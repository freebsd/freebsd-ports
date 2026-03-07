--- tests/test-pyshellhooks/hooks/pre_prompt.sh.orig	2026-03-07 13:53:29 UTC
+++ tests/test-pyshellhooks/hooks/pre_prompt.sh
@@ -1,4 +1,4 @@
-#!/bin/bash
+#!/bin/sh
 
 echo 'Pre-Prompt hook';
 touch '_cookiecutter.json'
