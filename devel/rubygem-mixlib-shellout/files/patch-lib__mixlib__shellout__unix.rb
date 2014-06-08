--- lib/mixlib/shellout/unix.rb.bak	2014-05-21 13:10:28.670548925 +0200
+++ lib/mixlib/shellout/unix.rb		2014-05-21 13:10:40.484660467 +0200
@@ -222,7 +222,7 @@
       # the ulimit based on platform.
       def clean_parent_file_descriptors
         # Don't clean $stdin, $stdout, $stderr, process_status_pipe.
-        3.upto(256) do |n|
+        9.upto(256) do |n|
           # We are checking the fd for error pipe before attempting to
           # create a file because error pipe will auto close when we
           # try to create a file since it's set to CLOEXEC.
