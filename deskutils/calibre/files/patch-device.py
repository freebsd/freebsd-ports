--- src/calibre/devices/usbms/device.py.orig	2011-07-08 12:29:30.000000000 -0500
+++ src/calibre/devices/usbms/device.py	2011-07-12 20:02:45.000000000 -0500
@@ -704,14 +704,12 @@
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
+#              1.  get list of da devices in /dev
+#              2.  find the ones with matching s/n
+#              3.  attempt to mount each one using calibre-mount-helper
+#              4.  when finished, we have a list of mount points and associated device nodes
 #
     def open_freebsd(self):
 
@@ -722,81 +720,68 @@
         if not d.serial:
             raise DeviceError("Device has no S/N.  Can't continue")
             return False
-
+        
         devs={}
         di=0
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
+        
+        # delay for user to set device if necessary
+        time.sleep(5)
 
+        # get list of disk devices and
+        # see if we can get a S/N from the actual device node
+        #dsks=['/dev/da1', '/dev/da3s1']
+        dsks=glob.glob('/dev/da*')
+        dsks.sort()
+        for ndvc in dsks:
+            dvc = ndvc.replace('/dev/', '')
+            print "FBSD:	Checking ", dvc
+            #sn="08004610011F550C"
+            try:
+                sn=subprocess.Popen("/sbin/camcontrol inquiry "+dvc+" -S", shell=True, stdout=subprocess.PIPE).communicate()[0]
+            except:
+                print "FBSD:	inquiry failed:"
+            sn=sn[0:-1]             # drop the trailing newline
+            print "FBSD:	S/N = ", sn
+            if sn and d.match_serial(sn):
+                # we have a matching s/n, record this device node
+                print "FBSD:	match found: ", dvc
+                devs[di]=dvc
+                di += 1
+        
+        print "FBSD:	", devs
+        
         # now we need to see if any of these have slices/partitions
         mtd=0
-        label="READER"      # could use something more unique, like S/N or productID...
+        label="READER"          # could use something more unique, like S/N or productID...
         cmd = '/usr/local/bin/calibre-mount-helper'
-        cmd = [cmd, 'mount']
-        for i in range(0,ndevs):
-            cmd2="ls /dev/"+devs[i]+"*"
-            p=subprocess.Popen(cmd2, shell=True, stdout=subprocess.PIPE)
-            devs[i]=subprocess.Popen(["cut", "-d", "/", "-f" "3"], stdin=p.stdout, stdout=subprocess.PIPE).communicate()[0]
-            p.stdout.close()
-
+        for i in range(0,di):
             # try all the nodes to see what we can mount
             for dev in devs[i].split():
-                mp='/media/'+label+'-'+dev
-                #print "trying ", dev, "on", mp
+                mp='/mnt/'+label+'-'+dev+'/'
+                print "FBSD:	trying ", dev, "on", mp
                 try:
-                    p = subprocess.Popen(cmd + ["/dev/"+dev, mp])
-                except OSError:
-                    raise DeviceError(_('Could not find mount helper: %s.')%cmd[0])
+                    p = subprocess.Popen([cmd, "mount", "/dev/"+dev, mp])
+                except:
+                    print "FBSD:	mount failed:"
                 while p.poll() is None:
                     time.sleep(0.1)
-
+    
                 if p.returncode == 0:
-                    #print "  mounted", dev
-                    if i == 0:
+                    print "FBSD:	  mounted", dev, "on", mp
+                    if mtd == 0:
                         self._main_prefix = mp
                         self._main_dev = "/dev/"+dev
-                        #print "main = ", self._main_dev, self._main_prefix
-                    if i == 1:
+                        print "FBSD:	main = ", self._main_dev, self._main_prefix
+                    if mtd == 1:
                         self._card_a_prefix = mp
                         self._card_a_dev = "/dev/"+dev
-                        #print "card a = ", self._card_a_dev, self._card_a_prefix
-                    if i == 2:
+                        print "FBSD:	card a = ", self._card_a_dev, self._card_a_prefix
+                    if mtd == 2:
                         self._card_b_prefix = mp
                         self._card_b_dev = "/dev/"+dev
-                        #print "card b = ", self._card_b_dev, self._card_b_prefix
-
+                        print "FBSD:	card b = ", self._card_b_dev, self._card_b_prefix
+                        break
                     mtd += 1
-                    break
 
         if mtd > 0:
             return True
@@ -805,16 +790,16 @@
 #
 # ------------------------------------------------------
 #
-#   this one is pretty simple:
-#       just umount each of the previously
-#       mounted filesystems, using the mount helper
+#    this one is pretty simple:
+#        just umount each of the previously
+#        mounted filesystems, using the mount helper
 #
     def eject_freebsd(self):
         cmd = '/usr/local/bin/calibre-mount-helper'
         cmd = [cmd, 'eject']
 
         if self._main_prefix:
-            #print "umount main:", cmd, self._main_dev, self._main_prefix
+            print "FBSD:	umount main:", cmd, self._main_dev, self._main_prefix
             try:
                 p = subprocess.Popen(cmd + [self._main_dev, self._main_prefix])
             except OSError:
@@ -824,7 +809,7 @@
                 time.sleep(0.1)
 
         if self._card_a_prefix:
-            #print "umount card a:", cmd, self._card_a_dev, self._card_a_prefix
+            print "FBSD:	umount card a:", cmd, self._card_a_dev, self._card_a_prefix
             try:
                 p = subprocess.Popen(cmd + [self._card_a_dev,  self._card_a_prefix])
             except OSError:
@@ -834,7 +819,7 @@
                 time.sleep(0.1)
 
         if self._card_b_prefix:
-            #print "umount card b:", cmd, self._card_b_dev, self._card_b_prefix
+            print "FBSD:	umount card b:", cmd, self._card_b_dev, self._card_b_prefix
             try:
                 p = subprocess.Popen(cmd + [self._card_b_dev, self._card_b_prefix])
             except OSError:
