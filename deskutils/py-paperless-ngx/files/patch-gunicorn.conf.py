--- gunicorn.conf.py.orig	2024-02-18 20:13:15 UTC
+++ gunicorn.conf.py
@@ -11,7 +11,7 @@ timeout = 120
 preload_app = True
 
 # https://docs.gunicorn.org/en/stable/faq.html#blocking-os-fchmod
-worker_tmp_dir = "/dev/shm"
+worker_tmp_dir = "/tmp"
 
 
 def pre_fork(server, worker):
