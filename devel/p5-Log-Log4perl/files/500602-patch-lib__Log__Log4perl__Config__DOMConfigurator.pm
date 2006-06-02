--- ./lib/Log/Log4perl/Config/DOMConfigurator.pm.orig	Thu Jun  1 23:08:48 2006
+++ ./lib/Log/Log4perl/Config/DOMConfigurator.pm	Thu Jun  1 23:09:44 2006
@@ -61,6 +61,7 @@
     my $config = $doc->getElementsByTagName("$LOG4J_PREFIX:configuration")->item(0)||
                  $doc->getElementsByTagName("$LOG4PERL_PREFIX:configuration")->item(0);
 
+    use utf8;
     my $threshold = uc(subst($config->getAttribute('threshold')));
     if ($threshold) {
         $l4p_tree->{threshold}{value} = $threshold;
