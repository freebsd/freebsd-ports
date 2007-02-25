# GNU Makefile wrapper for games/uhexen2.
# The source tree does not have a main Makefile.
#
# $FreeBSD$
#

all:
ifeq ($(BUILD_HEXEN2),yes)
ifeq ($(USE_X86_ASM),yes)
	$(MAKE) -C hexen2 h2 clean
endif
	$(MAKE) -C hexen2 glh2 clean
endif
ifeq ($(BUILD_HW),yes)
	cd hexenworld && ./build.sh
endif
ifeq ($(BUILD_LAUNCHER_GTK1),yes)
	$(MAKE) -C launcher GTK1=yes
	$(MAKE) -C launcher clean
endif
ifeq ($(BUILD_LAUNCHER_GTK2),yes)
	$(MAKE) -C launcher
	$(MAKE) -C launcher clean
endif
