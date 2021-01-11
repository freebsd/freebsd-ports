--- resources/linux/bin/code.sh.orig	2020-07-21 14:27:11 UTC
+++ resources/linux/bin/code.sh
@@ -4,7 +4,7 @@
 # Licensed under the MIT License. See License.txt in the project root for license information.
 
 # test that VSCode wasn't installed inside WSL
-if grep -qi Microsoft /proc/version && [ -z "$DONT_PROMPT_WSL_INSTALL" ]; then
+if grep -qi Microsoft /proc/version 2> /dev/null && [ -z "$DONT_PROMPT_WSL_INSTALL" ]; then
 	echo "To use @@PRODNAME@@ with the Windows Subsystem for Linux, please install @@PRODNAME@@ in Windows and uninstall the Linux version in WSL. You can then use the \`@@NAME@@\` command in a WSL terminal just as you would in a normal command prompt." 1>&2
 	printf "Do you want to continue anyway? [y/N] " 1>&2
 	read -r YN
