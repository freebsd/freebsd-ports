commit 2446514e716075cfe2be35e2a9b9de4eacdbac99
Author: Chris Novakovic <chris@chrisn.me.uk>
Date:   Tue Jun 6 23:02:59 2017 +0100

    Fix logic of appending ".<layer>" to PXE basename
    
    Commit f77700aa, which fixes a compiler warning, also breaks the
    behaviour of prepending ".<layer>" to basenames in --pxe-service: in
    situations where the basename contains a ".", the ".<layer>" suffix is
    erroneously added, and in situations where the basename doesn't contain
    a ".", the ".<layer>" suffix is erroneously omitted.
    
    A patch against the git HEAD is attached that inverts this logic and
    restores the expected behaviour of --pxe-service.

--- src/rfc2131.c.orig	2017-05-22 21:58:46 UTC
+++ src/rfc2131.c
@@ -836,10 +836,10 @@ size_t dhcp_reply(struct dhcp_context *c
 	  
 	  if (strchr(service->basename, '.'))
 	    snprintf((char *)mess->file, sizeof(mess->file),
-		"%s.%d", service->basename, layer);
+		"%s", service->basename);
 	  else
 	    snprintf((char *)mess->file, sizeof(mess->file),
-		"%s", service->basename);
+		"%s.%d", service->basename, layer);
 	  
 	  option_put(mess, end, OPTION_MESSAGE_TYPE, 1, DHCPACK);
 	  option_put(mess, end, OPTION_SERVER_IDENTIFIER, INADDRSZ, htonl(context->local.s_addr));
