--- inc/cc++/address.h	2010-10-31 15:22:45.000000000 -0700
+++ inc/cc++/address.h	2012-08-12 20:17:20.000000000 -0700
@@ -237,10 +237,10 @@
     bool isMember(const struct in_addr &inaddr) const;
 
     inline bool operator==(const struct sockaddr *a) const
-        {return isMember(a);};
+        {return isMember(a);}
 
     inline bool operator==(const struct in_addr &a) const
-        {return isMember(a);};
+        {return isMember(a);}
 };
 
 #ifdef  CCXX_IPV6
@@ -325,10 +325,10 @@
     bool isMember(const struct in6_addr &inaddr) const;
 
     inline bool operator==(const struct sockaddr *sa) const
-        {return isMember(sa);};
+        {return isMember(sa);}
 
     inline bool operator==(const struct in6_addr &a) const
-        {return isMember(a);};
+        {return isMember(a);}
 };
 
 #endif
