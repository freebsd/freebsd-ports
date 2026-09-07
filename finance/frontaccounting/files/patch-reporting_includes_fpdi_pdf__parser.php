--- reporting/includes/fpdi/pdf_parser.php.orig	2026-04-28 11:25:37 UTC
+++ reporting/includes/fpdi/pdf_parser.php
@@ -48,6 +48,7 @@ class pdf_parser {
 require_once("wrapper_functions.php");
 
 class pdf_parser {
+    var $actual_obj;
 	
 	/**
      * Filename
