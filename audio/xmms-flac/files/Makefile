# $FreeBSD$

SUBDIRS= src/share src/plugin_common src/plugin_xmms

all install:
	@for d in ${SUBDIRS}; do \
		(cd $$d; ${MAKE} $@); \
	done
