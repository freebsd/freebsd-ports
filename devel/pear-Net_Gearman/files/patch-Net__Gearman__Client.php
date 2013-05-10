--- ./Net/Gearman/Client.php.orig	2013-03-13 17:50:59.000000000 +0800
+++ ./Net/Gearman/Client.php	2013-03-13 17:51:18.000000000 +0800
@@ -166,11 +166,11 @@
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
@@ -244,7 +244,7 @@
             $task->fail();
             break;
         case 'job_created':
-            $task         = array_shift(Net_Gearman_Connection::$waiting[$s]);
+            $task         = array_shift(Net_Gearman_Connection::$waiting[(int) $s]);
             $task->handle = $resp['data']['handle'];
             if ($task->type == Net_Gearman_Task::JOB_BACKGROUND) {
                 $task->finished = true;
