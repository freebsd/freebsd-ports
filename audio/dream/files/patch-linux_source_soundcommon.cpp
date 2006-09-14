--- linux/source/soundcommon.cpp.orig	Wed Sep 13 11:06:20 2006
+++ linux/source/soundcommon.cpp	Wed Sep 13 11:25:45 2006
@@ -154,9 +154,10 @@
 	vector<string> tmp;
 	names.clear();
 	devices.clear();
+/*
 	ifstream sndstat("/dev/sndstat");
 	if(!sndstat.is_open())
-		sndstat.open("/proc/asound/oss/sndstat");
+		sndstat.open("/dev/sndstat");
 	if(sndstat.is_open())
 	{
 		while(!sndstat.eof())
@@ -176,6 +177,8 @@
 		}
 		sndstat.close();
 	}
+*/
+	tmp.push_back("0");
 	/* if there is more than one device, let the user chose */
 	if(tmp.size()>1)
 	{
