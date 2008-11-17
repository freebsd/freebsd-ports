# Install into the system root by default
GNUSTEP_INSTALLATION_DOMAIN=SYSTEM
RPM_DISABLE_RELOCATABLE=YES

include $(GNUSTEP_MAKEFILES)/common.make

PACKAGE_NAME = MDFinder
VERSION = 0.1

APP_NAME = MDFinder
MDFinder_PRINCIPAL_CLASS = MDFinder
MDFinder_APPLICATION_ICON=MDFinder.tiff

MDFinder_HAS_RESOURCE_BUNDLE = yes

MDFinder_RESOURCE_FILES = \
    Resources/Images/* \
    Resources/English.lproj 

MDFinder_LANGUAGES = Resources/English 

# The Objective-C source files to be compiled

MDFinder_OBJC_FILES = main.m \
                  MDFinder.m 

ADDITIONAL_GUI_LIBS += -lMDKit
ADDITIONAL_GUI_LIBS += -lFSNode
                  				 
-include GNUmakefile.preamble

-include GNUmakefile.local

include $(GNUSTEP_MAKEFILES)/application.make

-include GNUmakefile.postamble
