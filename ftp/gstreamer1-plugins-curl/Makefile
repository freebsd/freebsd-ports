PORTREVISION=	0
CATEGORIES=	ftp

COMMENT=	GStreamer curl based output plugin

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libssh2.so:security/libssh2

MASTERDIR=	${.CURDIR:H:H}/multimedia/gstreamer1-plugins

PLIST=		${.CURDIR}/pkg-plist

DIST=		bad
GST_PLUGIN=	curl

.include "${MASTERDIR}/Makefile"
