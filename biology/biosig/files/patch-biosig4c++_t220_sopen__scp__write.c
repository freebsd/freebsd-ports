--- biosig4c++/t220/sopen_scp_write.c.orig	2021-08-13 09:17:15 UTC
+++ biosig4c++/t220/sopen_scp_write.c
@@ -388,10 +388,8 @@ int sopen_SCP_write(HDRTYPE* hdr) {
 			if (VERBOSE_LEVEL>7) fprintf(stdout,"Section 1 Tag 25 \n");
 
 			gdf_time T1 = hdr->T0;
-#ifndef __APPLE__
-			T1 += (int32_t)ldexp(timezone/86400.0,32);			
-#endif 
-			T0_tm = gdf_time2tm_time(T1);
+			T0_tm = gdf_time2tm_time(hdr->T0);
+			T0_tm->tm_gmtoff = hdr->tzmin*60;
 
 			*(ptr+sectionStart+curSectLen) = 25;	// tag
 			leu16a(4, ptr+sectionStart+curSectLen+1);	// length
@@ -719,10 +717,8 @@ int sopen_SCP_write(HDRTYPE* hdr) {
 
 			// Recording Date and Time
 			gdf_time T1 = hdr->T0;
-#ifndef __APPLE__
-			T1 += (int32_t)ldexp(timezone/86400.0,32);
-#endif
-			T0_tm = gdf_time2tm_time(T1);
+			T0_tm = gdf_time2tm_time(hdr->T0);
+			T0_tm->tm_gmtoff = hdr->tzmin*60;
 
 			leu16a(T0_tm->tm_year+1900, PtrCurSect+10);     // year
 			PtrCurSect[12] = (uint8_t)(T0_tm->tm_mon + 1);  // month
