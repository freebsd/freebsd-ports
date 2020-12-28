--- tests/test-shellhooks/hooks/pre_gen_project.sh.orig	2020-12-28 09:55:19 UTC
+++ tests/test-shellhooks/hooks/pre_gen_project.sh
@@ -1,4 +1,4 @@
-#!/bin/bash
+#!/bin/sh
 
 echo 'pre generation hook';
 touch 'shell_pre.txt'
