From 75e405a41f5b4954bc253168acbf12b8b4136871 Mon Sep 17 00:00:00 2001
From: Christian Hergert <chergert@redhat.com>
Date: Mon, 28 Jan 2019 14:52:38 -0800
Subject: [PATCH] branch-enumerator: fix missing struct field init

This needs to be set to NULL so that it is not accidentially freed during
a call to ggit_branch_enumerator_next().
--- libgit2-glib/ggit-branch-enumerator.c.orig	2018-11-04 01:51:54 UTC
+++ libgit2-glib/ggit-branch-enumerator.c
@@ -19,6 +19,7 @@ _ggit_branch_enumerator_wrap (git_branch_iterator *ite
 	ret = g_slice_new (GgitBranchEnumerator);
 	ret->ref_count = 1;
 	ret->iterator = iter;
+	ret->ref = NULL;
 
 	return ret;
 }
