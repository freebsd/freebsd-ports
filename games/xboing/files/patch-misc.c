--- misc.c.orig	1996-11-22 01:28:46 UTC
+++ misc.c
@@ -89,8 +89,8 @@ void usleep(usec)
 #ifdef SYSV
 #ifdef __clipper__
     struct timeval tv;
-    tv.tv_sec=((usec)/1000);
-    tv.tv_usec=(((usec)%1000)*1000);
+    tv.tv_sec=((usec)/1000000);
+    tv.tv_usec=((usec)%1000000);
     select(1,NULL,NULL,NULL,&tv);
 #else
     poll((struct poll *) 0, (size_t) 0, usec / 1000);   /* ms resolution */
@@ -105,6 +105,68 @@ void usleep(usec)
 #endif
 
 #if NeedFunctionPrototypes
+static	int	kudelay(unsigned long count)
+#else
+static	int	kudelay(count)
+unsigned long count;
+#endif
+{
+    unsigned int	bluff = 1;
+
+    while( count-- != 0 )	/* this can hardly be "optimised out" */
+	bluff = (bluff ^ ((bluff & 1) * 0x6110)) >> 1;
+
+    return( bluff );
+}
+
+#if NeedFunctionPrototypes
+static	void kusleep(unsigned long usec)
+#else
+static	void kusleep(usec)
+        unsigned long usec;
+#endif
+{
+    static float	kuliber_time = 0.0;
+    static float	kuliber_count = 0.0;
+    static unsigned long	kutimerswap = (1000000 / 15);
+    struct timeval	st, et;
+    long		gap;
+    unsigned long	count;
+
+    if( kuliber_time == 0.0 )
+    {
+	count = 0x1000;		/* calibrate delay loop */
+	gettimeofday(&st, NULL);
+
+	while( True )
+	{
+	    kudelay( count );
+	    count = (count << 1);
+	    gettimeofday(&et, NULL);
+	    gap = (((et.tv_sec - st.tv_sec) * 1000000) +
+			(et.tv_usec - st.tv_usec) );
+
+	    if( gap > 400*1000 )
+		break;
+	}
+
+	kuliber_time = (float)(gap/4);
+	kuliber_count = (float)(((count-1)&~0xFFF)>>2);
+    }
+
+    if( usec > kutimerswap )
+    {
+	kutimerswap = (1000000 / 30);
+	usleep( usec );		/* using usleep() for low resolution only */
+    }
+    else
+    {
+	kutimerswap = (1000000 / 15);
+	kudelay( (unsigned long)(kuliber_count*((float)usec/kuliber_time)) );
+    }
+}
+
+#if NeedFunctionPrototypes
 void sleepSync(Display *display, unsigned long ms)
 #else
 void sleepSync(display, ms)
@@ -112,27 +174,85 @@ void sleepSync(display, ms)
     unsigned long ms;
 #endif
 {
-    struct timeval st, et;
-    long SyncTime;
-    static unsigned long accu;
+    static long		Expected_time = 0;
+    static long		Ref_sec = 0;
+    static long		Ref_usec = 0;
+    static long		Sleeping_time = 0;
+    static int		PLL_filter = 0;
+    struct timeval	st;
+    long		elapsed;
+    long		dodelay;
+    float		x;
 
-    gettimeofday(&st, NULL);
     XSync(display, False);
-    gettimeofday(&et, NULL);
 
-    SyncTime = (((et.tv_sec - st.tv_sec) * 1000) +
-               ((et.tv_usec - st.tv_usec) / 1000) );
+    gettimeofday(&st, NULL);
 
-/*    if ((ms) > ((1000 / 60) + SyncTime))
-        usleep(ms - SyncTime);
-*/
-    if ((ms + accu) > ((1000 / 30) + SyncTime)) 
+    if( Ref_sec == 0 )
     {
-        usleep(ms +accu - SyncTime);
-        accu = 0;
+	Ref_sec = st.tv_sec;	/* take the initial reference point */
+	Ref_usec = st.tv_usec;
+	Sleeping_time = ms * 1000;
     }
-    else if (ms > SyncTime)
-       accu += (ms - SyncTime);
+
+    elapsed = (st.tv_sec - Ref_sec) * 1000000 + (st.tv_usec - Ref_usec);
+    dodelay = Sleeping_time;
+
+    if( PLL_filter > 0 && elapsed != 0 )	/* Phase lock loop */
+    {
+	dodelay = Expected_time + Sleeping_time - elapsed;
+
+	if( dodelay < 0 )
+	{
+	    dodelay = 0; PLL_filter--;
+	}
+	else
+	    if( dodelay > 2*Sleeping_time )
+	    {
+		dodelay = 2*Sleeping_time; PLL_filter--;
+	    }
+	    else
+		PLL_filter = 3;
+
+	if( elapsed > 40*Sleeping_time && Expected_time > 40*Sleeping_time )
+	{
+	    elapsed -= 20*Sleeping_time; /* Ref. point shouldn't be far away*/
+	    Expected_time -= 20*Sleeping_time;
+	    Ref_usec += 20*Sleeping_time;
+	    Ref_sec += Ref_usec/1000000; Ref_usec %= 1000000;
+	}
+    }
+
+    if( PLL_filter <= 0 && elapsed > 40000 )	/* Frequency lock loop */
+    {
+	/* feedback filter */
+	x = 0.5 + 0.5 * (float)Expected_time / (float)elapsed;
+
+	if( x < 0.966 )	/* Acceleration must be strongly limited */
+	    x = 0.966;
+
+	if( x > 2.0 )
+	    x = 2.0;
+
+	Sleeping_time = (long)((float)Sleeping_time * x);
+
+	if( Sleeping_time < 500 )
+	    Sleeping_time = 500;
+
+	if( x > 0.99 && x < 1.01 && Sleeping_time > ms*500 )
+	    PLL_filter = -1 - 4*PLL_filter; /* locked - it's time to try PLL */
+	else
+	    PLL_filter = 0;
+
+	Ref_sec = st.tv_sec;
+	Ref_usec = st.tv_usec;
+	Expected_time = 0;
+	dodelay = Sleeping_time;
+    }
+
+    kusleep( dodelay );
+
+    Expected_time += ms * 1000;
 }
 
 #if NeedFunctionPrototypes
@@ -427,7 +547,7 @@ char *GetHomeDir()
      */
 
     if ((ptr = getenv("HOME")) != NULL)
-        (void) strcpy(dest, ptr);
+        (void) strncpy(dest, ptr,sizeof(dest)-1);
     else
     {
         /* HOME variable is not present so get USER var */
@@ -441,7 +561,7 @@ char *GetHomeDir()
         }
 
         if (pw)
-            (void) strcpy(dest, pw->pw_dir);
+            (void) strncpy(dest, pw->pw_dir, sizeof(dest)-1);
         else
             *dest = '\0';
     }
