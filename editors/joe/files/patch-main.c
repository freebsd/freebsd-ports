$NetBSD: patch-main.c,v 1.1 2011/04/01 13:12:24 wiz Exp $

Fix for crash with a segv if called as jmacs with more then
one file as an argument on the command line from upstream.

http://joe-editor.cvs.sourceforge.net/viewvc/joe-editor/joe-current/main/main.c?r1=1.5&r2=1.6

--- main.c.orig	2008-10-27 03:01:11.000000000 +0000
+++ main.c
@@ -431,7 +431,7 @@ int main(int argc, char **real_argv, cha
 				b->orphan = 1;
 				b->oldcur = pdup(b->bof, USTR "main");
 				pline(b->oldcur, get_file_pos(b->name));
-				p_goto_bol(bw->cursor);
+				p_goto_bol(b->oldcur);
 				line = b->oldcur->line - (maint->h - 1) / 2;
 				if (line < 0)
 					line = 0;
