--- go.mod.orig	2023-03-17 14:50:00 UTC
+++ go.mod
@@ -1,23 +1,28 @@
 module github.com/mephux/komanda-cli
 
-go 1.13
+go 1.17
 
 require (
 	github.com/0xAX/notificator v0.0.0-20181105090803-d81462e38c21
 	github.com/BurntSushi/toml v0.3.1
-	github.com/alecthomas/template v0.0.0-20190718012654-fb15b899a751 // indirect
-	github.com/alecthomas/units v0.0.0-20190717042225-c3de453c63f4 // indirect
 	github.com/davecgh/go-spew v1.1.1
 	github.com/fluffle/goirc v1.0.1
-	github.com/hectane/go-attest v0.1.2 // indirect
 	github.com/hectane/go-nonblockingchan v0.1.0
 	github.com/jroimartin/gocui v0.4.0
-	github.com/mattn/go-runewidth v0.0.4 // indirect
 	github.com/mephux/common v0.0.0-20170531153046-c3a670c8b76e
 	github.com/nsf/termbox-go v0.0.0-20190817171036-93860e161317
 	github.com/sirupsen/logrus v1.4.2
 	github.com/worg/merger v0.0.0-20151129084618-94181de72ed1
-	golang.org/x/lint v0.0.0-20190909230951-414d861bb4ac // indirect
-	golang.org/x/tools v0.0.0-20190918171317-3d643c64ae6b // indirect
 	gopkg.in/alecthomas/kingpin.v2 v2.2.6
+)
+
+require (
+	github.com/alecthomas/template v0.0.0-20190718012654-fb15b899a751 // indirect
+	github.com/alecthomas/units v0.0.0-20190717042225-c3de453c63f4 // indirect
+	github.com/golang/mock v1.1.1 // indirect
+	github.com/hectane/go-attest v0.1.2 // indirect
+	github.com/konsorten/go-windows-terminal-sequences v1.0.1 // indirect
+	github.com/mattn/go-runewidth v0.0.4 // indirect
+	golang.org/x/net v0.0.0-20190620200207-3b0461eec859 // indirect
+	golang.org/x/sys v0.6.0 // indirect
 )
