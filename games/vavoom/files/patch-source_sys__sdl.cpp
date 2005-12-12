--- source/sys_sdl.cpp.orig	Mon Dec 12 14:39:33 2005
+++ source/sys_sdl.cpp	Mon Dec 12 14:39:52 2005
@@ -380,7 +380,7 @@
 			char *out = buf;
 			size_t inbytes = 1;
 			size_t outbytes = 8;
-			iconv(cd, &in, &inbytes, &out, &outbytes);
+			iconv(cd, (const char**)&in, &inbytes, &out, &outbytes);
 			fwrite(buf, 1, out - buf, stdout);
 		}
 
