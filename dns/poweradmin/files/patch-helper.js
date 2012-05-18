--- inc/helper.js.orig	2011-05-30 12:32:41.799768002 +0300
+++ inc/helper.js	2011-05-30 12:35:03.911768000 +0300
@@ -47,3 +47,52 @@
 		field_area.innerHTML += "<li><input name='domain[]' id='"+(field+count)+"' type='text' class='input' /> <a onclick=\"this.parentNode.parentNode.removeChild(this.parentNode);\">Remove Field</a></li>";
 	}
 }
+
+function getDomainsElements(){
+    var
+        coll=document.getElementsByTagName('input'),
+        re=/^domain\[\]$/,
+        t,
+        elm,
+        i=0,
+        key=0,
+        records=new Array();
+
+    while(elm=coll.item(i++))
+    {
+            t=re.exec(elm.name);
+            if(t!=null)
+              {
+                records[key]=elm;
+                key++;
+              }
+    }
+    return records;
+}
+
+function checkDomainFilled(){
+    var
+        domains= new Array(),
+        allEmpty=true,
+        domains=getDomainsElements();
+
+    if (domains.length == 1) {
+        if ((domains[0].value.length == 0 || domains[0].value == null || domains[0].value == "")) {
+            alert('Zone name cannot be empty');
+            return false;
+        }
+    } else {
+        for (key in domains) {
+            if((domains[key].value.length != 0)) {
+                allEmpty = false;
+            }
+        }
+
+        if (true === allEmpty) {
+          alert('Please fill in at least one Zone name');
+          return false;
+        }
+    }
+
+    add_zone_master.submit();
+}
