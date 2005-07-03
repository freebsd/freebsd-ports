--- ./lib/as_exec.py.orig	Tue Jun 28 12:56:13 2005
+++ ./lib/as_exec.py	Sat Jul  2 22:34:46 2005
@@ -397,7 +397,7 @@
 --- Results :
 """)
       info_start=( nbtest, time.strftime('%c'),
-         os.path.join(REPREF,conf['SRCTEST'][0]), ', '.join(reptest), resutest,
+         os.path.join(REPREF,conf['SRCTEST'][0]), reptest, resutest,
          prof['version'][0], exetmp, cmdetmp, eletmp,
          nbmaxnook, cpresok, facmtps )
       print summary % info_start
