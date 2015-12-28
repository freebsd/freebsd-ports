# Bug 1235270 - Set submitter_id before calling _check_data()
# https://bugzilla.mozilla.org/show_bug.cgi?id=1235270
# Status: Upstreamed, pending next release

--- Bugzilla/Attachment.pm.orig	2015-12-22 21:22:10 UTC
+++ Bugzilla/Attachment.pm
@@ -865,6 +865,8 @@ sub create {
 sub run_create_validators {
     my ($class, $params) = @_;
 
+    $params->{submitter_id} = Bugzilla->user->id || ThrowUserError('invalid_user');
+
     # Let's validate the attachment content first as it may
     # alter some other attachment attributes.
     $params->{data} = $class->_check_data($params);
@@ -872,7 +874,6 @@ sub run_create_validators {
 
     $params->{creation_ts} ||= Bugzilla->dbh->selectrow_array('SELECT LOCALTIMESTAMP(0)');
     $params->{modification_time} = $params->{creation_ts};
-    $params->{submitter_id} = Bugzilla->user->id || ThrowUserError('invalid_user');
 
     return $params;
 }
