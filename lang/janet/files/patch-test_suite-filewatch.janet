--- test/suite-filewatch.janet.orig	2026-08-31 23:24:25 UTC
+++ test/suite-filewatch.janet
@@ -25,9 +25,10 @@
 
 (def chan (ev/chan 1000))
 (var is-win (or (= :mingw (os/which)) (= :windows (os/which))))
-(var is-linux (= :linux (os/which)))
-(def bsds [:freebsd :macos :openbsd :bsd :dragonfly :netbsd])
-(var is-kqueue (index-of (os/which) bsds))
+(def inotifies [:linux %INOTIFY%])
+(var is-inotify (index-of (os/which) inotifies))
+(def kqs [%KQUEUE% :macos :openbsd :bsd :dragonfly :netbsd])
+(var is-kqueue (index-of (os/which) kqs))
 
 # If not supported, exit early
 (def [supported msg] (protect (filewatch/new chan)))
@@ -95,7 +96,7 @@
 (when is-win
   (filewatch/add fw td1 :last-write :last-access :file-name :dir-name :size :attributes :recursive)
   (filewatch/add fw td2 :last-write :last-access :file-name :dir-name :size :attributes))
-(when is-linux
+(when is-inotify
   (filewatch/add fw (string td3 "/file3.txt") :close-write :create :delete)
   (filewatch/add fw td1 :close-write :create :delete)
   (filewatch/add fw td2 :close-write :create :delete :ignored))
@@ -155,7 +156,7 @@
 # Linux file writing
 #
 
-(when is-linux
+(when is-inotify
   (spit-file td1 "file1.txt")
   (expect :type :create :file-name "file1.txt" :dir-name td1)
   (expect :type :close-write)
