--- src/plugins/keyfile/keyfile.cpp.orig	2018-09-01 02:44:43 UTC
+++ src/plugins/keyfile/keyfile.cpp
@@ -314,7 +314,7 @@ Error _checkVersion(const API *api) {
 		       ERROR_LEVEL_NORMAL,
 		       HBCI_ERROR_CODE_MEDIUM,
 		       ERROR_ADVISE_DONTKNOW,
-		       "need OpenHBCI v"OPENHBCI_VERSION_FULL_STRING
+		       "need OpenHBCI v" OPENHBCI_VERSION_FULL_STRING
 		       " or newer");
   }
 
