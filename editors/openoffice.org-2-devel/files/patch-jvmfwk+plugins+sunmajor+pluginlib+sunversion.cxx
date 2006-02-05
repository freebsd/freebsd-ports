Issuetracker : #i56953#
CWS          : N/A
Author       : <maho@openoffice.org>
Description  : FreeBSD porting : do not hardcode pXX of Java version and FreeBSD native Java is always superior to Linux's one.

1. we had been hard coding Java's version by p1, p2 ... etc. but apparently
it is not a good habit. in this patch we eleminate this.

2. we'd better to use FreeBSD's native Java, and not GNU/Linux's ones if both are exist
in the system. We add 100 as micro version number, so that we treat FreeBSD's version of
java 1.4.1-p10 for example to 1.4.1_110.

--- jvmfwk/plugins/sunmajor/pluginlib/sunversion.cxx	Thu Sep  8 04:31:40 2005
+++ jvmfwk/plugins/sunmajor/pluginlib/sunversion.cxx	Sat Oct 22 18:25:49 2005
@@ -208,7 +208,15 @@
             return false;
 #if defined(FREEBSD)        
       if (m_preRelease == Rel_FreeBSD) {
-         m_nUpdateSpecial = *pCur;
+           pCur++; //elemnate `p'
+           if (pCur < pEnd && isdigit(*pCur))
+               pCur ++;
+           int len = pCur - pLast -1; //elemenate `p'
+		if (len >= 127)
+                   return false;
+	strncpy(buf, (pLast+1), len); //elemenate `p'
+	buf[len] = 0;
+	m_nUpdateSpecial = atoi(buf)+100; //hack for FBSD
 	return true;
       }
 #endif        
@@ -249,27 +258,7 @@
     else if (! strcmp(szRelease, "rc3"))
         return Rel_RC3;
 #if defined (FREEBSD)
-    else if (! strcmp(szRelease, "p1"))
-        return Rel_FreeBSD;
-    else if (! strcmp(szRelease, "p2"))
-        return Rel_FreeBSD;
-    else if (! strcmp(szRelease, "p3"))
-        return Rel_FreeBSD;
-    else if (! strcmp(szRelease, "p4"))
-        return Rel_FreeBSD;
-    else if (! strcmp(szRelease, "p5"))
-        return Rel_FreeBSD;
-    else if (! strcmp(szRelease, "p6"))
-        return Rel_FreeBSD;
-    else if (! strcmp(szRelease, "p7"))
-        return Rel_FreeBSD;
-    else if (! strcmp(szRelease, "p8"))
-        return Rel_FreeBSD;
-    else if (! strcmp(szRelease, "p9"))
-        return Rel_FreeBSD;
-    else if (! strcmp(szRelease, "p10"))
-        return Rel_FreeBSD;
-    else if (! strcmp(szRelease, "p11"))
+    else if (! strncmp(szRelease, "p", 1))
         return Rel_FreeBSD;
 #endif    
     else
