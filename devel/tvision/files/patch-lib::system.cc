--- lib/system.cc.orig	Wed Nov 10 17:08:59 2004
+++ lib/system.cc	Wed Nov 10 17:34:47 2004
@@ -56,6 +56,7 @@
 #include <signal.h>
 #include <stdio.h>
 #include <stdlib.h>
+#include <stdarg.h>
 #include <string.h>
 #include <sys/ioctl.h>
 #include <sys/stat.h>
@@ -105,6 +106,8 @@
 
 extern "C"
 {
+#define _XOPEN_SOURCE
+
 #ifdef HAVE_NCURSES_H
 #include <ncurses.h>
 #else
@@ -131,7 +134,7 @@
 
 /*
  * This is the delay in ms between next evMouseAuto events.  Must be greater
- * than DELAY_SIGALRM (see below).
+ * than DELAY_CURSES (see below).
  */
 #define DELAY_AUTOCLICK_NEXT	100
 
@@ -150,10 +153,9 @@
 #define DELAY_ESCAPE		400
 
 /*
- * This is the delay in ms between consecutive SIGALRM signals.  This
- * signal is used to generate evMouseAuto and cmSysWakeup events.
+ * This is the delay in ms used when waiting for keyboard events.
  */
-#define DELAY_SIGALRM		100
+#define DELAY_CURSES		100
 
 /*
  * This broadcast event is used to update the StatusLine.
@@ -591,7 +593,6 @@
 static TPoint msWhere;		/* mouse coordinates */
 static char env[PATH_MAX];	/* value of the TVOPT environment variable */
 static int curX, curY;		/* current cursor coordinates */
-static int currentTime;		/* current timer value */
 static int doRepaint;		/* should redraw the screen ? */
 static int doResize;		/* resize screen ? */
 static int evLength;		/* number of events in the queue */
@@ -604,15 +605,30 @@
 
 class Timer
 {
-	int limit;
+	long limit;
+	static struct timeval offset_tv;
+	long currentTime()
+	{
+		struct timeval tv;
+		if(!offset_tv.tv_sec && !offset_tv.tv_usec)
+		{
+			gettimeofday(&offset_tv, NULL);
+			return 0;
+		}
+		gettimeofday(&tv, NULL);
+		return 1000L * (tv.tv_sec - offset_tv.tv_sec - 1) + (tv.tv_usec - offset_tv.tv_usec + 1000000L) / 1000L;
+	}
+
 public:
 	Timer() { limit = -1; }
-	int isExpired() { return limit != -1 && currentTime >= limit; }
+	int isExpired() { return limit != -1 && currentTime() >= limit; }
 	int isRunning() { return limit != -1; }
-	void start(int timeout) { limit = currentTime + timeout; }
+	void start(int timeout) { limit = currentTime() + timeout; }
 	void stop() { limit = -1; }
 };
 
+struct timeval Timer::offset_tv = {0,0};
+
 static Timer kbEscTimer;	/* time limit to detect Esc-key sequences */
 static Timer msAutoTimer;	/* time when generate next cmMouseAuto */
 static Timer wakeupTimer;	/* time when generate next cmWakeup */
@@ -703,22 +719,20 @@
  * Reads a key from the keyboard.
  */
 #ifdef NCURSES_MOUSE_VERSION
+static void msInit();
+static void msClose();
+static void msSuspend();
+static void msResume();
 static void msHandle();
 #endif
 
 static void kbHandle()
 {
 	int code, type = 0;
-	sigset_t alarmBlock, normalMask;
-
-	sigemptyset(&alarmBlock);
-	sigaddset(&alarmBlock, SIGALRM);
 
 	/* see if there is data available */
 
-	sigprocmask(SIG_BLOCK, &alarmBlock, &normalMask);
 	code = getch();
-	sigprocmask(SIG_SETMASK, &normalMask, NULL);
 
 #ifdef NCURSES_MOUSE_VERSION
 	if (code == KEY_MOUSE)	/* was it a mouse event ? */
@@ -1138,6 +1152,28 @@
  */
 
 #ifdef NCURSES_MOUSE_VERSION
+static mmask_t orig_mousemask = 0;
+
+static void msInit()
+{
+	mmask_t m = mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, &orig_mousemask);
+}
+
+static void msClose()
+{
+	mmask_t m = mousemask(orig_mousemask, NULL);
+}
+
+static void msSuspend()
+{
+	mmask_t m = mousemask(0, NULL);
+}
+
+static void msResume()
+{
+	mmask_t m = mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
+}
+
 static void msHandle()
 {
 	TEvent event;
@@ -1502,13 +1538,14 @@
 
 static void startcurses()
 {
-	initscr();		/* initialize the curses library */
-	keypad(stdscr, TRUE);	/* enable keyboard mapping */
-	cbreak();		/* do not wait for \n */
-	noecho();		/* do not echo input */
-	if (has_colors()) start_color();
-	timeout(0);		/* set getch() in non-blocking mode */
-	refresh();		/* fix for new ncurses packages */
+	::initscr();		/* initialize the curses library */
+	if (::has_colors()) ::start_color();
+	::cbreak();               /* do not wait for \n */
+	::noecho();               /* do not echo input */
+	::nodelay(stdscr, TRUE);	/* set getch() in non-blocking mode */
+	::timeout(DELAY_CURSES);	/* set getch() in non-blocking mode */
+	::keypad(stdscr, TRUE);	/* enable keyboard mapping */
+	::refresh();		/* fix for new ncurses packages */
 	selectPalette();	/* select the more appropiate palette */
 	TScreen::drawCursor(0);	/* hide the cursor */
 	TScreen::drawMouse(1);	/* draw the mouse pointer */
@@ -1736,6 +1773,10 @@
 	TScreen::drawMouse(0);
 #ifdef ENABLE_GPM
 	gpmClose();
+#else
+#ifdef NCURSES_MOUSE_VERSION
+	msClose();
+#endif
 #endif
 	stopcurses();
 #ifdef ENABLE_VCS
@@ -1765,12 +1806,6 @@
 		msFlag++;
 		break;
 #endif
-	case SIGALRM:
-		/*
-		 * called every DELAY_SIGALRM ms
-		 */
-		currentTime += DELAY_SIGALRM;
-		break;
 	case SIGCONT:
 		/*
 		 * called when the user restart the process after a ctrl-z
@@ -1881,7 +1916,7 @@
 	/* internal stuff */
 
 	curX = curY = 0;
-	currentTime = doRepaint = doResize = evLength = 0;
+	doRepaint = doResize = evLength = 0;
 	evIn = evOut = &evQueue[0];
 	kbEscTimer.stop();
 	msAutoTimer.stop();
@@ -1909,6 +1944,10 @@
 	startcurses();		/* curses stuff */
 #ifdef ENABLE_GPM
 	gpmInit();
+#else
+#ifdef NCURSES_MOUSE_VERSION
+	msInit();
+#endif
 #endif
 	/* catch useful signals */
 
@@ -1921,20 +1960,12 @@
 #ifdef ENABLE_FBSDM
 	sigaction(FBSDM_SIGNAL, &dfl_handler, NULL);
 #endif
-	sigaction(SIGALRM, &dfl_handler, NULL);
 	sigaction(SIGCONT, &dfl_handler, NULL);
 	sigaction(SIGINT, &dfl_handler, NULL);
 	sigaction(SIGQUIT, &dfl_handler, NULL);
 	sigaction(SIGTSTP, &dfl_handler, NULL);
 	sigaction(SIGWINCH, &dfl_handler, NULL);
 
-	/* generates a SIGALRM signal every DELAY_SIGALRM ms */
-
-	struct itimerval timer;
-	timer.it_interval.tv_usec = timer.it_value.tv_usec =
-		DELAY_SIGALRM * 1000;
-	timer.it_interval.tv_sec = timer.it_value.tv_sec = 0;
-	setitimer(ITIMER_REAL, &timer, NULL);
 }
 
 /*
@@ -1951,6 +1982,10 @@
 	startcurses();
 #ifdef ENABLE_GPM
 	gpmResume();
+#else
+#ifdef NCURSES_MOUSE_VERSION
+	msResume();
+#endif
 #endif
 	doRepaint++;
 }
@@ -1959,6 +1994,10 @@
 {
 #ifdef ENABLE_GPM
 	gpmSuspend();
+#else
+#ifdef NCURSES_MOUSE_VERSION
+	msSuspend();
+#endif
 #endif
 	stopcurses();
 }
@@ -1986,6 +2025,10 @@
 		 */
 #ifdef ENABLE_GPM
 		gpmSuspend();
+#else
+#ifdef NCURSES_MOUSE_VERSION
+		msSuspend();
+#endif
 #endif
 		clear();	/* blank the screen */
 		refresh();	/* this is necessary */
@@ -1993,6 +2036,10 @@
 		startcurses();
 #ifdef ENABLE_GPM
 		gpmResume();
+#else
+#ifdef NCURSES_MOUSE_VERSION
+		msResume();
+#endif
 #endif
 		doResize = 0;
 		winsize win;
@@ -2056,11 +2103,14 @@
 		}
 #endif
 		/*
-		 * suspend until there is a signal or some data in file
+		 * suspend until there is a timeout or some data in file
 		 * descriptors
 		 */
+		struct timeval tv;
+		tv.tv_sec = 0;
+		tv.tv_usec = 1000L * DELAY_CURSES;
 		if (select(FD_SETSIZE, &fdActualRead, &fdActualWrite,
-			&fdActualExcept, NULL) > 0)
+			&fdActualExcept, &tv) > 0)
 		{
 			kbReady = FD_ISSET(STDIN_FILENO, &fdActualRead);
 #ifdef ENABLE_GPM
