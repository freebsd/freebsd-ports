--- ext/POSIX/POSIX.xs.orig	Tue Feb  1 11:55:24 2005
+++ ext/POSIX/POSIX.xs	Tue Feb  1 11:56:43 2005
@@ -3860,6 +3860,16 @@
 	    mytm.tm_yday = yday;
 	    mytm.tm_isdst = isdst;
 	    mini_mktime(&mytm);
+ /* use libc to normalize the thing -- @@@ -- FreeBSD PR 74042, perl bug 18238 */
+ {
+ struct tm mytm2;
+ time_t t;
+ mytm2 = mytm;
+ t = mktime(&mytm2);
+ mytm2 = *localtime(&t);
+ mytm.tm_gmtoff = mytm2.tm_gmtoff;
+ mytm.tm_zone = mytm2.tm_zone;
+ }
 	    len = strftime(tmpbuf, sizeof tmpbuf, fmt, &mytm);
 	    /*
 	    ** The following is needed to handle to the situation where 
