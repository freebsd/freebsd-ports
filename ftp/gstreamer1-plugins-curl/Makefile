PORTREVISION=	0
CATEGORIES=	ftp

COMMENT=	GStreamer curl based output plugin

GST_PLUGIN=	curl
DIST=		bad

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

PLIST=  ${.CURDIR}/pkg-plist

LIB_DEPENDS= libcurl.so:ftp/curl \
	libssh2.so:security/libssh2

.include "${MASTERDIR}/Makefile"
