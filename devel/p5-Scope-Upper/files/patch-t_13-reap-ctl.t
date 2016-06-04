--- t/13-reap-ctl.t.orig	2015-08-18 13:44:19 UTC
+++ t/13-reap-ctl.t
@@ -302,10 +302,12 @@ $y = undef;
    reap { ++$y; die "reaped\n" } => HERE;
    is $x, 3,     'die in reap at eval [not yet - x]';
    is $y, undef, 'die in reap at eval [not yet - y]';
-  }; # should trigger here, but the die isn't catched by this eval
-  die "failed\n";
+  }; # should trigger here, but the die isn't catched by this eval in
+     # ealier perls
+  die "inner\n";
  };
- is $@, "reaped\n", 'die in reap at eval [ok - $@]';
+ is $@, ($] >= 5.023008 ? "inner\n" : "reaped\n"),
+        'die in reap at eval [ok - $@]';
  is $x, 1, 'die in reap at eval [ok - x]';
  is $y, 1, 'die in reap at eval [ok - y]';
 }
