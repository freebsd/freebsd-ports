--- Premake.make.orig	Mon Mar 29 18:33:15 2004
+++ Premake.make	Mon Mar 29 18:33:35 2004
@@ -23,37 +23,21 @@
 	-@if [ ! -d obj ]; then mkdir obj; fi
 	@echo $(notdir $<)
 	@$(CXX) $(CXXFLAGS) -MD -o $@ -c $<
-	@cp obj/$*.d obj/$*.P; \
-	 sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' \
-	 -e '/^$$/ d' -e 's/$$/ :/' < obj/$*.d >> obj/$*.P; \
-	rm -f obj/$*.d
 
 obj/%.o : %.cpp
 	-@if [ ! -d obj ]; then mkdir obj; fi
 	@echo $(notdir $<)
 	@$(CXX) $(CXXFLAGS) -MD -o $@ -c $<
-	@cp obj/$*.d obj/$*.P; \
-	 sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' \
-	 -e '/^$$/ d' -e 's/$$/ :/' < obj/$*.d >> obj/$*.P; \
-	rm -f obj/$*.d
 
 obj/%.o : %.cxx
 	-@if [ ! -d obj ]; then mkdir obj; fi
 	@echo $(notdir $<)
 	@$(CXX) $(CXXFLAGS) -MD -o $@ -c $<
-	@cp obj/$*.d obj/$*.P; \
-	 sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' \
-	 -e '/^$$/ d' -e 's/$$/ :/' < obj/$*.d >> obj/$*.P; \
-	rm -f obj/$*.d
 
 obj/%.o : %.c
 	-@if [ ! -d obj ]; then mkdir obj; fi
 	@echo $(notdir $<)
 	@$(CC) $(CFLAGS) -MD -o $@ -c $<
-	@cp obj/$*.d obj/$*.P; \
-	 sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' \
-	 -e '/^$$/ d' -e 's/$$/ :/' < obj/$*.d >> obj/$*.P; \
-	rm -f obj/$*.d
 
 OBJECTS = \
 	obj/premake.o \
