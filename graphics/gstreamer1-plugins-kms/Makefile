PORTREVISION=	0
CATEGORIES=	graphics

COMMENT=	GStreamer video sink via KMS plugin

LIB_DEPENDS=	libdrm.so:graphics/libdrm

MASTERDIR=	${.CURDIR:H:H}/multimedia/gstreamer1-plugins

PLIST=		${.CURDIR}/pkg-plist

DIST=		bad
GST_PLUGIN=	kms

.include "${MASTERDIR}/Makefile"
