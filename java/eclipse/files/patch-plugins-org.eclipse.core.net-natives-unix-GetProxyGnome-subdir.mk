--- plugins/org.eclipse.core.net/natives/unix/GetProxyGnome/subdir.mk.orig	2009-02-15 13:45:15.836444551 -0500
+++ plugins/org.eclipse.core.net/natives/unix/GetProxyGnome/subdir.mk	2009-02-15 19:33:53.177979019 -0500
@@ -17,7 +17,7 @@
 %.o: ../%.c
 	@echo 'Building file: $<'
 	@echo 'Invoking: GCC C Compiler'
-	gcc -I/usr/include/gconf/2 -I/usr/include/orbit-2.0 -I/usr/include/glib-2.0 -I/usr/lib/glib-2.0/include/ -O0 -fPIC -g3 -Wall -c -fmessage-length=0 -m32 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
+	@gcc -I${JAVA_HOME}/include -I${JAVA_HOME}/include/freebsd -I${LOCALBASE}/include/gconf/2 -I${LOCALBASE}/include/orbit-2.0 -I${LOCALBASE}/include/glib-2.0 -O0 -fPIC -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
 	@echo 'Finished building: $<'
 	@echo ' '
 
