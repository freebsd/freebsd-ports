
$FreeBSD$

--- lib/kernel/test/file_SUITE.erl.orig
+++ lib/kernel/test/file_SUITE.erl
@@ -60,7 +60,8 @@
 -export([ read_not_really_compressed/1,
 	 read_compressed_cooked/1, read_compressed_cooked_binary/1,
 	 read_cooked_tar_problem/1,
-	 write_compressed/1, compress_errors/1, catenated_gzips/1]).
+	 write_compressed/1, compress_errors/1, catenated_gzips/1,
+	 compress_async_crash/1]).
 
 -export([ make_link/1, read_link_info_for_non_link/1, symlinks/1]).
 
@@ -133,7 +134,8 @@
      {compression, [],
       [read_compressed_cooked, read_compressed_cooked_binary,
        read_cooked_tar_problem, read_not_really_compressed,
-       write_compressed, compress_errors, catenated_gzips]},
+       write_compressed, compress_errors, catenated_gzips,
+       compress_async_crash]},
      {links, [],
       [make_link, read_link_info_for_non_link, symlinks]}].
 
@@ -2271,6 +2273,57 @@
 
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
+compress_async_crash(suite) -> [];
+compress_async_crash(doc) -> [];
+compress_async_crash(Config) when is_list(Config) ->
+    ?line DataDir = ?config(data_dir, Config),
+    ?line Path = filename:join(DataDir, "test.gz"),
+    ExpectedData = <<"qwerty">>,
+
+    ?line _ = ?FILE_MODULE:delete(Path),
+    ?line {ok, Fd} = ?FILE_MODULE:open(Path, [write, binary, compressed]),
+    ?line ok = ?FILE_MODULE:write(Fd, ExpectedData),
+    ?line ok = ?FILE_MODULE:close(Fd),
+
+    % Test that when using async thread pool, the emulator doesn't crash
+    % when the efile port driver is stopped while a compressed file operation
+    % is in progress (being carried by an async thread).
+    ?line ok = compress_async_crash_loop(10000, Path, ExpectedData),
+    ?line ok = ?FILE_MODULE:delete(Path),
+    ok.
+
+compress_async_crash_loop(0, _Path, _ExpectedData) ->
+    ok;
+compress_async_crash_loop(N, Path, ExpectedData) ->
+    Parent = self(),
+    {Pid, Ref} = spawn_monitor(
+            fun() ->
+                    ?line {ok, Fd} = ?FILE_MODULE:open(
+                                        Path, [read, compressed, raw, binary]),
+                    Len = byte_size(ExpectedData),
+                    Parent ! {self(), continue},
+                    ?line {ok, ExpectedData} = ?FILE_MODULE:read(Fd, Len),
+                    ?line ok = ?FILE_MODULE:close(Fd),
+                    receive foobar -> ok end
+            end),
+    receive
+        {Pid, continue} ->
+            exit(Pid, shutdown),
+            receive
+                {'DOWN', Ref, _, _, Reason} ->
+                    ?line shutdown = Reason
+            end;
+        {'DOWN', Ref, _, _, Reason2} ->
+            test_server:fail({worker_exited, Reason2})
+    after 60000 ->
+            exit(Pid, shutdown),
+            erlang:demonitor(Ref, [flush]),
+            test_server:fail(worker_timeout)
+    end,
+    compress_async_crash_loop(N - 1, Path, ExpectedData).
+
+%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
+
 altname(doc) ->
     "Test the file:altname/1 function";
 altname(suite) ->
