From 6733b1455f97531bace80bf7118dc644fe73fd3d Mon Sep 17 00:00:00 2001
From: tg <tg@mirbsd.org>
Date: Wed, 26 Jun 2013 18:15:51 +0000
Subject: Make cvs.texinfo compatible with newer makeinfo (Closes: #711298)


diff --git a/doc/cvs.texinfo b/doc/cvs.texinfo
index a0136a5..d11a5e1 100644
--- ../cvs/doc/cvs.texinfo
+++ ../cvs/doc/cvs.texinfo
@@ -113,9 +113,9 @@ approved by the Free Software Foundation.
 @sp 4
 @comment The title is printed in a large font.
 @center @titlefont{Version Management}
-@sp
+@sp 1
 @center @titlefont{with}
-@sp
+@sp 1
 @center @titlefont{CVS}
 @sp 2
 @center for @sc{cvs} @value{VERSION}
