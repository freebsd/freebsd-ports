--- src/file.cpp.bak	2012-09-30 18:58:51.000000000 -0500
+++ src/file.cpp	2012-09-30 18:59:15.000000000 -0500
@@ -310,7 +310,7 @@
 				if(magic==0x088b1f) {
 					 // maybe gzip... 
 
-					void* gzfile = gzopen(fileToOpen.c_str(),"rb");
+					gzFile gzfile = gzopen(fileToOpen.c_str(),"rb");
 					if(gzfile) {
 						delete fp;
