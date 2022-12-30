--- build/unix/compiledata.sh.orig	2022-11-16 10:35:46 UTC
+++ build/unix/compiledata.sh
@@ -58,7 +58,7 @@ CXXFLAGS=`echo $CXXFLAGS | sed 's/-Iinclude //' `
 
 # Remove the flags turning warnings into errors or extending
 # the number of warnings.
-CXXFLAGS=`echo $CXXFLAGS | sed -e 's/-Werror //g' -e 's/-Werror=\S* //g' -e 's/-Wall //g' -e 's/-Wshadow //g'  `
+CXXFLAGS=`echo $CXXFLAGS | sed -e 's/-Werror //g' -e 's/-Werror=[^[[:space:]]]* //g' -e 's/-Wall //g' -e 's/-Wshadow //g'  `
 
 # Determine the compiler version
 BXX="`basename $CXX`"
