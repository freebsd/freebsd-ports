--- lib/CGI.pm.orig	Tue Sep 30 10:17:22 2003
+++ lib/CGI.pm	Tue Sep 30 10:20:20 2003
@@ -1532,8 +1532,10 @@ sub startform {
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
