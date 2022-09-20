PORTREVISION=	0
CATEGORIES=	audio

COMMENT=	Gstreamer ladspa (Linux Audio Developer's Simple Plugin API) plugin

GST_PLUGIN=	ladspa
DIST=		bad

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

PLIST=  ${.CURDIR}/pkg-plist

BUILD_DEPENDS= ${LOCALBASE}/include/ladspa.h:audio/ladspa

LIB_DEPENDS= liblrdf.so:textproc/liblrdf

.include "${MASTERDIR}/Makefile"
