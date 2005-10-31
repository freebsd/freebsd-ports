Issuetracker : #iXXXXX#
CWS          : N/A
Author       : <maho@openoffice.org>
Description  : FreeBSD porting : do not hardcode pXX of Java version and FreeBSD native Java is always superior to Linux's one.

1. we had been hard coding Java's version by p1, p2 ... etc. but apparently
it is not a good habit. in this patch we eleminate this.

2. we'd better to use FreeBSD's native Java, and not GNU/Linux's ones if both are exist
in the system. We add 100 as micro version number, so that we treat FreeBSD's version of
java 1.4.1-p10 for example to 1.4.1_110.

--- jvmaccess/source/sunversion.cxx	Thu Jun 16 21:45:26 2005
+++ jvmaccess/source/sunversion.cxx	Sat Oct 22 16:42:01 2005
@@ -246,30 +247,22 @@
             m_preRelease = Rel_RC2;
 #if defined FREEBSD || defined NETBSD
 	// #i40617# and #i21615#: FreeBSD adds p1-p12 to their JDK port.
-        else if (! strcmp(pCur, "p12"))
-            m_preRelease = Rel_BETA;
-        else if (! strcmp(pCur, "p11"))
-            m_preRelease = Rel_BETA;
-        else if (! strcmp(pCur, "p10"))
-            m_preRelease = Rel_BETA;
-        else if (! strcmp(pCur, "p9"))
-            m_preRelease = Rel_BETA;
-        else if (! strcmp(pCur, "p8"))
-            m_preRelease = Rel_BETA;
-        else if (! strcmp(pCur, "p7"))
-            m_preRelease = Rel_BETA;
-        else if (! strcmp(pCur, "p6"))
-            m_preRelease = Rel_BETA;
-        else if (! strcmp(pCur, "p5"))
-            m_preRelease = Rel_BETA;
-        else if (! strcmp(pCur, "p4"))
-            m_preRelease = Rel_BETA;
-        else if (! strcmp(pCur, "p3"))
-            m_preRelease = Rel_BETA;
-        else if (! strcmp(pCur, "p2"))
-            m_preRelease = Rel_BETA;
-        else if (! strcmp(pCur, "p1"))
-            m_preRelease = Rel_BETA;
+        else if (!strncmp(pCur,"p",1)) //must be p[1-9]*
+	  {
+	    pCur++; //elemnate `p'
+            if (pCur < pEnd && isdigit(*pCur))
+            {
+                if (pCur < pEnd)
+                    pCur ++;
+            }
+                int len = pCur - pLast -1; //elemenate `p'
+                if (len >= 127) 
+                    return false;
+                strncpy(buf, (pLast+1), len); //elemenate `p'
+                buf[len] = 0;
+              //temporal hack we should use BSD's JDK...
+                m_arVersionParts[nPart] = atoi(buf)+100;
+	  }
 #endif
         else
             return false;
