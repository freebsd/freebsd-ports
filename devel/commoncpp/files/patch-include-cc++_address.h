--- inc/cc++/address.h	Tue Jan 23 14:15:02 2007
+++ inc/cc++/address.h	Tue Sep 11 11:58:17 2007
@@ -236,10 +236,10 @@
 	bool isMember(const struct in_addr &inaddr) const;
 
 	inline bool operator==(const struct sockaddr *a) const
-		{return isMember(a);};
+		{return isMember(a);}
 
 	inline bool operator==(const struct in_addr &a) const
-		{return isMember(a);};
+		{return isMember(a);}
 };
 
 #ifdef	CCXX_IPV6
@@ -324,10 +324,10 @@
 	bool isMember(const struct in6_addr &inaddr) const;
 
 	inline bool operator==(const struct sockaddr *sa) const
-		{return isMember(sa);};
+		{return isMember(sa);}
 
 	inline bool operator==(const struct in6_addr &a) const
-		{return isMember(a);};
+		{return isMember(a);}
 };
 
 #endif
