--- src/calibre/devices/usbms/device.py.orig	2011-12-29 20:00:38.000000000 -0800
+++ src/calibre/devices/usbms/device.py	2012-01-01 14:09:00.000000000 -0800
@@ -697,19 +697,21 @@
             self._card_a_prefix = self._card_b_prefix
             self._card_b_prefix = None
 
+
 # ------------------------------------------------------
 #
 #  open for FreeBSD
-#   find the device node or nodes that match the S/N we already have from the scanner
-#   and attempt to mount each one
-#       1.  get list of disk devices from sysctl
-#       2.  compare that list with the one from camcontrol
-#       3.  and see if it has a matching s/n
-#       6.  find any partitions/slices associated with each node
-#       7.  attempt to mount, using calibre-mount-helper, each one
-#       8.  when finished, we have a list of mount points and associated device nodes
+#      find the device node or nodes that match the S/N we already have from the scanner
+#      and attempt to mount each one
+#              1.  get list of devices in /dev with matching s/n etc.
+#              2.  get list of volumes associated with each
+#              3.  attempt to mount each one using Hal
+#              4.  when finished, we have a list of mount points and associated dbus nodes
 #
     def open_freebsd(self):
+        import dbus
+        # There should be some way to access the -v arg...
+        verbose = False
 
         # this gives us access to the S/N, etc. of the reader that the scanner has found
         # and the match routines for some of that data, like s/n, vendor ID, etc.
@@ -718,129 +720,149 @@
         if not d.serial:
             raise DeviceError("Device has no S/N.  Can't continue")
             return False
-
-        devs={}
-        di=0
-        ndevs=4     # number of possible devices per reader (main, carda, cardb, launcher)
-
-        #get list of disk devices
-        p=subprocess.Popen(["sysctl", "kern.disks"], stdout=subprocess.PIPE)
-        kdsks=subprocess.Popen(["sed", "s/kern.disks: //"], stdin=p.stdout, stdout=subprocess.PIPE).communicate()[0]
-        p.stdout.close()
-        #print kdsks
-        for dvc in kdsks.split():
-            # for each one that's also in the list of cam devices ...
-            p=subprocess.Popen(["camcontrol", "devlist"], stdout=subprocess.PIPE)
-            devmatch=subprocess.Popen(["grep", dvc], stdin=p.stdout, stdout=subprocess.PIPE).communicate()[0]
-            p.stdout.close()
-            if devmatch:
-                #print "Checking ", devmatch
-                # ... see if we can get a S/N from the actual device node
-                sn=subprocess.Popen(["camcontrol", "inquiry", dvc, "-S"], stdout=subprocess.PIPE).communicate()[0]
-                sn=sn[0:-1]             # drop the trailing newline
-                #print "S/N = ", sn
-                if sn and d.match_serial(sn):
-                    # we have a matching s/n, record this device node
-                    #print "match found: ", dvc
-                    devs[di]=dvc
-                    di += 1
-
-        # sort the list of devices
-        for i in range(1,ndevs+1):
-            for j in reversed(range(1,i)):
-                if devs[j-1] > devs[j]:
-                    x=devs[j-1]
-                    devs[j-1]=devs[j]
-                    devs[j]=x
-        #print devs
-
-        # now we need to see if any of these have slices/partitions
+        
+        vols=[]
+        
+        bus = dbus.SystemBus()
+        manager = dbus.Interface(bus.get_object('org.freedesktop.Hal',
+                      '/org/freedesktop/Hal/Manager'), 'org.freedesktop.Hal.Manager')
+        paths = manager.FindDeviceStringMatch('usb.serial',d.serial)
+        for path in paths:
+            objif = dbus.Interface(bus.get_object('org.freedesktop.Hal', path), 'org.freedesktop.Hal.Device')
+            # Extra paranoia...
+            try:
+                if d.idVendor == objif.GetProperty('usb.vendor_id') and \
+                        d.idProduct == objif.GetProperty('usb.product_id') and \
+                        d.manufacturer == objif.GetProperty('usb.vendor') and \
+                        d.product == objif.GetProperty('usb.product') and \
+                        d.serial == objif.GetProperty('usb.serial'):
+                    dpaths = manager.FindDeviceStringMatch('storage.originating_device', path)
+                    for dpath in dpaths:
+                        devif = dbus.Interface(bus.get_object('org.freedesktop.Hal', dpath), 'org.freedesktop.Hal.Device')
+                        try:
+                            vpaths = manager.FindDeviceStringMatch('block.storage_device', dpath)
+                            for vpath in vpaths:
+                                try:
+                                    vdevif = dbus.Interface(bus.get_object('org.freedesktop.Hal', vpath), 'org.freedesktop.Hal.Device')
+                                    if not vdevif.GetProperty('block.is_volume'):
+                                        continue
+                                    if vdevif.GetProperty('volume.fsusage') != 'filesystem':
+                                        continue
+                                    volif = dbus.Interface(bus.get_object('org.freedesktop.Hal', vpath), 'org.freedesktop.Hal.Device.Volume')
+                                    pdevif = dbus.Interface(bus.get_object('org.freedesktop.Hal', vdevif.GetProperty('info.parent')), 'org.freedesktop.Hal.Device')
+                                    vol = {'node': pdevif.GetProperty('block.device'),
+                                            'dev': vdevif,
+                                            'vol': volif,
+                                            'label': vdevif.GetProperty('volume.label')}
+                                    vols.append(vol)
+                                except dbus.exceptions.DBusException, e:
+                                    print e
+                                    continue
+                        except dbus.exceptions.DBusException, e:
+                            print e
+                            continue
+            except dbus.exceptions.DBusException, e:
+                continue
+
+        def ocmp(x,y):
+            if x['node'] < y['node']:
+                return -1
+            if x['node'] > y['node']:
+                return 1
+            return 0
+
+        vols.sort(cmp=ocmp)
+
+        if verbose:
+            print "FBSD:	", vols
+        
         mtd=0
-        label="READER"      # could use something more unique, like S/N or productID...
-        cmd = '/usr/local/bin/calibre-mount-helper'
-        cmd = [cmd, 'mount']
-        for i in range(0,ndevs):
-            cmd2="ls /dev/"+devs[i]+"*"
-            p=subprocess.Popen(cmd2, shell=True, stdout=subprocess.PIPE)
-            devs[i]=subprocess.Popen(["cut", "-d", "/", "-f" "3"], stdin=p.stdout, stdout=subprocess.PIPE).communicate()[0]
-            p.stdout.close()
-
-            # try all the nodes to see what we can mount
-            for dev in devs[i].split():
-                mp='/media/'+label+'-'+dev
-                mmp = mp
-                if mmp.endswith('/'):
-                    mmp = mmp[:-1]
-                #print "trying ", dev, "on", mp
-                try:
-                    p = subprocess.Popen(cmd + ["/dev/"+dev, mmp])
-                except OSError:
-                    raise DeviceError(_('Could not find mount helper: %s.')%cmd[0])
-                while p.poll() is None:
-                    time.sleep(0.1)
-
-                if p.returncode == 0:
-                    #print "  mounted", dev
-                    if i == 0:
-                        self._main_prefix = mp
-                        self._main_dev = "/dev/"+dev
-                        #print "main = ", self._main_dev, self._main_prefix
-                    if i == 1:
-                        self._card_a_prefix = mp
-                        self._card_a_dev = "/dev/"+dev
-                        #print "card a = ", self._card_a_dev, self._card_a_prefix
-                    if i == 2:
-                        self._card_b_prefix = mp
-                        self._card_b_dev = "/dev/"+dev
-                        #print "card b = ", self._card_b_dev, self._card_b_prefix
 
-                    mtd += 1
-                    break
+        for vol in vols:
+            mp = ''
+            if vol['dev'].GetProperty('volume.is_mounted'):
+                mp = vol['dev'].GetProperty('volume.mount_point')
+            else:
+                if verbose:
+                    print "FBSD:	trying ", vol['label'], "on", 'Calibre-'+labels[i]
+                try:
+                    vol['vol'].Mount('Calibre-'+vol['label'],
+                            vol['dev'].GetProperty('volume.fstype'), [])
+                    loops = 0
+                    while not vol['dev'].GetProperty('volume.is_mounted'):
+                        time.sleep(1)
+                        loops += 1
+                        if loops > 100:
+                            print "ERROR: Timeout waiting for mount to complete"
+                            continue
+                    mp = vol['dev'].GetProperty('volume.mount_point')
+                except dbus.exceptions.DBusException, e:
+                    print "Failed to mount ", e
+                    continue
+
+            # Mount Point becomes Mount Path
+            mp += '/'
+
+            if verbose:
+                print "FBSD:	  mounted", vol['label'], "on", mp
+            if mtd == 0:
+                self._main_prefix = mp
+                self._main_vol = vol['vol']
+                if verbose:
+                    print "FBSD:	main = ", self._main_prefix
+            if mtd == 1:
+                self._card_a_prefix = mp
+                self._card_a_vol = vol['vol']
+                if verbose:
+                    print "FBSD:	card a = ", self._card_a_prefix
+            if mtd == 2:
+                self._card_b_prefix = mp
+                self._card_b_vol = vol['vol']
+                if verbose:
+                    print "FBSD:	card b = ", self._card_b_prefix
+                # Note that mtd is used as a bool... not incrementing is fine.
+                break
+            mtd += 1
 
         if mtd > 0:
             return True
-        else :
-            return False
+        raise DeviceError(_('Unable to mount the device'))
+
 #
 # ------------------------------------------------------
 #
-#   this one is pretty simple:
-#       just umount each of the previously
-#       mounted filesystems, using the mount helper
+#    this one is pretty simple:
+#        just umount each of the previously
+#        mounted filesystems, using the stored volume object
 #
     def eject_freebsd(self):
-        cmd = '/usr/local/bin/calibre-mount-helper'
-        cmd = [cmd, 'eject']
+        import dbus
+        # There should be some way to access the -v arg...
+        verbose = False
 
         if self._main_prefix:
-            #print "umount main:", cmd, self._main_dev, self._main_prefix
+            if verbose:
+                print "FBSD:	umount main:", self._main_prefix
             try:
-                p = subprocess.Popen(cmd + [self._main_dev, self._main_prefix])
-            except OSError:
-                raise DeviceError(
-                _('Could not find mount helper: %s.')%cmd[0])
-            while p.poll() is None:
-                time.sleep(0.1)
+                self._main_vol.Unmount([])
+            except dbus.exceptions.DBusException, e:
+                print 'Unable to eject ', e
 
         if self._card_a_prefix:
-            #print "umount card a:", cmd, self._card_a_dev, self._card_a_prefix
+            if verbose:
+                print "FBSD:	umount card a:", self._card_a_prefix
             try:
-                p = subprocess.Popen(cmd + [self._card_a_dev,  self._card_a_prefix])
-            except OSError:
-                raise DeviceError(
-                _('Could not find mount helper: %s.')%cmd[0])
-            while p.poll() is None:
-                time.sleep(0.1)
+                self._card_a_vol.Unmount([])
+            except dbus.exceptions.DBusException, e:
+                print 'Unable to eject ', e
 
         if self._card_b_prefix:
-            #print "umount card b:", cmd, self._card_b_dev, self._card_b_prefix
+            if verbose:
+                print "FBSD:	umount card b:", self._card_b_prefix
             try:
-                p = subprocess.Popen(cmd + [self._card_b_dev, self._card_b_prefix])
-            except OSError:
-                raise DeviceError(
-                _('Could not find mount helper: %s.')%cmd[0])
-            while p.poll() is None:
-                time.sleep(0.1)
+                self._card_b_vol.Unmount([])
+            except dbus.exceptions.DBusException, e:
+                print 'Unable to eject ', e
 
         self._main_prefix = None
         self._card_a_prefix = None
@@ -859,11 +881,10 @@
                     time.sleep(7)
                     self.open_linux()
             if isfreebsd:
-                self._main_dev = self._card_a_dev = self._card_b_dev = None
+                self._main_vol = self._card_a_vol = self._card_b_vol = None
                 try:
                     self.open_freebsd()
                 except DeviceError:
-                    subprocess.Popen(["camcontrol", "rescan", "all"])
                     time.sleep(2)
                     self.open_freebsd()
             if iswindows:
