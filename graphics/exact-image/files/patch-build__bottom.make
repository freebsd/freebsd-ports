--- build/bottom.make.orig	2010-07-22 18:35:17.000000000 +0400
+++ build/bottom.make	2014-12-12 00:07:13.000000000 +0300
@@ -43,23 +43,23 @@
 
 $($(X_MODULE)_OUTPUT)/%.o: $(X_MODULE)/%.c
 	@echo '  C         $@'
-	$(Q)$(COMPILE.c) $($(dir $@)CFLAGS) -MMD -MP -MF '$(patsubst %.o,%.d,$@)' -o '$@' '$<'
+	$(Q)$(COMPILE.c) ${CFLAGS} ${CPPFLAGS} $($(dir $@)CFLAGS) -MMD -MP -MF '$(patsubst %.o,%.d,$@)' -o '$@' '$<'
 
 $($(X_MODULE)_OUTPUT)/%.o: $(X_MODULE)/%.m
 	@echo '  ObjC      $@'
-	$(Q)$(COMPILE.c) $($(dir $@)CFLAGS) -MMD -MP -MF '$(patsubst %.o,%.d,$@)' -o '$@' '$<'
+	$(Q)$(COMPILE.c) ${CFLAGS} ${CPPFLAGS} $($(dir $@)CFLAGS) -MMD -MP -MF '$(patsubst %.o,%.d,$@)' -o '$@' '$<'
 
 $($(X_MODULE)_OUTPUT)/%.o: $($(X_MODULE)_OUTPUT)/%.cc
 	@echo '  C++       $@'
-	$(Q)$(COMPILE.cc) $($(dir $@)CXXFLAGS) -MMD -MP -MF '$(patsubst %.o,%.d,$@)' -o '$@' '$<'
+	$(Q)$(COMPILE.cc) ${CXXFLAGS} ${CPPFLAGS} $($(dir $@)CXXFLAGS) -MMD -MP -MF '$(patsubst %.o,%.d,$@)' -o '$@' '$<'
 
 $($(X_MODULE)_OUTPUT)/%.o: $(X_MODULE)/%.cc
 	@echo '  C++       $@'
-	$(Q)$(COMPILE.cc) $($(dir $@)CXXFLAGS) -MMD -MP -MF '$(patsubst %.o,%.d,$@)' -o '$@' '$<'
+	$(Q)$(COMPILE.cc) ${CXXFLAGS} ${CPPFLAGS} $($(dir $@)CXXFLAGS) -MMD -MP -MF '$(patsubst %.o,%.d,$@)' -o '$@' '$<'
 
 $($(X_MODULE)_OUTPUT)/%.o: $(X_MODULE)/%.mm
 	@echo '  ObjC++    $@'
-	$(Q)$(COMPILE.cc) $($(dir $@)CXXFLAGS) -MMD -MP -MF '$(patsubst %.o,%.d,$@)' -o '$@' '$<'
+	$(Q)$(COMPILE.cc) ${CXXFLAGS} ${CPPFLAGS} $($(dir $@)CXXFLAGS) -MMD -MP -MF '$(patsubst %.o,%.d,$@)' -o '$@' '$<'
 
 # only implicit rules if one binary per module ...
 ifeq ($(words $(BINARY)), 1)
