--- connector/src/main/java/org/jboss/as/connector/util/JCAValidatorFactory.java.orig	2012-11-14 23:35:33.000000000 +0000
+++ connector/src/main/java/org/jboss/as/connector/util/JCAValidatorFactory.java	2012-09-21 12:14:04.000000000 +0000
@@ -92,7 +92,7 @@ public class JCAValidatorFactory impleme
             if (configuration == null) {
                 ConstraintMapping mapping = new ConstraintMapping();
                 HibernateValidatorConfiguration config =
-                    Validation.byProvider(HibernateValidator.class).providerResolver(new JBossProviderResolver()).configure();
+                    Validation.<HibernateValidatorConfiguration,HibernateValidator>byProvider(HibernateValidator.class).providerResolver(new JBossProviderResolver()).configure();
                 config.addMapping(mapping);
                 ValidatorFactory factory = config.buildValidatorFactory();
                 return factory;
