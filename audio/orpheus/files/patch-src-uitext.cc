diff -Nru src.orig/uitext.cc src/uitext.cc
--- src.orig/uitext.cc	Tue Feb 17 04:18:21 2004
+++ src/uitext.cc	Tue Apr 26 19:49:01 2005
@@ -125,6 +125,8 @@
 }
 
 void OrpheusTextUI::nexttrack() {
+    if (!plist.empty())
+    {
     if(conf.getplaymode() == Random) {
 	int k;
 	while(*(plist.begin()+(k = randlimit(0, plist.size()-1))) == currenttrack);
@@ -143,6 +145,7 @@
 	    }
 	}
     }
+    }
 }
 
 void OrpheusTextUI::prevtrack() {
@@ -577,14 +580,16 @@
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
@@ -719,7 +724,8 @@
     while(!finished) {
 	m.clear();
 
-	for(ct = mixerctl::ctVolume; ct != mixerctl::channeltype_end; (int) ct += 1) {
+	for(ct = mixerctl::ctVolume; ct != mixerctl::channeltype_end; ct = (mixerctl::channeltype) (ct + 1))
+	{
 	    if(chavail.count(ct)) {
 		val = mix.readlevel(ct);
 		if(val >= 0) {
