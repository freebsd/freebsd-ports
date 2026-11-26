--- share/ruby-install/ruby/dependencies.sh.orig	2026-10-25 12:30:01 UTC
+++ share/ruby-install/ruby/dependencies.sh
@@ -68,7 +68,6 @@ case "$package_manager" in
 		;;
 	pkg)
 		ruby_dependencies=(
-			openssl
 			readline
 			libyaml
 			libffi
