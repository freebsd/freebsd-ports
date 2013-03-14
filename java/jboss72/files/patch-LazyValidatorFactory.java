--- ee/src/main/java/org/jboss/as/ee/beanvalidation/LazyValidatorFactory.java.orig	2012-11-14 23:36:12.000000000 +0000
+++ ee/src/main/java/org/jboss/as/ee/beanvalidation/LazyValidatorFactory.java	2012-09-21 12:14:04.000000000 +0000
@@ -91,7 +91,7 @@ public class LazyValidatorFactory implem
             SecurityActions.setContextClassLoader(classLoader);
             if (configuration == null) {
                 ConstraintMapping mapping = new ConstraintMapping();
-                HibernateValidatorConfiguration config = Validation.byProvider(HibernateValidator.class).providerResolver(new JbossProviderResolver()).configure();
+                HibernateValidatorConfiguration config = Validation.<HibernateValidatorConfiguration,HibernateValidator>byProvider(HibernateValidator.class).providerResolver(new JbossProviderResolver()).configure();
                 config.addMapping(mapping);
                 ValidatorFactory factory = config.buildValidatorFactory();
                 return factory;
