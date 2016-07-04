$NetBSD: patch-as,v 1.1 2010/12/17 09:40:14 wiz Exp $

From upstream SVN.

--- src/libmojave-external/unix/lm_notify.ml.orig	2007-07-19 21:06:05.000000000 +0000
+++ src/libmojave-external/unix/lm_notify.ml
@@ -153,10 +153,8 @@ let is_path_prefix (root1, path1) (root2
 let is_monitored_name requests name =
    let new_path = path_of_name name in
       IntTable.exists (fun _ job ->
-            let { job_path = path;
-                  job_recursive = recursive
-                } = job
-            in
+            let path = job.job_path in
+            let recursive = job.job_recursive in
                new_path = path || (recursive && is_path_prefix path new_path)) requests
 
 (************************************************************************
@@ -215,18 +213,16 @@ let close notify =
 (*
  * Get the file descriptor.
  *)
-let file_descr { notify_fd = fd } =
-   fd
+let file_descr notify =
+   notify.notify_fd
 
 (*
  * Monitoring.
  *)
 let monitor notify dir recursive =
-   let { notify_info = info;
-         notify_dirs = dirs;
-         notify_requests = requests
-       } = notify
-   in
+   let info = notify.notify_info in
+   let dirs = notify.notify_dirs in
+   let requests = notify.notify_requests in
    let name = name_of_dir dir in
       if not (is_monitored_name requests name) then begin
          if !debug_notify then
@@ -250,11 +246,9 @@ let monitor notify dir recursive =
  * Suspend notifications.
  *)
 let suspend notify dir =
-   let { notify_info = info;
-         notify_dirs = dirs;
-         notify_requests = requests
-       } = notify
-   in
+   let info = notify.notify_info in
+   let dirs = notify.notify_dirs in
+   let requests = notify.notify_requests in
    let dir = name_of_dir dir in
    let request =
       try StringTable.find dirs dir with
@@ -269,10 +263,8 @@ let suspend notify dir =
          end
 
 let suspend_all notify =
-   let { notify_info = info;
-         notify_requests = requests
-       } = notify
-   in
+   let info = notify.notify_info in
+   let requests = notify.notify_requests in
       IntTable.iter (fun _ job ->
             if job.job_running then
                begin
@@ -281,11 +273,9 @@ let suspend_all notify =
                end) requests
 
 let resume notify dir =
-   let { notify_info = info;
-         notify_dirs = dirs;
-         notify_requests = requests
-       } = notify
-   in
+   let info = notify.notify_info in
+   let dirs = notify.notify_dirs in
+   let requests = notify.notify_requests in
    let dir = name_of_dir dir in
    let request =
       try StringTable.find dirs dir with
@@ -300,10 +290,8 @@ let resume notify dir =
          end
 
 let resume_all notify =
-   let { notify_info = info;
-         notify_requests = requests
-       } = notify
-   in
+   let info = notify.notify_info in
+   let requests = notify.notify_requests in
       IntTable.iter (fun _ job ->
             if not job.job_running then
                begin
@@ -315,11 +303,9 @@ let resume_all notify =
  * Cancel a request.
  *)
 let cancel notify dir =
-   let { notify_info = info;
-         notify_dirs = dirs;
-         notify_requests = requests
-       } = notify
-   in
+   let info = notify.notify_info in
+   let dirs = notify.notify_dirs in
+   let requests = notify.notify_requests in
    let dir = name_of_dir dir in
    let request =
       try StringTable.find dirs dir with
@@ -332,10 +318,8 @@ let cancel notify dir =
       notify.notify_requests <- IntTable.remove requests request
 
 let cancel_all notify =
-   let { notify_info = info;
-         notify_requests = requests
-       } = notify
-   in
+   let info = notify.notify_info in
+   let requests = notify.notify_requests in
       IntTable.iter (fun request _ -> notify_cancel info request) requests;
       notify.notify_dirs <- StringTable.empty;
       notify.notify_requests <- IntTable.empty
