--- filemenu.c.orig	Tue Aug 30 04:38:28 1994
+++ filemenu.c	Fri Nov 17 22:05:05 2000
@@ -95,7 +95,7 @@
 #endif
 #endif	/* _POSIX_SOURCE */
 #else	/* SYSV */
-#ifdef SUNOS4
+#if defined(SUNOS4) || defined(__FreeBSD__)
 #include <dirent.h>
 #else
 #include <sys/dir.h>
@@ -185,7 +185,7 @@
  *    text files 
  *    executable files
  */
-#ifndef SYSV
+#if !defined(SYSV) && !defined(__FreeBSD__)
 static int InList(entry)
 Directory *entry;
 {
@@ -228,7 +228,7 @@
 static void ScanDir(dir)
 char *dir;
 {
-#ifndef SYSV 
+#if !defined(SYSV) && !defined(__FreeBSD__)
     extern 	alphasort();
     Directory   **namelist;
 #else
@@ -238,7 +238,7 @@
 #endif
     register int		i,j;
 
-#ifdef SYSV 
+#if defined(SYSV) || defined(__FreeBSD__)
     if(!(WorkingDir = opendir(dir)))
       {
 	UpdateMessageWindow("scandir: cannot open %s", dir);
@@ -262,7 +262,7 @@
     filelist = (char **) XtMalloc((nfiles+1) * sizeof(char *));
     i = 0;
     for (j=0; j<nfiles; j++) {
-#ifdef SYSV 
+#if defined(SYSV) || defined(__FreeBSD__)
       WorkingDirEntry = readdir(WorkingDir);
       if(!strcmp(WorkingDirEntry->d_name, "."))
 	  strcpy(store, "./");
@@ -305,7 +305,7 @@
     }
     filelist[i++] = NULL;
 
-#ifdef SYSV 
+#if defined(SYSV) || defined(__FreeBSD__)
     closedir(WorkingDir);
 #else
     XtFree((XtPointer) namelist);
