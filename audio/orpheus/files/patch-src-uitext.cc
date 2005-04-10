--- src/uitext.cc	Tue Feb 17 04:18:21 2004
+++ src/uitext.cc	Sun Dec 12 22:12:41 2004
@@ -577,14 +577,16 @@
 			autosavepl = !autosavepl;
 			break;
 		    case 41:
-			if(++((int) playmode) == PlayMode_size)
+			playmode = (PlayMode) (playmode + 1);
+			if(playmode == PlayMode_size)
 			    playmode = Normal;
 			break;
 		    case 42:
 			autoplay = !autoplay;
 			break;
 		    case 43:
-			if(++((int) sortorder) == SortOrder_size)
+			sortorder = (SortOrder) (sortorder + 1);
+			if(sortorder == SortOrder_size)
 			    sortorder = byFileName;
 			break;
 		    case 44:
@@ -719,7 +721,8 @@
     while(!finished) {
 	m.clear();
 
-	for(ct = mixerctl::ctVolume; ct != mixerctl::channeltype_end; (int) ct += 1) {
+	for(ct = mixerctl::ctVolume; ct != mixerctl::channeltype_end; ct = (mixerctl::channeltype) (ct + 1))
+	{
 	    if(chavail.count(ct)) {
 		val = mix.readlevel(ct);
 		if(val >= 0) {
