--- kioslaves/imap4/mimeheader.cc	2005/07/26 18:54:59	438982
+++ kioslaves/imap4/mimeheader.cc	2007/03/28 21:58:46	647617
@@ -339,35 +339,47 @@
     {
       val = rfcDecoder::encodeRFC2231String (aValue);
     }
+    //kdDebug(7116) << "mimeHeader::setParameter() - val = '" << val << "'" << endl;
     //see if it needs to be truncated
     vlen = val.length();
     llen = aLabel.length();
-    if (vlen + llen + 4 > 80 && llen < 80 - 8 )
+    if (vlen + llen + 4 > 80 && llen < 80 - 8 - 2 )
     {
-      int limit = 80 - 8 - (int)llen;
+      const int limit = 80 - 8 - 2 - (int)llen;
+      // the -2 is there to allow extending the length of a part of val
+      // by 1 or 2 in order to prevent an encoded character from being
+      // split in half
       int i = 0;
       QString shortValue;
       QCString shortLabel;
 
       while (!val.isEmpty ())
       {
-        //don't truncate the encoded chars
-        int offset = 0;
-        if (limit > int(vlen))
-          limit = vlen;
-        offset = val.findRev ('%', limit);
-        if (offset == limit - 1 || offset == limit - 2)
-        {
-//          cout << "offset " << offset << "-" << limit << "=" << limit-offset << endl;
-          offset = limit - offset;
+        int partLen; // the length of the next part of the value
+        if ( limit >= int(vlen) ) {
+          // the rest of the value fits completely into one continued header
+          partLen = vlen;
+        }
+        else {
+          partLen = limit;
+          // make sure that we don't split an encoded char in half
+          if ( val[partLen-1] == '%' ) {
+            partLen += 2;
+          }
+          else if ( partLen > 1 && val[partLen-2] == '%' ) {
+            partLen += 1;
+          }
+          // make sure partLen does not exceed vlen (could happen in case of
+          // an incomplete encoded char)
+          if ( partLen > int(vlen) ) {
+            partLen = vlen;
+          }
         }
-        else
-          offset = 0;
-        shortValue = val.left (limit - offset);
+        shortValue = val.left( partLen );
         shortLabel.setNum (i);
         shortLabel = aLabel + "*" + shortLabel;
-        val = val.right (vlen - limit + offset);
-        vlen = vlen - limit + offset;
+        val = val.right( vlen - partLen );
+        vlen = vlen - partLen;
         if (encoded)
         {
           if (i == 0)
@@ -376,7 +388,9 @@
           }
           shortLabel += "*";
         }
-//        cout << shortLabel << "-" << shortValue << endl;
+        //kdDebug(7116) << "mimeHeader::setParameter() - shortLabel = '" << shortLabel << "'" << endl;
+        //kdDebug(7116) << "mimeHeader::setParameter() - shortValue = '" << shortValue << "'" << endl;
+        //kdDebug(7116) << "mimeHeader::setParameter() - val        = '" << val << "'" << endl;
         aDict->insert (shortLabel, new QString (shortValue));
         i++;
       }
