--- templates/status.tpl.orig	Tue Apr 10 18:48:12 2007
+++ templates/status.tpl	Tue Apr 10 19:58:35 2007
@@ -183,7 +183,8 @@
     {/if}
 </p>
 {else}
-{$message.strStopPgpool|escape}
+  <p>{$message.strStopPgpool|escape}</p>
+  <div id="status"></div>
 {/if}
 <h2>{$message.strPgpool|escape}</h2>
     {if $pgpoolIsActive == false}
