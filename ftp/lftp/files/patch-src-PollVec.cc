Fix build on i386 [1]

[1] https://lists.freebsd.org/pipermail/freebsd-pkg-fallout/Week-of-Mon-20170911/539371.html

--- ./src/PollVec.cc.orig	2017-09-16 22:29:12.266876000 +0200
+++ ./src/PollVec.cc	2017-09-16 22:31:49.303761000 +0200
@@ -30,7 +30,7 @@
 
 void PollVec::AddTimeoutU(unsigned t)
 {
-   struct timeval new_timeout={t/1000000,t%1000000};
+   struct timeval new_timeout={static_cast<time_t>(t/1000000),static_cast<suseconds_t>(t%1000000)};
    if(tv_timeout.tv_sec<0 || new_timeout<tv_timeout)
       SetTimeout(new_timeout);
 }
