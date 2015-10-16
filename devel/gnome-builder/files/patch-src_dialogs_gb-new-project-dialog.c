Upstream patch to fix build with more fresh libgit2 library we have in ports.
Should be removed after updating to 3.18.0

--- src/dialogs/gb-new-project-dialog.c.orig	2015-04-08 20:10:45 UTC
+++ src/dialogs/gb-new-project-dialog.c
@@ -188,6 +188,7 @@ gb_new_project_dialog__clone_worker (GTa
   g_autoptr(GFile) workdir = NULL;
   CloneRequest *req = task_data;
   GgitCloneOptions *clone_options;
+  GgitFetchOptions *fetch_options;
   GgitRemoteCallbacks *callbacks;
   IdeProgress *progress;
   GError *error = NULL;
@@ -197,21 +198,25 @@ gb_new_project_dialog__clone_worker (GTa
   g_assert (req != NULL);
   g_assert (!cancellable || G_IS_CANCELLABLE (cancellable));
 
-  clone_options = ggit_clone_options_new ();
-  ggit_clone_options_set_is_bare (clone_options, FALSE);
-  ggit_clone_options_set_checkout_branch (clone_options, "master");
-
   callbacks = g_object_new (IDE_TYPE_GIT_REMOTE_CALLBACKS, NULL);
   progress = ide_git_remote_callbacks_get_progress (IDE_GIT_REMOTE_CALLBACKS (callbacks));
   g_object_bind_property (progress, "fraction",
                           self->clone_progress, "fraction",
                           G_BINDING_SYNC_CREATE);
-  ggit_clone_options_set_remote_callbacks (clone_options, callbacks);
+
+  fetch_options = ggit_fetch_options_new ();
+  ggit_fetch_options_set_remote_callbacks (fetch_options, callbacks);
+
+  clone_options = ggit_clone_options_new ();
+  ggit_clone_options_set_is_bare (clone_options, FALSE);
+  ggit_clone_options_set_checkout_branch (clone_options, "master");
+  ggit_clone_options_set_fetch_options (clone_options, fetch_options);
+  g_clear_pointer (&fetch_options, ggit_fetch_options_free);
 
   repository = ggit_repository_clone (req->uri, req->location, clone_options, &error);
 
-  g_object_unref (callbacks);
-  ggit_clone_options_free (clone_options);
+  g_clear_object (&callbacks);
+  g_clear_object (&clone_options);
 
   if (repository == NULL)
     {
