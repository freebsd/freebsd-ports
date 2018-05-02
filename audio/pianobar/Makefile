# Created by: John Hixson <john@pcbsd.org>
# $FreeBSD$

PORTNAME=	pianobar
PORTVERSION=	2017.08.30
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://6xq.net/${PORTNAME}/

PATCH_SITES=	https://github.com/PromyLOPh/${PORTNAME}/commit/
PATCHFILES=	38b16f9957a7.patch:-p1

MAINTAINER=	jhixson@gmail.com
COMMENT=	Command-line Pandora online radio player

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
