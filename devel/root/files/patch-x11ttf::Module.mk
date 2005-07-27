*** x11ttf/Module.mk.orig	Sun Jul 10 14:47:12 2005
--- x11ttf/Module.mk	Sun Jul 10 14:47:31 2005
***************
*** 40,46 ****
  		@$(MAKELIB) $(PLATFORM) $(LD) "$(LDFLAGS)" \
  		   "$(SOFLAGS)" libGX11TTF.$(SOEXT) $@ \
  		   "$(X11TTFO) $(X11TTFDO)" \
! 		   "$(FREETYPELDLFAGS) $(FREETYPELIB) $(X11TTFLIBEXTRA) $(XLIBS)"
  
  $(X11TTFDS):    $(X11TTFH) $(X11TTFL) $(ROOTCINTTMP)
  		@echo "Generating dictionary $@..."
--- 40,46 ----
  		@$(MAKELIB) $(PLATFORM) $(LD) "$(LDFLAGS)" \
  		   "$(SOFLAGS)" libGX11TTF.$(SOEXT) $@ \
  		   "$(X11TTFO) $(X11TTFDO)" \
! 		   "$(FREETYPELDFLAGS) $(FREETYPELIB) $(X11TTFLIBEXTRA) $(XLIBS)"
  
  $(X11TTFDS):    $(X11TTFH) $(X11TTFL) $(ROOTCINTTMP)
  		@echo "Generating dictionary $@..."
