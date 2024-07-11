From 360e1c423b5475fa2c1caba1f19d652538a8f322 Mon Sep 17 00:00:00 2001
From: Peter Bex <peter@more-magic.net>
Date: Mon, 31 Oct 2022 13:06:26 +0100
Subject: [PATCH 1/1] Do not double call normalize-destination on share dir

In install-random-files, don't call normalize-destination on the
destination directory - this is already done in compile-egg-info

Before, we'd see things like in the install script like:
  mkdir -p /path/to/chicken/path/to/chicken/share
With this patch, it becomes:
  mkdir -p /path/to/chicken/share
which is as it should be.

Signed-off-by: felix <felix@call-with-current-continuation.org>
--- egg-compile.scm.orig	2021-11-18 06:32:06 UTC
+++ egg-compile.scm
@@ -1051,7 +1051,7 @@
          (root (string-append srcdir "/"))
          (mkdir (mkdir-command platform))
          (sfiles (map (cut prefix srcdir <>) files))
-         (dfile (qs* (normalize-destination dest mode) platform #t))
+         (dfile (qs* dest platform #t))
          (ddir (shell-variable "DESTDIR" platform)))
     (print "\n" mkdir " " ddir dfile)
     (let-values (((ds fs) (partition directory? sfiles)))
