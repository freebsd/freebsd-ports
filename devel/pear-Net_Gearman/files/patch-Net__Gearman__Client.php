--- Net/Gearman/Client.php.orig	1970-01-01 09:13:08 UTC
+++ Net/Gearman/Client.php
@@ -166,11 +166,11 @@ class Net_Gearman_Client
         $s = $this->getConnection();
         Net_Gearman_Connection::send($s, $type, $params);
 
-        if (!is_array(Net_Gearman_Connection::$waiting[$s])) {
-            Net_Gearman_Connection::$waiting[$s] = array();
+        if (!is_array(Net_Gearman_Connection::$waiting[(int) $s])) {
+            Net_Gearman_Connection::$waiting[(int) $s] = array();
         }
 
-        array_push(Net_Gearman_Connection::$waiting[$s], $task);
+        array_push(Net_Gearman_Connection::$waiting[(int) $s], $task);
     }
 
     /**
@@ -244,7 +244,7 @@ class Net_Gearman_Client
             $task->fail();
             break;
         case 'job_created':
-            $task         = array_shift(Net_Gearman_Connection::$waiting[$s]);
+            $task         = array_shift(Net_Gearman_Connection::$waiting[(int) $s]);
             $task->handle = $resp['data']['handle'];
             if ($task->type == Net_Gearman_Task::JOB_BACKGROUND) {
                 $task->finished = true;
