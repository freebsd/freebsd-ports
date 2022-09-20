PORTREVISION=	0
CATEGORIES=	audio
PKGNAMESUFFIX=	1-plugins-amrwbdec

COMMENT=	GStreamer OpenCore based Adaptive Multi-Rate Wide-Band Decoder plugin

GST_PLUGIN=	amrwbdec
DIST=		ugly

MASTERDIR=  ${.CURDIR}/../../multimedia/gstreamer1-plugins

MESON_ARGS+= -Dgpl=enabled

PLIST=  ${.CURDIR}/pkg-plist

LIB_DEPENDS= libopencore-amrwb.so:audio/opencore-amr

.include "${MASTERDIR}/Makefile"
