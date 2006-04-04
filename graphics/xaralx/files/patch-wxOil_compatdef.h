--- wxOil/compatdef.h.orig	Thu Mar 23 18:43:35 2006
+++ wxOil/compatdef.h	Thu Mar 23 18:45:19 2006
@@ -136,7 +136,7 @@
 #define lstrcpyn		wcsncpy
 #define lstrcat			wcscat
 #define lstrcmp			wcscmp
-#if defined(__WXMAC__)
+#if defined(__WXMAC__) || defined(__FreeBSD__)
 //PORTNOTE("MacPort", "Horrendous bodge - can't find case insensitive string compare function")
 // NOTE! wcscasecmp not available in wchar.h on Mac OS X (???) Bodged to be case senstive temporarilly...
 #define lstrcmpi		wcscmp
@@ -153,7 +153,7 @@
 #define _tcsncpy		wcsncpy
 #define _tcscat			wcscat
 #define _tcschr			wcschr
-#if defined(__WXMAC__)
+#if defined(__WXMAC__) || defined(__FreeBSD__)
 #define _tcsdup			wxStrdup
 #else
 #define _tcsdup			wcsdup
@@ -162,7 +162,7 @@
 #define tcstok			wcstok
 #define _tcscmp			wcscmp
 #define _tcsncmp		wcsncmp
-#if defined(__WXMAC__)
+#if defined(__WXMAC__) || defined(__FreeBSD__)
 //PORTNOTE("MacPort", "Horrendous bodge - can't find case insensitive string compare function")
 // NOTE! wcsncasecmp not available in wchar.h on Mac OS X (???) Bodged to be case senstive temporarilly...
 #define _tcsnicmp		wcsncmp
