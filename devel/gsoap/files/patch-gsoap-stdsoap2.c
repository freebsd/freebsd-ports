--- gsoap/stdsoap2.c.orig
+++ gsoap/stdsoap2.c
@@ -809,7 +809,7 @@ soap_flush_raw(struct soap *soap, const char *s, size_t n)
 #ifndef WITH_LEANER
   if ((soap->mode & SOAP_IO) == SOAP_IO_CHUNK)
   { char t[16];
-    sprintf(t, "\r\n%lX\r\n" + (soap->chunksize ? 0 : 2), (unsigned long)n);
+    sprintf(t, &"\r\n%lX\r\n"[soap->chunksize ? 0 : 2], (unsigned long)n);
     DBGMSG(SENT, t, strlen(t));
     if ((soap->error = soap->fsend(soap, t, strlen(t))))
       return soap->error;
@@ -9534,7 +9534,8 @@ soap_element_start_end_out(struct soap *soap, const char *tag)
     }
     for (np = soap->nlist; np; np = np->next)
     { if (np->index == 1 && np->ns)
-      { sprintf(soap->tmpbuf, *(np->id) ? "xmlns:%s" : "xmlns", np->id);
+      {
+        sprintf(soap->tmpbuf, *(np->id) ? "xmlns:%s" : "xmlns%s", *(np->id) ? np->id : "");
         DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Enabling utilized binding (level=%u) %s='%s'\n", np->level, soap->tmpbuf, np->ns));
         soap_set_attr(soap, soap->tmpbuf, np->ns, 1);
         np->index = 2;
@@ -11635,7 +11636,7 @@ SOAP_FMAC1
 const char*
 SOAP_FMAC2
 soap_LONG642s(struct soap *soap, LONG64 n)
-{ sprintf(soap->tmpbuf, SOAP_LONG_FORMAT, n);
+{ sprintf(soap->tmpbuf, SOAP_LONG_FORMAT, (long long) (n));
   return soap->tmpbuf;
 }
 #endif
@@ -12453,7 +12454,7 @@ SOAP_FMAC1
 const char*
 SOAP_FMAC2
 soap_ULONG642s(struct soap *soap, ULONG64 n)
-{ sprintf(soap->tmpbuf, SOAP_ULONG_FORMAT, n);
+{ sprintf(soap->tmpbuf, SOAP_ULONG_FORMAT, (unsigned long long) (n));
   return soap->tmpbuf;
 }
 #endif
