--- ace/OS_NS_netdb.inl.orig	Sun Apr 23 23:34:14 2006
+++ ace/OS_NS_netdb.inl	Sun Apr 23 23:39:33 2006
@@ -101,7 +101,7 @@
       *h_errnop = h_errno;
       return (struct hostent *) 0;
     }
-# elif defined (__GLIBC__)
+# elif defined (__GLIBC__) || defined (__FreeBSD__)
   // GNU C library has a different signature
   ACE_OS::memset (buffer, 0, sizeof (ACE_HOSTENT_DATA));
 
@@ -211,7 +211,7 @@
       *h_errnop = h_errno;
       return (struct hostent *) 0;
     }
-# elif defined (__GLIBC__)
+# elif defined (__GLIBC__) || defined (__FreeBSD__)
   // GNU C library has a different signature
   ACE_OS::memset (buffer, 0, sizeof (ACE_HOSTENT_DATA));
 
@@ -360,7 +360,7 @@
     return result;
   else
     return 0;
-# elif defined (__GLIBC__)
+# elif defined (__GLIBC__) || defined (__FreeBSD__)
   // GNU C library has a different signature
   if (::getprotobyname_r (name,
                           result,
@@ -427,7 +427,7 @@
     return result;
   else
     return 0;
-# elif defined (__GLIBC__)
+# elif defined (__GLIBC__) || (__FreeBSD__)
   // GNU C library has a different signature
   if (::getprotobynumber_r (proto,
                             result,
@@ -499,7 +499,7 @@
     return result;
   else
     return (struct servent *) 0;
-# elif defined (__GLIBC__)
+# elif defined (__GLIBC__) || defined (__FreeBSD__)
   // GNU C library has a different signature
   ACE_OS::memset (buf, 0, sizeof (ACE_SERVENT_DATA));
 
