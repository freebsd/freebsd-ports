# GNU Makefile wrapper for games/uhexen2.
# The source tree does not have a main Makefile.
#
# $FreeBSD$
#

all:
ifeq ($(BUILD_HEXEN2),yes)
	$(MAKE) -C engine/hexen2 h2 clean
	$(MAKE) -C engine/hexen2 glh2 clean
endif
ifeq ($(BUILD_HW),yes)
	$(MAKE) -C engine/hexenworld/server hwsv clean
	$(MAKE) -C engine/hexenworld/client hw localclean
	$(MAKE) -C engine/hexenworld/client glhw localclean
	$(MAKE) -C hw_utils/hwmaster hwmaster clean
endif
