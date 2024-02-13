commit 30bced3a67
Author: Philippe Blain <levraiphilippeblain@gmail.com>
Date:   Thu Feb 1 21:18:33 2024

    imap-send: add missing "strbuf.h" include under NO_CURL
    
    Building with NO_CURL is currently broken since imap-send.c uses things
    defined in "strbuf.h" wihtout including it.
    
    The inclusion of that header was removed in eea0e59ffb (treewide: remove
    unnecessary includes in source files, 2023-12-23), which failed to
    notice that "strbuf.h" was transitively included in imap-send.c via
    "http.h", but only if USE_CURL_FOR_IMAP_SEND is defined. Add back the
    missing include. Note that it was explicitely added in 3307f7dde2
    (imap-send: include strbuf.h, 2023-05-17) after a similar breakage in
    ba3d1c73da (treewide: remove unnecessary cache.h includes, 2023-02-24) -
    see the thread starting at [1].
    
    It can be verified by inspection that this is the only case where a
    header we include is dependent on a Makefile knob in the files modified
    in eea0e59ffb.
    
    [1] https://lore.kernel.org/git/20230517070632.71884-1-list@eworm.de/
    
    Signed-off-by: Philippe Blain <levraiphilippeblain@gmail.com>
    Signed-off-by: Junio C Hamano <gitster@pobox.com>

diff --git imap-send.c imap-send.c
index 904cb23cf5..9b1806a285 100644
--- imap-send.c
+++ imap-send.c
@@ -28,6 +28,7 @@
 #include "run-command.h"
 #include "parse-options.h"
 #include "setup.h"
+#include "strbuf.h"
 #if defined(NO_OPENSSL) && !defined(HAVE_OPENSSL_CSPRNG)
 typedef void *SSL;
 #endif
