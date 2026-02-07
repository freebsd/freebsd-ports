--- lib/stdlib/src/calendar.erl.orig	2015-03-31 12:32:52 UTC
+++ lib/stdlib/src/calendar.erl
@@ -279,11 +279,19 @@ local_time_to_universal_time(DateTime, I
       DateTime1 :: datetime1970(),
       DateTime :: datetime1970().
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
