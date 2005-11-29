--- ext/extmk.rb	6 Feb 2005 15:13:50 -0000	1.44.2.8
+++ ext/extmk.rb	2 Mar 2005 10:53:20 -0000	1.44.2.9
@@ -157,6 +157,10 @@ def parse_args()
     grep(/\A-(?!-).*#{'%c' % flag}/i) { return true }
     false
   end
+  def $mflags.defined?(var)
+    grep(/\A#{var}=(.*)/) {return $1}
+    false
+  end
 
   if $mflags.set?(?n)
     $dryrun = true
@@ -165,7 +169,10 @@ def parse_args()
   end
 
   $continue = $mflags.set?(?k)
-  $mflags |= ["DESTDIR=#{$destdir}"]
+  if !$destdir.to_s.empty?
+    $destdir = File.expand_path($destdir)
+    $mflags.defined?("DESTDIR") or $mflags << "DESTDIR=#{$destdir}"
+  end
 end
 
 parse_args()
