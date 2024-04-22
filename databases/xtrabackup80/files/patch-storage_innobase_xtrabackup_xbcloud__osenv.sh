--- storage/innobase/xtrabackup/xbcloud_osenv.sh.orig	2020-08-28 21:02:32 UTC
+++ storage/innobase/xtrabackup/xbcloud_osenv.sh
@@ -1,4 +1,4 @@
-#!/bin/bash
+#!/bin/sh
 
 # Copyright (C) 2015 Percona LLC and/or its affiliates.
 # This software comes with ABSOLUTELY NO WARRANTY. This is free software,
@@ -105,5 +105,5 @@ fi
 
 # do it
 # shellcheck disable=SC2086,SC2048
-${XBCLOUD_BIN} $* ${XBCLOUD_OS_ENV}
+${XBCLOUD_BIN} "$@" ${XBCLOUD_OS_ENV}
 
