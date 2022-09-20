PORTREVISION=	0
CATEGORIES=	audio

COMMENT=	Gstreamer musepack mpc encoder/decoder plugin

GST_PLUGIN=	musepack
DIST=		bad

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

PLIST=  ${.CURDIR}/pkg-plist

LIB_DEPENDS=libmpcdec.so:audio/musepack

.include "${MASTERDIR}/Makefile"
