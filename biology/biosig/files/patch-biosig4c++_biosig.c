--- biosig4c++/biosig.c.orig	2021-08-13 09:17:15 UTC
+++ biosig4c++/biosig.c
@@ -631,7 +631,7 @@ int ifsetpos(HDRTYPE* hdr, size_t *pos) {
 	// gnu linux on sparc needs this 
 	fpos_t p;
 	p.__pos = *pos;
-#elif __sparc__ || __APPLE__ || __MINGW32__ || ANDROID || __NetBSD__ || __CYGWIN__
+#elif __sparc__ || __APPLE__ || __MINGW32__ || ANDROID || __NetBSD__ || __CYGWIN__ || __FreeBSD__
 	fpos_t p = *pos;
 #else
 	fpos_t p;
@@ -652,7 +652,7 @@ int ifsetpos(HDRTYPE* hdr, size_t *pos) {
 #if __gnu_linux__
 	// gnu linux on sparc needs this 
 	*pos = p.__pos;
-#elif __sparc__ || __APPLE__ || __MINGW32__ || ANDROID || __NetBSD__ || __CYGWIN__
+#elif __sparc__ || __APPLE__ || __MINGW32__ || ANDROID || __NetBSD__ || __CYGWIN__ || __FreeBSD__
 	*pos = p;
 #else
 	*pos = p.__pos;
@@ -678,7 +678,7 @@ int ifgetpos(HDRTYPE* hdr, size_t *pos) {
 #if __gnu_linux__
 		// gnu linux on sparc needs this 
 		*pos = p.__pos;	// ugly hack but working
-#elif __sparc__ || __APPLE__ || __MINGW32__ || ANDROID || __NetBSD__ || __CYGWIN__
+#elif __sparc__ || __APPLE__ || __MINGW32__ || ANDROID || __NetBSD__ || __CYGWIN__ || __FreeBSD__
 		*pos = p;
 #else
 		*pos = p.__pos;	// ugly hack but working
@@ -1219,8 +1219,11 @@ HDRTYPE* constructHDR(const unsigned NS, const unsigne
 	hdr->data.size[0] = 0; 	// rows
 	hdr->data.size[1] = 0;  // columns
 	hdr->data.block = NULL;
-	hdr->T0    = t_time2gdf_time(time(NULL)-timezone); // localtime
-	hdr->tzmin = -timezone/60;      // convert from seconds west of UTC to minutes east;
+
+	time_t t=time(NULL);
+	struct tm *tt = localtime(&t);
+	hdr->tzmin    = tt->tm_gmtoff/60;
+	hdr->T0       = t_time2gdf_time(time(NULL)-tt->tm_gmtoff); // localtime
 
 	{
 	uint8_t Equipment[8] = "b4c_1.5 ";
