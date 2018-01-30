--- src/gapps/auditservice.cs.orig	2018-01-21 06:35:28 UTC
+++ src/gapps/auditservice.cs
@@ -18,6 +18,7 @@ using System.Collections.Generic;
 using System.Web;
 using Google.GData.Extensions.Apps;
 using Google.GData.Client;
+using HttpUtility = Google.GData.Client.HttpUtility;
 
 namespace Google.GData.Apps {
     /// <summary>
