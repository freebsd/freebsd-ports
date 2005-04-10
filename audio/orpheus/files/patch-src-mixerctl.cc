--- src/mixerctl.cc	Sat Feb 14 20:11:05 2004
+++ src/mixerctl.cc	Sun Dec 12 22:08:37 2004
@@ -50,7 +50,7 @@
 
     if((fd = ::open(devname.c_str(), O_RDWR)) != -1) {
 	if(ioctl(fd, SOUND_MIXER_READ_DEVMASK, &devmask) != -1) {
-	    for(ct = ctVolume; ct != channeltype_end; (int) ct += 1) {
+	    for(ct = ctVolume; ct != channeltype_end; ct = (mixerctl::channeltype) (ct + 1)) {
 		if((1 << (int) ct) & devmask) {
 		    channels.insert(ct);
 		}
