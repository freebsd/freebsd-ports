--- wmSpaceWeather.c.orig	Thu Feb 18 17:57:45 1999
+++ wmSpaceWeather.c	Tue Apr 13 20:06:41 2004
@@ -115,7 +115,7 @@ XEvent		event;
 int			i, n, s, k, m, dt1, dt2;
 int 		Year, Month, Day, DayOfMonth, OldDayOfMonth;
 int			Hours, Mins, Secs, OldSecs, xoff, D[10], xsize;
-long		CurrentLocalTime;
+time_t		CurrentLocalTime;
 int			height, UpToDate, LEDOn;
 double		UT, TU, TU2, TU3, T0, gmst, hour24();
 
@@ -126,6 +126,7 @@ int 		Kp[8] = { -1, -1, -1, -1, -1, -1, 
 double		E1, E2, P1, P2, P3;
 char		Xray[10], digit[2];
 FILE		*fp;
+char		FileName[1024];
 
 
 
@@ -249,13 +250,13 @@ FILE		*fp;
 
 
 	/*
-	 *  Check the Kp file every (approx.) 2 seconds.
+	 *  Check the Kp file every (approx.) 60 seconds.
 	 *  Can significantly reduce this frequency later. But its
 	 *  easier to debug this way...
 	 *  Do this before trying to download again! The file may be there and it
 	 *  may be Up-To-Date!
 	 */
-	if (dt2 > 2){
+	if (dt2 > 60){
 	    
 	    dt2 = 0;
 
@@ -272,13 +273,13 @@ FILE		*fp;
 	    Secs  = Time->tm_sec;
 	    UT = (double)Hours + (double)Mins/60.0 + (double)Secs/3600.0;
 	    CurrentJD = jd(Year, Month, Day, UT);
-	    
 
 
     	    /*
     	     *  Read in Kp values
     	     */
-    	    if ((fp = fopen("/tmp/LatestKp.txt", "r")) != NULL){
+	    snprintf(FileName, sizeof(FileName), "/tmp/LatestKp.txt", getenv("HOME"));
+	    if ((fp = fopen(FileName, "r")) != NULL){
 
     	        for (i=0; i<8; ++i){
 	    	    fscanf(fp, "%ld %d", &TimeTag[i], &Kp[i]);
@@ -289,7 +290,7 @@ FILE		*fp;
 	    	fscanf(fp, "%lf", &P3);
 	    	fscanf(fp, "%lf", &E1);
 	    	fscanf(fp, "%lf", &E2);
-	    	fscanf(fp, "%10s",  Xray);
+	    	fscanf(fp, "%9s",  Xray);
     	        fclose(fp);
 
 	    } else {
@@ -318,7 +319,7 @@ FILE		*fp;
 	    LatestAvailJD = jd(Year, Month, Day, UT);
 
 	    DeltaT = (CurrentJD - LatestAvailJD)*24.0;
-	    UpToDate = (DeltaT <= 3.0) ? 1 : 0;
+	    UpToDate = (DeltaT <= 4.0) ? 1 : 0;
 
 	    if (!UpToDate){
 
@@ -560,7 +561,7 @@ void ParseCMDLine(int argc, char *argv[]
 
         } else if ((!strcmp(argv[i], "-url"))||(!strcmp(argv[i], "-u"))){
 
-            strcpy(URL, argv[++i]);
+            strlcpy(URL, argv[++i], sizeof(URL));
 
         } else {
 
@@ -651,7 +652,7 @@ void pressEvent(XButtonEvent *xev){
     if (GotDoubleClick1) {
         GotFirstClick1 = 0;
         GotDoubleClick1 = 0;
-        sprintf(Command, "netscape -remote 'openURL(%s)' || netscape '%s' &", URL, URL);
+        snprintf(Command, sizeof(Command), "netscape -remote 'openURL(%s)' || netscape '%s' &", URL, URL);
         system(Command);
     }
 
