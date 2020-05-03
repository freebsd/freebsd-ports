--- raphodo/storage.py.orig	2020-04-17 01:22:23 UTC
+++ raphodo/storage.py
@@ -68,10 +68,9 @@ import xdg
 import gi
 
 gi.require_version('GUdev', '1.0')
-gi.require_version('UDisks', '2.0')
 gi.require_version('GExiv2', '0.10')
 gi.require_version('GLib', '2.0')
-from gi.repository import GUdev, UDisks, GLib
+from gi.repository import GUdev, GLib
 
 
 
@@ -170,7 +169,7 @@ def get_media_dir() -> str:
 
     """
 
-    if sys.platform.startswith('linux'):
+    if sys.platform.startswith('linux') or sys.platform.startswith('freebsd'):
         media_dir = '/media/{}'.format(get_user_name())
         run_media_dir = '/run/media'
         distro = get_distro()
@@ -278,7 +277,7 @@ class ValidMounts():
         self.validMountFolders, e.g. /media/<USER>, etc.
         """
 
-        if not sys.platform.startswith('linux'):
+        if not sys.platform.startswith('linux') and not sys.platform.startswith('freebsd'):
             raise ("Mounts.setValidMountPoints() not implemented on %s", sys.platform())
         else:
             try:
@@ -649,7 +648,7 @@ def get_default_file_manager() -> Tuple[Optional[str],
 
     _default_file_manager_probed = True
 
-    assert sys.platform.startswith('linux')
+    assert sys.platform.startswith('linux') or sys.platform.startswith('freebsd')
     cmd = shlex.split('xdg-mime query default inode/directory')
     try:
         desktop_file = subprocess.check_output(cmd, universal_newlines=True)  # type: str
@@ -794,7 +793,7 @@ def validate_download_folder(path: Optional[str],
 
     :param path: path to analyze
     :param write_on_waccesss_failure: if os.access reports path is not writable, test
-     nonetheless to see if it's writable by writing and deleting a test file 
+     nonetheless to see if it's writable by writing and deleting a test file
     :return: Tuple indicating validity and path made absolute
 
     >>> validate_download_folder('/some/bogus/and/ridiculous/path')
@@ -1041,259 +1040,6 @@ class CameraHotplug(QObject):
                 self.cameraRemoved.emit()
 
 
-class UDisks2Monitor(QObject):
-    # Most of this class is Copyright 2008-2015 Canonical
-
-    partitionMounted = pyqtSignal(str, list, bool)
-    partitionUnmounted = pyqtSignal(str)
-
-    loop_prefix = '/org/freedesktop/UDisks2/block_devices/loop'
-    not_interesting = (
-        '/org/freedesktop/UDisks2/block_devices/dm_',
-        '/org/freedesktop/UDisks2/block_devices/ram',
-        '/org/freedesktop/UDisks2/block_devices/zram',
-    )
-
-    def __init__(self, validMounts: ValidMounts) -> None:
-        super().__init__()
-        self.validMounts = validMounts
-
-    @pyqtSlot()
-    def startMonitor(self) -> None:
-        self.udisks = UDisks.Client.new_sync(None)
-        self.manager = self.udisks.get_object_manager()
-        self.manager.connect('object-added',
-                             lambda man, obj: self._udisks_obj_added(obj))
-        self.manager.connect('object-removed',
-                             lambda man, obj: self._device_removed(obj))
-
-        # Track the paths of the mount points, which is useful when unmounting
-        # objects.
-        self.known_mounts = {}  # type: Dict[str, str]
-        for obj in self.manager.get_objects():
-            path = obj.get_object_path()
-            fs = obj.get_filesystem()
-            if fs:
-                mount_points = fs.get_cached_property('MountPoints').get_bytestring_array()
-                if mount_points:
-                    self.known_mounts[path] = mount_points[0]
-        logging.debug("... UDisks2 monitor started")
-
-    def _udisks_obj_added(self, obj) -> None:
-        path = obj.get_object_path()
-        for boring in self.not_interesting:
-            if path.startswith(boring):
-                return
-        block = obj.get_block()
-        if not block:
-            return
-
-        drive = self._get_drive(block)
-
-        part = obj.get_partition()
-        is_system = block.get_cached_property('HintSystem').get_boolean()
-        is_loop = path.startswith(self.loop_prefix) and not \
-            block.get_cached_property('ReadOnly').get_boolean()
-        if not is_system or is_loop:
-            if part:
-                self._udisks_partition_added(obj, block, drive, path)
-
-    def _get_drive(self, block) -> Optional[UDisks.Drive]:
-        drive_name = block.get_cached_property('Drive').get_string()
-        if drive_name != '/':
-            return self.udisks.get_object(drive_name).get_drive()
-        else:
-            return None
-
-    def _udisks_partition_added(self, obj, block, drive, path) -> None:
-        logging.debug('UDisks: partition added: %s' % path)
-        fstype = block.get_cached_property('IdType').get_string()
-        logging.debug('Udisks: id-type: %s' % fstype)
-
-        fs = obj.get_filesystem()
-
-        if fs:
-            icon_names = self.get_icon_names(obj)
-
-            if drive is not None:
-                ejectable = drive.get_property('ejectable')
-            else:
-                ejectable = False
-            mount_point = ''
-            mount_points = fs.get_cached_property('MountPoints').get_bytestring_array()
-            if len(mount_points) == 0:
-                try:
-                    logging.debug("UDisks: attempting to mount %s", path)
-                    mount_point = self.retry_mount(fs, fstype)
-                    if not mount_point:
-                        raise Exception
-                    else:
-                        logging.debug("UDisks: successfully mounted at %s", mount_point)
-                except Exception:
-                    logging.error('UDisks: could not mount the device: %s', path)
-                    return
-            else:
-                mount_point = mount_points[0]
-                logging.debug("UDisks: already mounted at %s", mount_point)
-
-            self.known_mounts[path] = mount_point
-            if self.validMounts.pathIsValidMountPoint(mount_point):
-                self.partitionMounted.emit(mount_point, icon_names, ejectable)
-
-        else:
-            logging.debug("Udisks: partition has no file system %s", path)
-
-    def retry_mount(self, fs, fstype) -> str:
-        # Variant parameter construction Copyright Bernard Baeyens, and is
-        # licensed under GNU General Public License Version 2 or higher.
-        # https://github.com/berbae/udisksvm
-        list_options = ''
-        if fstype == 'vfat':
-            list_options = 'flush'
-        elif fstype == 'ext2':
-            list_options = 'sync'
-        G_VARIANT_TYPE_VARDICT = GLib.VariantType.new('a{sv}')
-        param_builder = GLib.VariantBuilder.new(G_VARIANT_TYPE_VARDICT)
-        optname = GLib.Variant.new_string('fstype')  # s
-        value = GLib.Variant.new_string(fstype)
-        vvalue = GLib.Variant.new_variant(value)  # v
-        newsv = GLib.Variant.new_dict_entry(optname, vvalue)  # {sv}
-        param_builder.add_value(newsv)
-        optname = GLib.Variant.new_string('options')
-        value = GLib.Variant.new_string(list_options)
-        vvalue = GLib.Variant.new_variant(value)
-        newsv = GLib.Variant.new_dict_entry(optname, vvalue)
-        param_builder.add_value(newsv)
-        vparam = param_builder.end()  # a{sv}
-
-        # Try to mount until it does not fail with "Busy"
-        timeout = 10
-        while timeout >= 0:
-            try:
-                return fs.call_mount_sync(vparam, None)
-            except GLib.GError as e:
-                if not 'UDisks2.Error.DeviceBusy' in e.message:
-                    raise
-                logging.debug('Udisks: Device busy.')
-                time.sleep(0.3)
-                timeout -= 1
-        return ''
-
-    def get_icon_names(self, obj: UDisks.Object) -> List[str]:
-        # Get icon information, if possible
-        icon_names = []
-        if have_gio:
-            info = self.udisks.get_object_info(obj)
-            icon = info.get_icon()
-            if isinstance(icon, Gio.ThemedIcon):
-                icon_names = icon.get_names()
-        return icon_names
-
-    # Next four class member functions from Damon Lynch, not Canonical
-    def _device_removed(self, obj: UDisks.Object) -> None:
-        # path here refers to the udev / udisks path, not the mount point
-        path = obj.get_object_path()
-        if path in self.known_mounts:
-            mount_point = self.known_mounts[path]
-            del self.known_mounts[path]
-            self.partitionUnmounted.emit(mount_point)
-
-    def get_can_eject(self, obj: UDisks.Object) -> bool:
-        block = obj.get_block()
-        drive = self._get_drive(block)
-        if drive is not None:
-            return drive.get_property('ejectable')
-        return False
-
-    def get_device_props(self, device_path: str) -> Tuple[List[str], bool]:
-        """
-        Given a device, get the icon names suggested by udev, and
-        determine whether the mount is ejectable or not.
-        :param device_path: system path of the device to check,
-        e.g. /dev/sdc1
-        :return: icon names and eject boolean
-        """
-
-        object_path = '/org/freedesktop/UDisks2/block_devices/{}'.format(
-            os.path.split(device_path)[1])
-        obj = self.udisks.get_object(object_path)
-        icon_names = self.get_icon_names(obj)
-        can_eject = self.get_can_eject(obj)
-        return (icon_names, can_eject)
-
-    @pyqtSlot(str)
-    def unmount_volume(self, mount_point: str) -> None:
-
-        G_VARIANT_TYPE_VARDICT = GLib.VariantType.new('a{sv}')
-        param_builder = GLib.VariantBuilder.new(G_VARIANT_TYPE_VARDICT)
-
-        # Variant parameter construction Copyright Bernard Baeyens, and is
-        # licensed under GNU General Public License Version 2 or higher.
-        # https://github.com/berbae/udisksvm
-
-        optname = GLib.Variant.new_string('force')
-        value = GLib.Variant.new_boolean(False)
-        vvalue = GLib.Variant.new_variant(value)
-        newsv = GLib.Variant.new_dict_entry(optname, vvalue)
-        param_builder.add_value(newsv)
-
-        vparam = param_builder.end()                            # a{sv}
-
-        path = None
-        # Get the path from the dict we keep of known mounts
-        for key, value in self.known_mounts.items():
-            if value == mount_point:
-                path = key
-                break
-        if path is None:
-            logging.error("Could not find UDisks2 path used to be able to unmount %s", mount_point)
-
-        fs = None
-        for obj in self.manager.get_objects():
-            opath = obj.get_object_path()
-            if path == opath:
-                fs = obj.get_filesystem()
-        if fs is None:
-            logging.error("Could not find UDisks2 filesystem used to be able to unmount %s",
-                          mount_point)
-
-        logging.debug("Unmounting %s...", mount_point)
-        try:
-            fs.call_unmount(vparam, None, self.umount_volume_callback, (mount_point, fs))
-        except GLib.GError:
-            value = sys.exc_info()[1]
-            logging.error('Unmounting failed with error:')
-            logging.error("%s", value)
-
-    def umount_volume_callback(self, source_object:  UDisks.FilesystemProxy,
-                               result: Gio.AsyncResult,
-                               user_data: Tuple[str, UDisks.Filesystem]) -> None:
-        """
-        Callback for asynchronous unmount operation.
-
-        :param source_object: the FilesystemProxy object
-        :param result: result of the unmount
-        :param user_data: mount_point and the file system
-        """
-
-        mount_point, fs = user_data
-
-        try:
-            if fs.call_unmount_finish(result):
-                logging.debug("...successfully unmounted %s", mount_point)
-            else:
-                # this is the result even when the unmount was unsuccessful
-                logging.debug("...possibly failed to unmount %s", mount_point)
-        except GLib.GError as e:
-            logging.error('Exception occurred unmounting %s', mount_point)
-            logging.exception('Traceback:')
-        except:
-            logging.error('Exception occurred unmounting %s', mount_point)
-            logging.exception('Traceback:')
-
-        self.partitionUnmounted.emit(mount_point)
-
-
 if have_gio:
     class GVolumeMonitor(QObject):
         r"""
@@ -1692,7 +1438,7 @@ def get_mount_size(mount: QStorageInfo) -> Tuple[int, 
     """
     Uses GIO to get bytes total and bytes free (available) for the mount that a
     path is in.
-    
+
     :param path: path located anywhere in the mount
     :return: bytes_total, bytes_free
     """
