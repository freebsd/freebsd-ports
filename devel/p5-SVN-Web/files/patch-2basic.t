--- t/2basic.t	Sun Apr 29 23:22:51 2007
+++ t/2basic.t	Mon Dec 15 03:09:45 2008
@@ -61,6 +61,9 @@
     # a ':'.  This catches template bugs with too many slashes.
     unlike($mech->uri(), qr{(?<!:)//}, 'URI does not contain "//"');
 
+    diag('skip static files checks in local tests: '.$mech->uri), return
+        if $mech->uri->path eq '/' or $mech->uri->path =~ m{/css/};
+
     $mech->content_unlike(qr'An error occured', '  and content was correct');
     if($can_tidy 
        and ($mech->uri() !~ m{ (?:
