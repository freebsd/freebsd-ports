# GNU Makefile wrapper for games/uhexen2.
# The source tree does not have a main Makefile.
#
# $FreeBSD$
#

all:
ifeq ($(BUILD_HEXEN2),yes)
	$(MAKE) -C hexen2 h2 clean
	$(MAKE) -C hexen2 glh2 clean
endif
ifeq ($(BUILD_HW),yes)
	cd hexenworld && ./build.sh
endif
ifeq ($(BUILD_LAUNCHER_GTK1),yes)
	$(MAKE) -C launcher GTK1=yes
	cd launcher && mv h2launcher h2launcher.gtk1
	$(MAKE) -C launcher clean
endif
ifeq ($(BUILD_LAUNCHER_GTK2),yes)
	$(MAKE) -C launcher
	cd launcher && mv h2launcher h2launcher.gtk2
	$(MAKE) -C launcher clean
endif
