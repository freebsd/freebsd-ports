--- makefiles/src/subdir.mk.orig	2012-12-02 20:22:54.000000000 +0400
+++ makefiles/src/subdir.mk	2012-12-13 01:07:24.472933242 +0400
@@ -71,7 +71,7 @@
 src/%.o: ../src/%.cpp
 	@echo 'Building file: $<'
 	@echo 'Invoking: GCC C++ Compiler'
-	g++ -O2 -ffast-math -Wall -c -fmessage-length=0 `pkg-config --cflags gtk+-2.0 gthread-2.0;` -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
+	$(CXX) $(CXXFLAGS) -ffast-math -Wall -c -fmessage-length=0 `pkg-config --cflags gtk+-2.0 gthread-2.0;` -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
 	@echo 'Finished building: $<'
 	@echo ' '
 
