--- lib/CGI.pm.orig	Tue Sep 30 10:16:33 2003
+++ lib/CGI.pm	Tue Sep 30 10:20:35 2003
@@ -1497,8 +1497,10 @@ sub startform {
     $method = lc($method) || 'post';
     $enctype = $enctype || &URL_ENCODED;
     unless (defined $action) {
-       $action = $self->url(-absolute=>1,-path=>1);
-       $action .= "?$ENV{QUERY_STRING}" if $ENV{QUERY_STRING};
+       $action = $self->escapeHTML($self->url(-absolute=>1,-path=>1));
+       if (length($ENV{QUERY_STRING})>0) {
+           $action .= "?".$self->escapeHTML($ENV{QUERY_STRING},1);
+       }
     }
     $action = qq(action="$action");
     my($other) = @other ? " @other" : '';
