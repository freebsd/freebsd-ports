--- lib/playlist_item.rb.orig	Mon Jul 10 11:30:20 2006
+++ lib/playlist_item.rb	Mon Jul 10 11:31:08 2006
@@ -1,4 +1,4 @@
-# $Id: playlist_item.rb,v 1.17 2005/12/14 20:02:14 tsauerbeck Exp $
+# $Id: playlist_item.rb,v 1.19 2006/07/08 12:25:31 tilman Exp $
 
 class PlaylistItem
 	attr_reader :id, :edje, :position, :selected, :hilighted
@@ -23,9 +23,7 @@
 	end
 
 	def method_missing(method)
-		tmp = @props[method]
-
-		tmp || @props[:server][method] || "default"
+		@props[method] || "default"
 	end
 
 	def duration
