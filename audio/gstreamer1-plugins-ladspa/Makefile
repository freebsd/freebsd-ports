PORTREVISION=	0
CATEGORIES=	audio

COMMENT=	Gstreamer ladspa (Linux Audio Developer's Simple Plugin API) plugin

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa
LIB_DEPENDS=	liblrdf.so:textproc/liblrdf

MASTERDIR=	${.CURDIR:H:H}/multimedia/gstreamer1-plugins

PLIST=		${.CURDIR}/pkg-plist

DIST=		bad
GST_PLUGIN=	ladspa

.include "${MASTERDIR}/Makefile"
