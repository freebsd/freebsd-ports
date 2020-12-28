--- tests/test-shellhooks/hooks/post_gen_project.sh.orig	2020-12-28 09:54:42 UTC
+++ tests/test-shellhooks/hooks/post_gen_project.sh
@@ -1,4 +1,4 @@
-#!/bin/bash
+#!/bin/sh
 
 echo 'post generation hook';
 touch 'shell_post.txt'
