--- _support/makegen.go.orig	2018-11-23 11:12:56 UTC
+++ _support/makegen.go
@@ -225,7 +225,7 @@ var templateText = `
 # These variables may be overriden at runtime by top-level make
 PREFIX ?= /usr/local
 INSTALL_DEST_DIR := $(DESTDIR)$(PREFIX)/bin/
-BUNDLE_FLAGS ?= --deployment
+BUNDLE_FLAGS ?= --local
 ASSEMBLY_ROOT ?= {{ .BuildDir }}/assembly
 
 unexport GOROOT
@@ -245,7 +245,7 @@ build: ../.ruby-bundle
 # _build. Hence the '../' in front.
 ../.ruby-bundle: {{ .SourceDir }}/ruby/Gemfile.lock {{ .SourceDir }}/ruby/Gemfile
 	cd {{ .SourceDir }}/ruby && bundle config # for debugging
-	cd {{ .SourceDir }}/ruby && bundle install $(BUNDLE_FLAGS)
+	cd {{ .SourceDir }}/ruby && rm Gemfile.lock && bundle install $(BUNDLE_FLAGS)
 	cd {{ .SourceDir }}/ruby && bundle show gitaly-proto # sanity check
 	touch $@
 
