--- node_modules/github/bin/linux-ssh-wrapper.sh.orig	2020-02-15 07:03:49 UTC
+++ node_modules/github/bin/linux-ssh-wrapper.sh
@@ -26,5 +26,5 @@ if type setsid >/dev/null 2>&1; then
   setsid ${SSH_CMD} "${@:-}"
 else
   log "no setsid available. SSH prompts may appear on a tty."
-  sh -c "${SSH_CMD} ${@:-}"
+  ${SSH_CMD} "${@:-}"
 fi
