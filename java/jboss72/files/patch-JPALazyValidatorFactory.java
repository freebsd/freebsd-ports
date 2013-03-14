--- jpa/core/src/main/java/org/jboss/as/jpa/validator/JPALazyValidatorFactory.java.orig	2012-11-15 00:06:15.000000000 +0000
+++ jpa/core/src/main/java/org/jboss/as/jpa/validator/JPALazyValidatorFactory.java	2012-09-21 12:14:04.000000000 +0000
@@ -78,7 +78,7 @@ public class JPALazyValidatorFactory imp
         try {
             SecurityActions.setContextClassLoader(oldTCCL);
             ConstraintMapping mapping = new ConstraintMapping();
-            HibernateValidatorConfiguration config = Validation.byProvider(HibernateValidator.class).providerResolver(new JbossProviderResolver()).configure();
+            HibernateValidatorConfiguration config = Validation.<HibernateValidatorConfiguration,HibernateValidator>byProvider(HibernateValidator.class).providerResolver(new JbossProviderResolver()).configure();
             config.addMapping(mapping);
             ValidatorFactory factory = config.buildValidatorFactory();
             return factory;
