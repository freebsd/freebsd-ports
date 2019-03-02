--- _support/makegen.go.orig	2019-02-14 18:35:35 UTC
+++ _support/makegen.go
@@ -230,7 +230,7 @@ var templateText = `
 # These variables may be overriden at runtime by top-level make
 PREFIX ?= /usr/local
 INSTALL_DEST_DIR := $(DESTDIR)$(PREFIX)/bin/
-BUNDLE_FLAGS ?= --deployment
+BUNDLE_FLAGS ?= --local
 ASSEMBLY_ROOT ?= {{ .BuildDir }}/assembly
 BUILD_TAGS := tracer_static tracer_static_jaeger
 
@@ -251,7 +251,7 @@ build: ../.ruby-bundle
 # _build. Hence the '../' in front.
 ../.ruby-bundle:  {{ .GitalyRubyDir }}/Gemfile.lock  {{ .GitalyRubyDir }}/Gemfile
 	cd  {{ .GitalyRubyDir }} && bundle config # for debugging
-	cd  {{ .GitalyRubyDir }} && bundle install $(BUNDLE_FLAGS)
+	cd  {{ .GitalyRubyDir }} && rm Gemfile.lock && bundle install $(BUNDLE_FLAGS)
 	cd  {{ .GitalyRubyDir }} && bundle show gitaly-proto # sanity check
 	touch $@
 
