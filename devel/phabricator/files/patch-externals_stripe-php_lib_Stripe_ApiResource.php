--- externals/stripe-php/lib/Stripe/ApiResource.php.orig	2021-12-18 19:11:09 UTC
+++ externals/stripe-php/lib/Stripe/ApiResource.php
@@ -59,7 +59,7 @@ abstract class Stripe_ApiResource extends Stripe_Objec
   public static function classUrl($class)
   {
     $base = self::_scopedLsb($class, 'className', $class);
-    return "/v1/${base}s";
+    return "/v1/{$base}s";
   }
 
   /**
