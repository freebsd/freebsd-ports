--- tests/test-pyshellhooks/hooks/pre_gen_project.sh.orig	2020-12-28 10:00:09 UTC
+++ tests/test-pyshellhooks/hooks/pre_gen_project.sh
@@ -1,4 +1,4 @@
-#!/bin/bash
+#!/bin/sh
 
 echo 'post generation hook';
 touch 'shell_pre.txt'
