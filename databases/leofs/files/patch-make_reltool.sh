--- make_reltool.sh.orig	2018-04-24 12:31:51.000000000 +0200
+++ make_reltool.sh	2018-06-11 15:59:25.081369000 +0200
@@ -1,4 +1,4 @@
-#!/bin/bash
+#!/bin/sh
 
 # requires first parameter to be either "yes" or "no", which is done by "make reltool"
 with_sd_notify=$1
