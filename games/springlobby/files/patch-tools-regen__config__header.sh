--- tools/regen_config_header.sh.orig	2011-04-25 01:48:12.000000000 +0400
+++ tools/regen_config_header.sh	2011-05-05 12:03:25.000000000 +0400
@@ -1,4 +1,4 @@
-#!/usr/bin/env bash
+#!/bin/sh
 
 #regen on bbot releases would screw with version
 if [ "x${BUILDBOT_RELEASE}" != "x" ] ; then
@@ -14,6 +14,7 @@
 REV_TEMPLATE="@SPRINGLOBBY_REV@"
 
 #don't fail if no .git
+exit 0
 git branch &> /dev/null || exit 0
 
 REV="$(git describe --tags)"
