--- contrib/repl.sh.orig	2025-10-26 05:55:04 UTC
+++ contrib/repl.sh
@@ -1,4 +1,4 @@
-#!/bin/bash
+#!/bin/sh
 
 EXEC=$(which ledger)
 if [[ -z "$EXEC" ]]; then
