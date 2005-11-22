--- code/unix/unix_shared.c.orig	Mon Aug 15 20:10:07 2005
+++ code/unix/unix_shared.c	Sun Nov 20 18:41:22 2005
@@ -38,7 +38,7 @@
 static char cdPath[MAX_OSPATH];
 
 // Used to determine local installation path
-static char installPath[MAX_OSPATH];
+static char installPath[MAX_OSPATH] = %%Q3DIR%%;
 
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
@@ -136,7 +140,7 @@
 
 	return ret;
 }
-#endif
+// #endif
 
 //#if 0 // bk001215 - see snapvector.nasm for replacement
 #if (defined __APPLE__) // rcg010206 - using this for PPC builds...
