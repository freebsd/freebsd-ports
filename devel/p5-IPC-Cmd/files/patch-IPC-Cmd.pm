$Id$

--- lib/IPC/Cmd.pm.orig	Sat Dec  2 15:55:55 2006
+++ lib/IPC/Cmd.pm	Sat Dec  2 15:56:52 2006
@@ -597,7 +597,7 @@ sub _system_run { 
             ### we should re-open this filehandle right now, not
             ### just dup it
             if( $redir eq '>&' ) {
-                open( $fh, '>', File::Spec->devnull ) or (
+                open( $fh, '> ' . File::Spec->devnull ) or (
                     Carp::carp(loc("Could not reopen '$name': %1", $!)),
                     return
                 );
