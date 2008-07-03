From 12837594b705ad10fdadfd0ba1bfc2249b3b1264 Mon Sep 17 00:00:00 2001
From: Michael Krelin <hacker@klever.net>
Date: Sun, 29  Jun  2008  16:08:01  +0000
Subject: Fixed w3c to unix timestamp conversion for FreeBSD

Thanks to Göran Löwkrantz for pointing both to the problem and possible
solution.

Signed-off-by: Michael Krelin <hacker@klever.net>
---
diff --git a/configure.ac b/configure.ac
index 3194718..3484146 100644
--- configure.ac
+++ configure.ac
@@ -10,6 +10,7 @@ AC_PROG_LIBTOOL
 PKG_PROG_PKG_CONFIG
 
 AC_HEADER_STDC
+AC_CHECK_FUNCS([timegm])
 
 AC_PATH_PROG([XSLTPROC],[xsltproc],[true])
 
diff --git a/lib/util.cc b/lib/util.cc
index d979502..a46ba2a 100644
--- lib/util.cc
+++ lib/util.cc
@@ -122,6 +122,21 @@ namespace opkele {
 	    return rv;
 	}
 
+#ifndef HAVE_TIMEGM
+	static time_t timegm(struct tm *t) {
+	    char *tz = getenv("TZ");
+	    setenv("TZ","",1); tzset();
+	    time_t rv = mktime(t);
+	    if(tz)
+		setenv("TZ",tz,1);
+	    else
+		unsetenv("TZ");
+	    tzset();
+	    return rv;
+	}
+#	define timegm opkele::util::timegm
+#endif /* HAVE_TIMEGM */
+
 	time_t w3c_to_time(const string& w) {
 	    int fraction;
 	    struct tm tm_t;
@@ -145,10 +160,10 @@ namespace opkele {
 		throw failed_conversion(OPKELE_CP_ "failed to sscanf()");
 	    tm_t.tm_mon--;
 	    tm_t.tm_year-=1900;
-	    time_t rv = mktime(&tm_t);
+	    time_t rv = timegm(&tm_t);
 	    if(rv==(time_t)-1)
-		throw failed_conversion(OPKELE_CP_ "failed to mktime()");
-	    return rv-timezone;
+		throw failed_conversion(OPKELE_CP_ "failed to gmtime()");
+	    return rv;
 	}
 
 	/*
--
cgit v0.7.1-118-g42ef
