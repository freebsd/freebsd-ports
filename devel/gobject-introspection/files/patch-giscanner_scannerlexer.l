$NetBSD: patch-giscanner_scannerlexer.l,v 1.2 2013/05/05 09:20:44 drochner Exp $

Ignore __asm volatile as per PR pkg/46017
https://bugzilla.gnome.org/show_bug.cgi?id=678794

--- giscanner/scannerlexer.l.orig	2012-12-18 16:27:16.000000000 +0000
+++ giscanner/scannerlexer.l
@@ -134,6 +134,8 @@ stringtext				([^\\\"])|(\\.)
 ","					{ return ','; }
 "->"					{ return ARROW; }
 
+"__asm"[\t\f\v\r ]+"volatile"		{ if (!parse_ignored_macro()) REJECT; }
+"__asm__"[\t\f\v\r ]+"volatile"		{ if (!parse_ignored_macro()) REJECT; }
 "__asm" 	        	        { if (!parse_ignored_macro()) REJECT; }
 "__asm__" 	        	        { if (!parse_ignored_macro()) REJECT; }
 "__attribute__" 		        { if (!parse_ignored_macro()) REJECT; }
@@ -145,6 +147,8 @@ stringtext				([^\\\"])|(\\.)
 "__signed__"				{ return SIGNED; }
 "__restrict"				{ return RESTRICT; }
 "__typeof"				{ if (!parse_ignored_macro()) REJECT; }
+"__volatile"				{ if (!parse_ignored_macro()) REJECT; }
+"__volatile__"				{ if (!parse_ignored_macro()) REJECT; }
 "_Bool"					{ return BOOL; }
 
 "G_GINT64_CONSTANT"			{ return INTL_CONST; }
