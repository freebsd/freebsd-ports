--- lib/video/renderer.cpp.orig	Sat Jan 19 18:52:21 2002
+++ lib/video/renderer.cpp	Sat Jan 19 18:53:21 2002
@@ -1166,7 +1166,7 @@
 		    cout<<"iconv open error"<<endl;
 		}
 		else {
-		    sts = iconv(icvsts, (char **)&sub,&in_size,
+		    sts = iconv(icvsts, (const char **)&sub,&in_size,
 					(char **)&out_p,&out_size);
 		    if (sts == (uint_t)(-1)) {
 			cout <<"iconv convert error"<<endl;
@@ -1214,7 +1214,7 @@
 		        cout<<"iconv open error"<<endl;
 		    }
 		    else {
-		        sts = iconv(icvsts, (char **)&sub,&in_size,
+		        sts = iconv(icvsts, (const char **)&sub,&in_size,
 					(char **)&out_p,&out_size);
 		        if (sts == (uint_t)(-1)) {
 			    cout <<"iconv convert error"<<endl;
