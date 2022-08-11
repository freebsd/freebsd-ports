--- resources/linux/bin/code.sh.orig	2022-06-08 11:20:55 UTC
+++ resources/linux/bin/code.sh
@@ -13,7 +13,7 @@ if [ -n "$VSCODE_IPC_HOOK_CLI" ]; then
 fi
 
 # test that VSCode wasn't installed inside WSL
-if grep -qi Microsoft /proc/version && [ -z "$DONT_PROMPT_WSL_INSTALL" ]; then
+if grep -qi Microsoft /proc/version 2> /dev/null && [ -z "$DONT_PROMPT_WSL_INSTALL" ]; then
 	echo "To use @@PRODNAME@@ with the Windows Subsystem for Linux, please install @@PRODNAME@@ in Windows and uninstall the Linux version in WSL. You can then use the \`@@APPNAME@@\` command in a WSL terminal just as you would in a normal command prompt." 1>&2
 	printf "Do you want to continue anyway? [y/N] " 1>&2
 	read -r YN
