--- src/future/FutureProxy.php.orig	2022-05-17 23:20:14 UTC
+++ src/future/FutureProxy.php
@@ -8,7 +8,7 @@ abstract class FutureProxy extends Future {
 
   private $proxied;
 
-  public function __construct(Future $proxied = null) {
+  public function __construct(?Future $proxied = null) {
     if ($proxied) {
       $this->setProxiedFuture($proxied);
     }
