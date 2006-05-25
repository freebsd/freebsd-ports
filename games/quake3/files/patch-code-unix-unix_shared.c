--- code/unix/unix_shared.c.orig	Thu May 25 14:38:44 2006
+++ code/unix/unix_shared.c	Thu May 25 14:41:26 2006
@@ -38,7 +38,7 @@
 static char cdPath[MAX_OSPATH];
 
 // Used to determine local installation path
-static char installPath[MAX_OSPATH];
+static char installPath[MAX_OSPATH] = DATADIR;
 
 // Used to determine where to store user-specific files
 static char homePath[MAX_OSPATH];
@@ -76,7 +76,7 @@
 	return curtime;
 }
 
-#if defined(__linux__) && !defined(DEDICATED)
+// #if defined(__linux__) && !defined(DEDICATED)
 /*
 ================
 Sys_XTimeToSysTime
@@ -98,11 +98,15 @@
 {
 	int ret, time, test;
 	
+	/*
+	Let's try to comment out this and see what will happen :-)
+	
 	if (!in_subframe->value)
 	{
 		// if you don't want to do any event times corrections
 		return Sys_Milliseconds();
 	}
+	*/
 
 	// test the wrap issue
 #if 0	
@@ -136,10 +140,10 @@
 
 	return ret;
 }
-#endif
+// #endif
 
 //#if 0 // bk001215 - see snapvector.nasm for replacement
-#if (defined __APPLE__) // rcg010206 - using this for PPC builds...
+#ifndef __i386__ // rcg010206 - using this for PPC builds...
 long fastftol( float f ) { // bk001213 - from win32/win_shared.c
   //static int tmp;
   //	__asm fld f
