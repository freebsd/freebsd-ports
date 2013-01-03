Fix building with libxslt newer than 1.1.26.

Obtained from:	https://www.virtualbox.org/ticket/10940
--- src/VBox/Main/webservice/websrv-wsdl.xsl 2012-10-26 18:24:53.000000000 +0200
+++ src/VBox/Main/webservice/websrv-wsdl.xsl 2012-12-17 10:44:59.000001310 +0100
@@ -93,6 +93,7 @@
   targetNamespace="http://schemas.xmlsoap.org/wsdl/"
   xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
   xmlns:xsd="http://www.w3.org/2001/XMLSchema"
+  xmlns:wsdl="http://schemas.xmlsoap.org/wsdl/"
   xmlns:soap="http://schemas.xmlsoap.org/wsdl/soap/"
   xmlns:vbox="http://www.virtualbox.org/"
   xmlns:exsl="http://exslt.org/common"
@@ -460,7 +461,7 @@
   <xsl:param name="_params" />
   <xsl:param name="_valuetype" />       <!-- optional, for attribute setter messages -->
 
-  <message>
+  <wsdl:message>
     <xsl:attribute name="name"><xsl:value-of select="concat($_ifname, $G_classSeparator, $_methodname, $G_methodRequest)" /></xsl:attribute>
 
     <xsl:call-template name="convertTypeAndEmitPartOrElement">
@@ -469,10 +470,10 @@
       <xsl:with-param name="name" select="'parameters'" />
       <xsl:with-param name="type" select="$G_typeIsGlobalRequestElementMarker" />
       <xsl:with-param name="safearray" select="'no'" />
-      <xsl:with-param name="elname" select="'part'" /> <!-- "part" or "element" -->
+      <xsl:with-param name="elname" select="'wsdl:part'" /> <!-- "part" or "element" -->
       <xsl:with-param name="attrname" select="'element'" />   <!-- attrib of part of element: <part type=...> or <part element=...> or <element type=...> -->
     </xsl:call-template>
-  </message>
+  </wsdl:message>
 </xsl:template>
 
 <!--
@@ -485,7 +486,7 @@
   <xsl:param name="_params" />          <!-- set of parameter elements -->
   <xsl:param name="_resulttype" />      <!-- for attribute getter methods only -->
 
-  <message>
+  <wsdl:message>
     <xsl:attribute name="name"><xsl:copy-of select="$_ifname" /><xsl:value-of select="$G_classSeparator" /><xsl:value-of select="$_methodname" /><xsl:copy-of select="$G_methodResponse" /></xsl:attribute>
 
     <!-- <xsl:variable name="cOutParams" select="count($_params[@dir='out']) + count($_params[@dir='return'])" /> -->
@@ -495,10 +496,10 @@
       <xsl:with-param name="name" select="'parameters'" />
       <xsl:with-param name="type" select="$G_typeIsGlobalResponseElementMarker" />
       <xsl:with-param name="safearray" select="'no'" />
-      <xsl:with-param name="elname" select="'part'" /> <!-- "part" or "element" -->
+      <xsl:with-param name="elname" select="'wsdl:part'" /> <!-- "part" or "element" -->
       <xsl:with-param name="attrname" select="'element'" />   <!-- attrib of part of element: <part type=...> or <part element=...> or <element type=...> -->
     </xsl:call-template>
-  </message>
+  </wsdl:message>
 </xsl:template>
 
 <!--
@@ -543,13 +544,13 @@
     <xsl:with-param name="_methodname" select="$attrSetter" />
     <xsl:with-param name="_params" select="/.." /> <!-- empty set -->
     <xsl:with-param name="_valuetype" select="$attrtype" />
-    <xsl:with-param name="elname" select="'part'" /> <!-- "part" or "element" -->
+    <xsl:with-param name="elname" select="'wsdl:part'" /> <!-- "part" or "element" -->
   </xsl:call-template>
   <xsl:call-template name="emitResultMessage">
     <xsl:with-param name="_ifname" select="$ifname" />
     <xsl:with-param name="_methodname" select="$attrSetter" />
     <xsl:with-param name="_params" select="/.." /> <!-- empty set -->
-    <xsl:with-param name="elname" select="'part'" /> <!-- "part" or "element" -->
+    <xsl:with-param name="elname" select="'wsdl:part'" /> <!-- "part" or "element" -->
   </xsl:call-template>
 </xsl:template>
 
@@ -566,7 +567,7 @@
 
   <xsl:call-template name="debugMsg"><xsl:with-param name="msg" select="concat('....emitInOutOperation ', $_ifname, '::', $_methodname)" /></xsl:call-template>
 
-  <operation>
+  <wsdl:operation>
     <xsl:attribute name="name">
       <xsl:value-of select="concat($_ifname, '_', $_methodname)" />
     </xsl:attribute>
@@ -577,7 +578,7 @@
         <xsl:attribute name="style"><xsl:value-of select="$G_basefmt" /></xsl:attribute>
       </soap:operation>
     </xsl:if>
-    <input>
+    <wsdl:input>
       <xsl:choose>
         <xsl:when test="$_fSoap">
           <soap:body>
@@ -589,10 +590,10 @@
           <xsl:attribute name="message">vbox:<xsl:copy-of select="$_ifname" /><xsl:value-of select="$G_classSeparator" /><xsl:value-of select="$_methodname" /><xsl:copy-of select="$G_methodRequest" /></xsl:attribute>
         </xsl:otherwise>
       </xsl:choose>
-    </input>
+    </wsdl:input>
     <xsl:choose>
       <xsl:when test="$_resulttype">
-        <output>
+        <wsdl:output>
           <xsl:choose>
             <xsl:when test="$_fSoap">
               <soap:body>
@@ -604,11 +605,11 @@
               <xsl:attribute name="message">vbox:<xsl:copy-of select="$_ifname" /><xsl:value-of select="$G_classSeparator" /><xsl:value-of select="$_methodname" /><xsl:copy-of select="$G_methodResponse" /></xsl:attribute>
             </xsl:otherwise>
           </xsl:choose>
-        </output>
+        </wsdl:output>
       </xsl:when>
       <xsl:otherwise>
         <!-- <xsl:if test="count($_params[@dir='out'] | $_params[@dir='return']) > 0"> -->
-          <output>
+          <wsdl:output>
             <xsl:choose>
               <xsl:when test="$_fSoap">
                 <soap:body>
@@ -620,29 +621,29 @@
                 <xsl:attribute name="message">vbox:<xsl:copy-of select="$_ifname" /><xsl:value-of select="$G_classSeparator" /><xsl:value-of select="$_methodname" /><xsl:copy-of select="$G_methodResponse" /></xsl:attribute>
               </xsl:otherwise>
             </xsl:choose>
-          </output>
+          </wsdl:output>
         <!-- </xsl:if> -->
       </xsl:otherwise>
     </xsl:choose>
     <xsl:choose>
       <xsl:when test="not($_fSoap)">
-        <fault name="InvalidObjectFault" message="vbox:InvalidObjectFaultMsg" />
-        <fault name="RuntimeFault" message="vbox:RuntimeFaultMsg" />
+        <wsdl:fault name="InvalidObjectFault" message="vbox:InvalidObjectFaultMsg" />
+        <wsdl:fault name="RuntimeFault" message="vbox:RuntimeFaultMsg" />
       </xsl:when>
       <xsl:otherwise>
-        <fault name="InvalidObjectFault">
+        <wsdl:fault name="InvalidObjectFault">
           <soap:fault name="InvalidObjectFault">
             <xsl:attribute name="use"><xsl:value-of select="$G_parmfmt" /></xsl:attribute>
           </soap:fault>
-        </fault>
-        <fault name="RuntimeFault">
+        </wsdl:fault>
+        <wsdl:fault name="RuntimeFault">
           <soap:fault name="RuntimeFault">
             <xsl:attribute name="use"><xsl:value-of select="$G_parmfmt" /></xsl:attribute>
           </soap:fault>
-        </fault>
+        </wsdl:fault>
       </xsl:otherwise>
     </xsl:choose>
-  </operation>
+  </wsdl:operation>
 </xsl:template>
 
 <!--
@@ -742,7 +743,7 @@
             <xsl:with-param name="_wsmap" select="$wsmap" />
             <xsl:with-param name="_methodname" select="$methodname" />
             <xsl:with-param name="_params" select="param" />
-            <xsl:with-param name="elname" select="'part'" /> <!-- "part" or "element" -->
+            <xsl:with-param name="elname" select="'wsdl:part'" /> <!-- "part" or "element" -->
           </xsl:call-template>
           <!-- emit a second "result" message only if the method has "out" arguments or a return value -->
           <!-- <xsl:if test="(count(param[@dir='out'] | param[@dir='return']) > 0)"> -->
@@ -751,7 +752,7 @@
               <xsl:with-param name="_wsmap" select="$wsmap" />
               <xsl:with-param name="_methodname" select="@name" />
               <xsl:with-param name="_params" select="param" />
-              <xsl:with-param name="elname" select="'part'" /> <!-- "part" or "element" -->
+              <xsl:with-param name="elname" select="'wsdl:part'" /> <!-- "part" or "element" -->
             </xsl:call-template>
           <!-- </xsl:if> -->
         </xsl:otherwise>
@@ -956,10 +957,9 @@
     and emit complexTypes for all method arguments and return values.
 -->
 <xsl:template match="library">
-  <definitions
+  <wsdl:definitions
         name="VirtualBox"
         xmlns:wsdl="http://schemas.xmlsoap.org/wsdl/">
-    <xsl:attribute name="xmlns">http://schemas.xmlsoap.org/wsdl/</xsl:attribute>
     <xsl:attribute name="targetNamespace"><xsl:value-of select="$G_targetNamespace" /></xsl:attribute>
     <!-- at top of WSDL file, dump a <types> section with user-defined types -->
       <xsl:comment>
@@ -969,7 +969,7 @@
   *
   ******************************************************
 </xsl:comment>
-    <types>
+    <wsdl:types>
       <xsd:schema>
         <xsl:attribute name="targetNamespace"><xsl:value-of select='$G_targetNamespace' /></xsl:attribute>
 
@@ -1193,14 +1193,14 @@
       </xsd:schema>
 
 
-    </types>
+    </wsdl:types>
 
-    <message name="InvalidObjectFaultMsg">
-      <part name="fault" element="vbox:InvalidObjectFault" />
-    </message>
-    <message name="RuntimeFaultMsg">
-      <part name="fault" element="vbox:RuntimeFault" />
-    </message>
+    <wsdl:message name="InvalidObjectFaultMsg">
+      <wsdl:part name="fault" element="vbox:InvalidObjectFault" />
+    </wsdl:message>
+    <wsdl:message name="RuntimeFaultMsg">
+      <wsdl:part name="fault" element="vbox:RuntimeFault" />
+    </wsdl:message>
 
     <xsl:comment>
   ******************************************************
@@ -1241,7 +1241,7 @@
       ******************************************************
     </xsl:comment>
 
-    <portType>
+    <wsdl:portType>
       <xsl:attribute name="name"><xsl:copy-of select="'vbox'" /><xsl:value-of select="$G_portTypeSuffix" /></xsl:attribute>
 
       <xsl:for-each select="//interface">
@@ -1261,7 +1261,7 @@
           </xsl:call-template>
         </xsl:if>
       </xsl:for-each>
-    </portType>
+    </wsdl:portType>
 
     <xsl:comment>
       ******************************************************
@@ -1271,7 +1271,7 @@
       ******************************************************
     </xsl:comment>
 
-    <binding>
+    <wsdl:binding>
       <xsl:attribute name="name"><xsl:value-of select="concat('vbox', $G_bindingSuffix)" /></xsl:attribute>
       <xsl:attribute name="type"><xsl:value-of select="concat('vbox:vbox', $G_portTypeSuffix)" /></xsl:attribute>
 
@@ -1297,9 +1297,9 @@
           </xsl:call-template>
         </xsl:if>
       </xsl:for-each>
-    </binding>
+    </wsdl:binding>
 
-  </definitions>
+  </wsdl:definitions>
 </xsl:template>
