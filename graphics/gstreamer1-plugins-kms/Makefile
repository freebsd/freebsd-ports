PORTREVISION=	0
CATEGORIES=	graphics

COMMENT=	GStreamer video sink via KMS plugin

GST_PLUGIN=	kms
DIST=		bad

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

PLIST=  ${.CURDIR}/pkg-plist

LIB_DEPENDS=  libdrm.so:graphics/libdrm

.include "${MASTERDIR}/Makefile"
