PORTREVISION=	2
CATEGORIES=	graphics

COMMENT=	GStreamer OpenExr codec plugin

USES+=		compiler:c++11-lang
GST_PLUGIN=	openexr
DIST=		bad

CPPFLAGS+=	-DInt64=uint64_t

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

PLIST=  ${.CURDIR}/pkg-plist

LIB_DEPENDS=  libOpenEXR.so:graphics/openexr \
	libImath-3_1.so:math/Imath

.include "${MASTERDIR}/Makefile"
