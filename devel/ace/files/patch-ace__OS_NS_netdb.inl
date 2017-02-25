--- ace/OS_NS_netdb.inl.orig	2016-05-02 07:59:38 UTC
+++ ace/OS_NS_netdb.inl
@@ -3,6 +3,8 @@
 #include "ace/OS_NS_string.h"
 #include "ace/OS_NS_errno.h"
 
+#include <sys/param.h>
+
 #if defined (ACE_LACKS_NETDB_REENTRANT_FUNCTIONS)
 # if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0) && !defined (HPUX_11)
 #   define ACE_NETDBCALL_RETURN(OP,TYPE,FAILVALUE,TARGET,SIZE) \
@@ -117,7 +119,7 @@ ACE_OS::gethostbyaddr_r (const char *add
       *h_errnop = h_errno;
       return (struct hostent *) 0;
     }
-#   elif defined (__GLIBC__)
+#   elif defined (__GLIBC__) || (defined(__FreeBSD__) && __FreeBSD_version >= 700015)
   // GNU C library has a different signature
   ACE_OS::memset (buffer, 0, sizeof (ACE_HOSTENT_DATA));
 
@@ -303,7 +305,7 @@ ACE_OS::gethostbyname_r (const char *nam
       *h_errnop = h_errno;
       return (struct hostent *) 0;
     }
-#   elif defined (__GLIBC__)
+#   elif defined (__GLIBC__) || (defined(__FreeBSD__) && __FreeBSD_version >= 700015)
   // GNU C library has a different signature
   ACE_OS::memset (buffer, 0, sizeof (ACE_HOSTENT_DATA));
 
@@ -516,7 +518,7 @@ ACE_OS::getprotobyname_r (const char *na
   else
     return 0;
   //FUZZ: enable check_for_lack_ACE_OS
-# elif defined (__GLIBC__)
+# elif defined (__GLIBC__) || (defined(__FreeBSD__) && __FreeBSD_version >= 700015)
   // GNU C library has a different signature
   //FUZZ: disable check_for_lack_ACE_OS
   if (::getprotobyname_r (name,
@@ -597,7 +599,7 @@ ACE_OS::getprotobynumber_r (int proto,
   //FUZZ: enable check_for_lack_ACE_OS
   else
     return 0;
-# elif defined (__GLIBC__)
+# elif defined (__GLIBC__) || (defined(__FreeBSD__) && __FreeBSD_version >= 700015)
   // GNU C library has a different signature
   //FUZZ: disable check_for_lack_ACE_OS
   if (::getprotobynumber_r (proto,
@@ -683,7 +685,7 @@ ACE_OS::getservbyname_r (const char *svc
   //FUZZ: enable check_for_lack_ACE_OS
   else
     return (struct servent *) 0;
-# elif defined (__GLIBC__)
+# elif defined (__GLIBC__) || (defined(__FreeBSD__) && __FreeBSD_version >= 700015)
   // GNU C library has a different signature
   ACE_OS::memset (buf, 0, sizeof (ACE_SERVENT_DATA));
 
