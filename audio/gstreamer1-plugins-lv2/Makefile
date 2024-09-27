PORTREVISION=	0
CATEGORIES=	audio

COMMENT=	Gstreamer lv2 wrapper plugin

BUILD_DEPENDS=	lv2>=1.14.0:audio/lv2
LIB_DEPENDS=	liblilv-0.so:audio/lilv \
		libserd-0.so:devel/serd \
		libsord-0.so:devel/sord \
		libsratom-0.so:audio/sratom

MASTERDIR=	${.CURDIR:H:H}/multimedia/gstreamer1-plugins

PLIST=		${.CURDIR}/pkg-plist

DIST=		bad
GST_PLUGIN=	lv2

.include "${MASTERDIR}/Makefile"
