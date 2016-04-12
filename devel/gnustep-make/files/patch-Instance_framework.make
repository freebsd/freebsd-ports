--- Instance/framework.make	2016-03-18 10:56:04.192482000 -0500
+++ Instance/framework.make	2016-03-18 10:56:59.215696000 -0500
@@ -493,7 +493,7 @@
 	echo "@end" >> $@; \
 	echo "@implementation $(DUMMY_FRAMEWORK)" >> $@; \
 	echo "+ (NSString *)frameworkEnv { return nil; }" >> $@; \
-	echo "+ (NSString *)frameworkPath { return @\"$(FRAMEWORK_INSTALL_DIR)\"; }" >> $@; \
+	echo "+ (NSString *)frameworkPath { return @\"$(GNUSTEP_$(GNUSTEP_INSTALLATION_DOMAIN)_FRAMEWORKS)\"; }" >> $@; \
 	echo "+ (NSString *)frameworkVersion { return @\"$(CURRENT_VERSION_NAME)\"; }" >> $@; \
 	echo "static NSString *allClasses[] = {$$classlist};" >> $@; \
 	echo "+ (NSString *const*)frameworkClasses { return allClasses; }" >> $@;\
