fix sh: Syntax error: Unterminated quoted string
    Filter command '"sed" "-e" "s\"' failed

--- Makefile.PL.orig	2025-07-13 08:56:55 UTC
+++ Makefile.PL
@@ -21,7 +21,7 @@ WriteMakefile(
     'PREREQ_PM'    => {
         'POE' => '0.22',
     },
-    PM_FILTER => "sed -e s\\#__DEFAULT_RRDTOOL__\\#${DEFAULT_RRDTOOL}\\#g -e s\\#__RRDTOOL_VERSION__\\#${RRDTOOL_VERSION}\\#g",
+    PM_FILTER => "sed -e s=__DEFAULT_RRDTOOL__=${DEFAULT_RRDTOOL}=g -e s=__RRDTOOL_VERSION__=${RRDTOOL_VERSION}=g",
     (($] ge '5.005') ? 
         (   'AUTHOR'   => 'Todd Caine <todd@pobox.com>',
             'ABSTRACT' => 'POE interface to Tobias Oetiker\'s RRDTool',
