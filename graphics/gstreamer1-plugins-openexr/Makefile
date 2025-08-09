PORTREVISION=	0
CATEGORIES=	graphics

COMMENT=	GStreamer OpenExr codec plugin

LIB_DEPENDS=	libOpenEXR.so:graphics/openexr

USES+=		compiler:c++11-lang

CPPFLAGS+=	-DInt64=uint64_t

MASTERDIR=	${.CURDIR:H:H}/multimedia/gstreamer1-plugins

PLIST=		${.CURDIR}/pkg-plist

DIST=		bad
GST_PLUGIN=	openexr

.include "${MASTERDIR}/Makefile"
