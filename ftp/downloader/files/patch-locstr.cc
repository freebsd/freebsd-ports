--- main/locstr.cc.orig	Wed May  1 02:32:33 2002
+++ main/locstr.cc	Wed May  1 02:50:38 2002
@@ -711,7 +711,7 @@
 			sscanf_int(tmpdata,&(date.tm_sec));
 		};
 	};
-	return(mktime(&date)+timezone);
+	return(mktime(&date)+date.tm_gmtoff);
 };
 
 /* check_mask();
