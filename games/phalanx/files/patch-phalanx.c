--- phalanx.c.orig	Fri Jul 18 13:36:59 2003
+++ phalanx.c	Fri Jul 18 13:38:52 2003
@@ -11,30 +11,30 @@
 
 void badoptions(void)
 {
-printf("\
-Usage:    phalanx [options] [<moves> <minutes> [<increment in seconds>]]
-          phalanx [options] [<seconds per move>]
-          phalanx bench
-          phalanx bcreate [options]
-Options:  -t <transposition table size in kilobytes>
-          -f <fixed search time in seconds>
-          -x <+/->  xboard mode on/off        default: on
-          -p <+/->  permanent brain on/off    default: off
-          -s <+/->  show thinking on/off      default: off
-          -c <+/->  cpu time                  default: off
-          -o <+/->  polling input             default: on
-          -b <+/->  opening book              default: on
-          -r <resign value in centipawns>     default: 0 (no resigning)
-          -e <easy level 0...100>             default: 0 (best play)
-          -l <+/->  learning on/off           default: on
-          -v        print version and exit
-          -P <primary book directory>
-          -S <secondary book directory>
-          -L <learning file directory>
-          -g <log file name>
-Examples: phalanx -c+ -s+ -o - -x- -f 60 -t4000
-          xboard -fcp \"phalanx -l+ -r800\"
-");
+printf("\n"
+"Usage:    phalanx [options] [<moves> <minutes> [<increment in seconds>]]\n"
+          "phalanx [options] [<seconds per move>]\n"
+          "phalanx bench\n"
+          "phalanx bcreate [options]\n"
+"Options:  -t <transposition table size in kilobytes>\n"
+          "-f <fixed search time in seconds>\n"
+          "-x <+/->  xboard mode on/off        default: on\n"
+          "-p <+/->  permanent brain on/off    default: off\n"
+          "-s <+/->  show thinking on/off      default: off\n"
+          "-c <+/->  cpu time                  default: off\n"
+          "-o <+/->  polling input             default: on\n"
+          "-b <+/->  opening book              default: on\n"
+          "-r <resign value in centipawns>     default: 0 (no resigning)\n"
+          "-e <easy level 0...100>             default: 0 (best play)\n"
+          "-l <+/->  learning on/off           default: on\n"
+          "-v        print version and exit\n"
+          "-P <primary book directory>\n"
+          "-S <secondary book directory>\n"
+          "-L <learning file directory>\n"
+          "-g <log file name>\n"
+"Examples: phalanx -c+ -s+ -o - -x- -f 60 -t4000\n"
+          "xboard -fcp \"phalanx -l+ -r800\n"
+);
 exit(0);
 }
 
