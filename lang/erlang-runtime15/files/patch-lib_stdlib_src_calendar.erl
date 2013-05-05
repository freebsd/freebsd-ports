
$FreeBSD$

--- lib/stdlib/src/calendar.erl.orig
+++ lib/stdlib/src/calendar.erl
@@ -215,11 +215,19 @@
 
 -spec local_time_to_universal_time_dst(t_datetime1970()) -> [t_datetime1970()].
 local_time_to_universal_time_dst(DateTime) ->
-    UtDst = erlang:localtime_to_universaltime(DateTime, true),
-    Ut    = erlang:localtime_to_universaltime(DateTime, false),
     %% Reverse check the universal times
-    LtDst = erlang:universaltime_to_localtime(UtDst),
-    Lt    = erlang:universaltime_to_localtime(Ut),
+    {UtDst, LtDst} =
+        try
+            UtDst0 = erlang:localtime_to_universaltime(DateTime, true),
+            {UtDst0, erlang:universaltime_to_localtime(UtDst0)}
+        catch error:badarg -> {error, error}
+        end,
+    {Ut, Lt} =
+        try
+            Ut0 = erlang:localtime_to_universaltime(DateTime, false),
+            {Ut0, erlang:universaltime_to_localtime(Ut0)}
+        catch error:badarg -> {error, error}
+        end,
     %% Return the valid universal times
     case {LtDst,Lt} of
 	{DateTime,DateTime} when UtDst =/= Ut ->
