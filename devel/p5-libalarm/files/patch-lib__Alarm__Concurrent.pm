--- ./lib/Alarm/Concurrent.pm.orig	2004-05-11 22:06:28.000000000 +0000
+++ ./lib/Alarm/Concurrent.pm	2008-03-27 16:18:44.000000000 +0000
@@ -198,12 +198,14 @@
 =cut
 sub setalarm($$) {
   my ($alarm, $code) = @_;
+  my $alarm_id = 0;
 
   unless(not defined($code) or UNIVERSAL::isa($code, 'CODE')) {
     croak("Alarm handler must be CODEREF");
   }
 
   push( @ALARM_QUEUE, [ $alarm, time(), $code ] );
+  $alarm_id = $#ALARM_QUEUE;
 
   my $time_remaining;
   $time_remaining  = $ALARM_QUEUE[$ACTIVE_ALARM][1];
@@ -214,6 +216,8 @@
     $ACTIVE_ALARM = $#ALARM_QUEUE;
     CORE::alarm($alarm);
   }
+
+  return $alarm_id;
 }
 
 =item clearalarm INDEX LENGTH
