# Created by: John Hixson <john@pcbsd.org>
# $FreeBSD$

PORTNAME=	pianobar
PORTVERSION=	2016.06.02
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	http://6xq.net/projects/${PORTNAME}/

MAINTAINER=	jhixson@gmail.com
COMMENT=	Command line Pandora player

LICENSE=	MIT

LIB_DEPENDS=	libao.so:audio/libao \
		libfaad.so:audio/faad \
		libmad.so:audio/libmad \
		libgnutls.so:security/gnutls \
		libjson-c.so:devel/json-c \
		libgcrypt.so:security/libgcrypt \
		libavcodec.so:multimedia/ffmpeg \
		libcurl.so:ftp/curl

PLIST_FILES=	bin/pianobar \
		man/man1/pianobar.1.gz

USES=		alias gmake pkgconfig tar:bzip2
MAKE_ARGS+=	CC="${CC}" PREFIX="${PREFIX}"

CFLAGS+=	-I${LOCALBASE}/include -std=c99
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
