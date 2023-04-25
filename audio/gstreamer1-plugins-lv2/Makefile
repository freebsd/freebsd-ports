PORTREVISION=	1
CATEGORIES=	audio

COMMENT=	Gstreamer lv2 wrapper plugin

GST_PLUGIN=	lv2
DIST=		bad

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

PLIST=  ${.CURDIR}/pkg-plist

BUILD_DEPENDS=  lv2>=1.14.0:audio/lv2
LIB_DEPENDS=  libsord-0.so:devel/sord \
		libserd-0.so:devel/serd \
		libsratom-0.so:audio/sratom \
		liblilv-0.so:audio/lilv

.include "${MASTERDIR}/Makefile"

USES+=   pkgconfig
