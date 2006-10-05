--- include/cc++/address.h	Sun Oct  1 07:07:12 2006
+++ include/cc++/address.h	Wed Oct  4 21:25:44 2006
@@ -237,10 +237,10 @@
 };
 
 inline bool operator==(struct sockaddr *sa, IPV4Cidr &cidr)
-	{return cidr.isMember(sa);};
+	{return cidr.isMember(sa);}
 
 inline bool operator==(struct in_addr &a, IPV4Cidr &cidr)
-	{return cidr.isMember(a);};
+	{return cidr.isMember(a);}
 
 #ifdef	CCXX_IPV6
 /**
@@ -325,10 +325,10 @@
 };
 
 inline bool operator==(struct sockaddr *sa, IPV6Cidr &cidr)
-	{return cidr.isMember(sa);};
+	{return cidr.isMember(sa);}
 
 inline bool operator==(struct in6_addr &a, IPV6Cidr &cidr)
-	{return cidr.isMember(a);};
+	{return cidr.isMember(a);}
 
 #endif
 
