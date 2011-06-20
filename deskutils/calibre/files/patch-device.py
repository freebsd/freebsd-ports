--- src/calibre/devices/usbms/device.py.orig	2011-06-19 09:41:50.000000000 -0500
+++ src/calibre/devices/usbms/device.py	2011-06-19 08:20:32.000000000 -0500
@@ -17,7 +17,7 @@
 from calibre.devices.interface import DevicePlugin
 from calibre.devices.errors import DeviceError, FreeSpaceError
 from calibre.devices.usbms.deviceconfig import DeviceConfig
-from calibre.constants import iswindows, islinux, isosx, plugins
+from calibre.constants import iswindows, islinux, isosx, isfreebsd, plugins
 from calibre.utils.filenames import ascii_filename as sanitize, shorten_components_to
 
 if isosx:
@@ -698,7 +698,152 @@
             self._card_a_prefix = self._card_b_prefix
             self._card_b_prefix = None
 
-
+# ------------------------------------------------------
+#
+#  open for FreeBSD
+#	find the device node or nodes that match the S/N we already have from the scanner 
+#	and attempt to mount each one
+#		1.  get list of disk devices from sysctl
+#		2.  compare that list with the one from camcontrol
+#		3.  and see if it has a matching s/n
+#		6.  find any partitions/slices associated with each node
+#		7.  attempt to mount, using calibre-mount-helper, each one
+#		8.  when finished, we have a list of mount points and associated device nodes
+#
+    def open_freebsd(self):
+
+		# this gives us access to the S/N, etc. of the reader that the scanner has found
+		# and the match routines for some of that data, like s/n, vendor ID, etc.
+		d=self.detected_device	
+		
+		if not d.serial:
+			raise DeviceError("Device has no S/N.  Can't continue")
+			return False
+
+		devs={}
+		di=0
+		ndevs=4		# number of possible devices per reader (main, carda, cardb, launcher)
+
+		#get list of disk devices
+		p=subprocess.Popen(["sysctl", "kern.disks"], stdout=subprocess.PIPE)
+		kdsks=subprocess.Popen(["sed", "s/kern.disks: //"], stdin=p.stdout, stdout=subprocess.PIPE).communicate()[0]
+		p.stdout.close()
+		#print kdsks
+		for dvc in kdsks.split():
+			# for each one that's also in the list of cam devices ...
+			p=subprocess.Popen(["camcontrol", "devlist"], stdout=subprocess.PIPE)
+			devmatch=subprocess.Popen(["grep", dvc], stdin=p.stdout, stdout=subprocess.PIPE).communicate()[0]
+			p.stdout.close()
+			if devmatch:
+				#print "Checking ", devmatch
+				# ... see if we can get a S/N from the actual device node
+				sn=subprocess.Popen(["camcontrol", "inquiry", dvc, "-S"], stdout=subprocess.PIPE).communicate()[0]
+				sn=sn[0:-1]             # drop the trailing newline
+				#print "S/N = ", sn
+				if sn and d.match_serial(sn):
+					# we have a matching s/n, record this device node
+					#print "match found: ", dvc
+					devs[di]=dvc
+					di += 1
+
+		# sort the list of devices
+		for i in range(1,ndevs+1):
+			for j in reversed(range(1,i)):
+				if devs[j-1] > devs[j]:
+					x=devs[j-1]
+					devs[j-1]=devs[j]
+					devs[j]=x
+		#print devs
+
+		# now we need to see if any of these have slices/partitions
+		mtd=0
+		label="READER"		# could use something more unique, like S/N or productID...
+		cmd = '/usr/local/bin/calibre-mount-helper'
+		cmd = [cmd, 'mount']
+		for i in range(0,ndevs):
+			cmd2="ls /dev/"+devs[i]+"*"
+			p=subprocess.Popen(cmd2, shell=True, stdout=subprocess.PIPE)
+			devs[i]=subprocess.Popen(["cut", "-d", "/", "-f" "3"], stdin=p.stdout, stdout=subprocess.PIPE).communicate()[0]
+			p.stdout.close()
+	
+			# try all the nodes to see what we can mount
+			for dev in devs[i].split():
+				mp='/media/'+label+'-'+dev
+				#print "trying ", dev, "on", mp
+				try:
+					p = subprocess.Popen(cmd + ["/dev/"+dev, mp])
+				except OSError:
+					raise DeviceError(_('Could not find mount helper: %s.')%cmd[0])
+				while p.poll() is None:
+					time.sleep(0.1)
+			
+				if p.returncode == 0:
+					#print "  mounted", dev
+					if i == 0:
+						self._main_prefix = mp
+						self._main_dev = "/dev/"+dev
+						#print "main = ", self._main_dev, self._main_prefix
+					if i == 1:
+						self._card_a_prefix = mp
+						self._card_a_dev = "/dev/"+dev
+						#print "card a = ", self._card_a_dev, self._card_a_prefix
+					if i == 2:
+						self._card_b_prefix = mp
+						self._card_b_dev = "/dev/"+dev
+						#print "card b = ", self._card_b_dev, self._card_b_prefix
+						
+					mtd += 1
+					break
+
+		if mtd > 0:
+			return True
+		else :
+			return False
+#
+# ------------------------------------------------------
+#
+#	this one is pretty simple:
+#		just umount each of the previously
+#		mounted filesystems, using the mount helper
+#
+    def eject_freebsd(self):
+		cmd = '/usr/local/bin/calibre-mount-helper'
+		cmd = [cmd, 'eject']
+
+		if self._main_prefix:
+			#print "umount main:", cmd, self._main_dev, self._main_prefix
+			try:
+				p = subprocess.Popen(cmd + [self._main_dev, self._main_prefix])
+			except OSError:
+				raise DeviceError(
+				_('Could not find mount helper: %s.')%cmd[0])
+			while p.poll() is None:
+				time.sleep(0.1)
+
+		if self._card_a_prefix:
+			#print "umount card a:", cmd, self._card_a_dev, self._card_a_prefix
+			try:
+				p = subprocess.Popen(cmd + [self._card_a_dev,  self._card_a_prefix])
+			except OSError:
+				raise DeviceError(
+				_('Could not find mount helper: %s.')%cmd[0])
+			while p.poll() is None:
+				time.sleep(0.1)
+
+		if self._card_b_prefix:
+			#print "umount card b:", cmd, self._card_b_dev, self._card_b_prefix
+			try:
+				p = subprocess.Popen(cmd + [self._card_b_dev, self._card_b_prefix])
+			except OSError:
+				raise DeviceError(
+				_('Could not find mount helper: %s.')%cmd[0])
+			while p.poll() is None:
+				time.sleep(0.1)
+
+		self._main_prefix = None
+		self._card_a_prefix = None
+		self._card_b_prefix = None
+# ------------------------------------------------------
 
     def open(self, library_uuid):
         time.sleep(5)
@@ -709,6 +854,14 @@
             except DeviceError:
                 time.sleep(7)
                 self.open_linux()
+        if isfreebsd:
+            self._main_dev = self._card_a_dev = self._card_b_dev = None
+            try:
+                self.open_freebsd()
+            except DeviceError:
+                subprocess.Popen(["camcontrol", "rescan", "all"])
+                time.sleep(2)
+                self.open_freebsd()
         if iswindows:
             try:
                 self.open_windows()
@@ -797,6 +950,11 @@
                 self.eject_linux()
             except:
                 pass
+        if isfreebsd:
+            try:
+                self.eject_freebsd()
+            except:
+                pass
         if iswindows:
             try:
                 self.eject_windows()
