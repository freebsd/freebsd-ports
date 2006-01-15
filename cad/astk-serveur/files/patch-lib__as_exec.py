--- ./lib/as_exec.py.orig	Thu Oct 20 17:52:32 2005
+++ ./lib/as_exec.py	Tue Jan 10 22:21:37 2006
@@ -402,7 +402,7 @@
 --- Results :
 """)
       info_start = ( nbtest, time.strftime('%c'),
-         os.path.join(REPREF, conf['SRCTEST'][0]), ', '.join(reptest), resutest,
+         os.path.join(REPREF, conf['SRCTEST'][0]), reptest, resutest,
          prof['version'][0], exetmp, cmdetmp, eletmp,
          nbmaxnook, cpresok, facmtps )
       print summary % info_start
