--- lib/CGI.pm.orig	Fri Feb 12 09:05:57 1999
+++ lib/CGI.pm	Sat Oct  4 01:14:41 2003
@@ -1413,8 +1413,8 @@
 
     $method = $method || 'POST';
     $enctype = $enctype || &URL_ENCODED;
-    $action = $action ? qq/ACTION="$action"/ : $method eq 'GET' ?
-	'ACTION="'.$self->script_name.'"' : '';
+    $action = $action ? 'ACTION="'.$self->escapeHTML($action).'"' : $method eq 'GET' ?
+	'ACTION="'.$self->escapeHTML($self->script_name).'"' : '';
     my($other) = @other ? " @other" : '';
     $self->{'.parametersToAdd'}={};
     return qq/<FORM METHOD="$method" $action ENCTYPE="$enctype"$other>\n/;
