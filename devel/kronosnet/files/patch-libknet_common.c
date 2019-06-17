From 97924ac12d8da26b61d3bc3ab90fbd86b0b58e72 Mon Sep 17 00:00:00 2001
From: =?UTF-8?q?Jan=20Pokorn=C3=BD?= <jpokorny@redhat.com>
Date: Thu, 24 Jan 2019 14:54:24 +0100
Subject: [PATCH] [common] fix not reporting a true dlinfo error cause
MIME-Version: 1.0
Content-Type: text/plain; charset=UTF-8
Content-Transfer-Encoding: 8bit

This was automatically caught with GCC 9
("'%s' directive argument is null").

Signed-off-by: Jan Pokorný <jpokorny@redhat.com>
--- libknet/common.c.orig	2018-02-25 04:32:12 UTC
+++ libknet/common.c
@@ -82,6 +82,7 @@ static void *open_lib(knet_handle_t knet_h, const char
 		/*
 		 * should we dlclose and return error?
 		 */
+		error = dlerror();
 		log_warn(knet_h, KNET_SUB_COMMON, "unable to dlinfo %s: %s",
 			 libname, error);
 	} else {
