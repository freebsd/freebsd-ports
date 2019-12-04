--- config/libxml2.m4.orig	2019-12-04 11:56:24 UTC
+++ config/libxml2.m4
@@ -41,7 +41,7 @@ AC_ARG_ENABLE(xmltest,
     no_xml=yes
   else
     XML_CPPFLAGS=`$XML2_CONFIG $xml_config_args --cflags`
-    XML_LIBS=`$XML2_CONFIG $xml_config_args --libs`
+    XML_LIBS=`$XML2_CONFIG $xml_config_args --libs | sed 's|-L/usr/lib||g'`
     xml_config_major_version=`$XML2_CONFIG $xml_config_args --version | \
            sed 's/\([[0-9]]*\).\([[0-9]]*\).\([[0-9]]*\)/\1/'`
     xml_config_minor_version=`$XML2_CONFIG $xml_config_args --version | \
