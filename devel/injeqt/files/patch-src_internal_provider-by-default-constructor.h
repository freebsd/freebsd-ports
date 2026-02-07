--- src/internal/provider-by-default-constructor.h.orig	2017-04-27 17:04:46 UTC
+++ src/internal/provider-by-default-constructor.h
@@ -77,14 +77,14 @@ class INJEQT_INTERNAL_API provider_by_default_construc
 	/**
 	 * @return empty set of object - this provider does not require another object to instantiate
 	 */
-	virtual types required_types() const { return types{}; }
+	virtual types required_types() const override { return types{}; }
 
 	/**
 	 * @return true
 	 *
 	 * Objects created by injector will have its dependencies resolved.
 	 */
-	virtual bool require_resolving() const;
+	virtual bool require_resolving() const override;
 
 	/**
 	 * @return constructor object passed in constructor
