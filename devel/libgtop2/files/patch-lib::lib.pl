--- lib/lib.pl.orig	Mon Sep  1 20:17:45 2003
+++ lib/lib.pl	Wed Sep  3 11:53:12 2003
@@ -116,6 +116,8 @@
 	$param_decl = '';
 	$send_size = '';
 	$send_ptr = '';
+	$send_buf_decl = '';
+	$send_buf = '';
 	$nr_params = (@params = split(/:/, $param_def, 9999));
 	for ($param = 1; $param <= $nr_params; $param++) {
 	    $list = $params[$param];
@@ -135,28 +137,37 @@
 
 		  $fields[$field];
 		$call_param = $call_param . ', ' . $fields[$field];
-		if ($send_ptr eq '') {
-		    $send_ptr = "\n\tconst void *send_ptr = &" .
-
-		      $fields[$field] . ';';
-		}
-		if ($send_size eq '') {
-		    $send_size = "\n\tconst size_t send_size =\n\t\t";
+		if ($send_buf eq '') {
+		    $send_size = "\n\tconst size_t send_size = ";
+		    $send_ptr = "\n\tconst void *send_ptr = &";
+		    if ($nr_params == 1 && $count == 1) {
+			$send_size = $send_size . 'sizeof (' . $fields[$field] . ');';
+			$send_ptr = $send_ptr . $fields[$field] . ';';
+			last;
+		    }
+		    $send_size = $send_size . 'sizeof (send_buf);';
+		    $send_ptr = $send_ptr . 'send_buf;';
 		}
 		else {
-		    $send_size = $send_size . ' + ';
+		    $send_buf_decl = $send_buf_decl . ' ';
+		    $send_buf = $send_buf . ', ';
 		}
-		$send_size = $send_size . 'sizeof (' . $fields[$field] . ')';
+		$send_buf_decl = $send_buf_decl . '' .  $convert{$type} . ' ' .
+
+		  $fields[$field] . ';';
+		$send_buf = $send_buf . '' . $fields[$field];
 	    }
 	}
-	if ($send_size ne '') {
-	    $send_size = $send_size . ';';
-	}
-	else {
+	if ($send_size eq '') {
 	    $send_size = "\n\tconst size_t send_size = 0;";
 	}
 	if ($send_ptr eq '') {
 	    $send_ptr = "\n\tconst void *send_ptr = NULL;";
+	}
+	if ($send_buf ne '') {
+	    $send_ptr = "\n\tconst struct { " . $send_buf_decl . " } send_buf =\n" .
+	      "\t\t{ " . $send_buf . ' };' .
+	      $send_ptr;
 	}
     }
 
