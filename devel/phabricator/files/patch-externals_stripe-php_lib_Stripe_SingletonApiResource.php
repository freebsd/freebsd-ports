--- externals/stripe-php/lib/Stripe/SingletonApiResource.php.orig	2021-12-18 19:11:09 UTC
+++ externals/stripe-php/lib/Stripe/SingletonApiResource.php
@@ -16,7 +16,7 @@ abstract class Stripe_SingletonApiResource extends Str
   public static function classUrl($class)
   {
     $base = self::className($class);
-    return "/v1/${base}";
+    return "/v1/{$base}";
   }
 
   /**
