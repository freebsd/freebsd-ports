--- Makefile.inc.old	Thu Jan 25 10:03:41 2007
+++ Makefile.inc	Thu Jan 25 10:05:55 2007
@@ -1,5 +1,3 @@
-CXX=g++
-
 #You can set the on what OS is compiling (Linux/Windows)
 OS_PORT=LINUX
 #OS_PORT=WINDOWS
@@ -18,9 +16,9 @@
 
 # L I N U X   C O N F I G U R A T I O N
 #Next line sets the midi input. It can be "ALSA", "OSS" or "NONE".
-LINUX_MIDIIN=ALSA
+#LINUX_MIDIIN=ALSA
 #LINUX_MIDIIN=OSS
-#LINUX_MIDIIN=NONE
+LINUX_MIDIIN=NONE
 
 #Next lines sets the audio output (OSS/JACK/PA)
 #You may use only one at the time
