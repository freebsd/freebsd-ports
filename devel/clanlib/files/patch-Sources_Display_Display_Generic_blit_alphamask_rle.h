--- Sources/Display/Display/Generic/blit_alphamask_rle.h.orig	Mon Aug  2 10:47:18 2004
+++ Sources/Display/Display/Generic/blit_alphamask_rle.h	Mon Aug  2 10:49:31 2004
@@ -107,14 +107,14 @@
 		{
 			T a = alpha_data[x];
 			T destval = dst_data[x];
-			T r = lookup_r[(((destval&rmask)>>rstart)<<8)+a];	//(((destval&rmask)>>rstart)*a)>>8;
-			T g = lookup_g[(((destval&gmask)>>gstart)<<8)+a];	//(((destval&gmask)>>gstart)*a)>>8;
-			T b = lookup_b[(((destval&bmask)>>bstart)<<8)+a];	//(((destval&bmask)>>bstart)*a)>>8;
+			T r = this->lookup_r[(((destval&this->rmask)>>this->rstart)<<8)+a];	//(((destval&rmask)>>rstart)*a)>>8;
+			T g = this->lookup_g[(((destval&this->gmask)>>this->gstart)<<8)+a];	//(((destval&gmask)>>gstart)*a)>>8;
+			T b = this->lookup_b[(((destval&this->bmask)>>this->bstart)<<8)+a];	//(((destval&bmask)>>bstart)*a)>>8;
 
 			T amix = 
-				(r<<rstart) +
-				(g<<gstart) + 
-				(b<<bstart);
+				(r<<this->rstart) +
+				(g<<this->gstart) + 
+				(b<<this->bstart);
 
 			dst_data[x] = amix + *(src_data++);
 		}
@@ -151,13 +151,13 @@
 		{
 			T a = alpha_data[x];
 			T destval = dst_buf[x];
-			T r = lookup_r[(((destval&rmask)>>rstart)<<8)+a];
-			T g = lookup_g[(((destval&gmask)>>gstart)<<8)+a];
-			T b = lookup_b[(((destval&bmask)>>bstart)<<8)+a];
+			T r = this->lookup_r[(((destval&this->rmask)>>this->rstart)<<8)+a];
+			T g = this->lookup_g[(((destval&this->gmask)>>this->gstart)<<8)+a];
+			T b = this->lookup_b[(((destval&this->bmask)>>this->bstart)<<8)+a];
 			T amix = 
-				(r<<rstart) +
-				(g<<gstart) + 
-				(b<<bstart);
+				(r<<this->rstart) +
+				(g<<this->gstart) + 
+				(b<<this->bstart);
 			dst_buf[x] = amix + *(src_data++);
 		}
 		memcpy(dst_data, dst_buf, sizeof(T)*rep);
