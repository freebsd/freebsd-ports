Make the build reproducible
--- src/Mixfix/banner.cc.orig	2018-09-17 10:53:25 UTC
+++ src/Mixfix/banner.cc
@@ -53,8 +53,7 @@ printBanner(std::ostream& s)
     Tty(Tty::GREEN) << 'e' <<
     Tty(Tty::RESET) << " ---\n";
   s << "\t\t     /||||||||||||||||||\\\n";
-  s << "\t   " << PACKAGE_STRING << " built: " <<
-    __DATE__ << ' ' << __TIME__ << '\n';
+  s << "\t   " << PACKAGE_STRING << " built by FreeBSD ports\n";
   s << "\t    Copyright 1997-2016 SRI International\n";
   s << "\t\t   " << ctime(&secs);
 }
