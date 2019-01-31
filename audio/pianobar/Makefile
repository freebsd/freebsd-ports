# Created by: John Hixson <john@pcbsd.org>
# $FreeBSD$

PORTNAME=	pianobar
PORTVERSION=	2019.01.25
CATEGORIES=	audio
MASTER_SITES=	https://6xq.net/${PORTNAME}/

MAINTAINER=	jhixson@FreeBSD.org
COMMENT=	Command-line Pandora online radio player

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libao.so:audio/libao \
		libfaad.so:audio/faad \
		libmad.so:audio/libmad \
		libgnutls.so:security/gnutls \
		libjson-c.so:devel/json-c \
		libgcrypt.so:security/libgcrypt \
		libavcodec.so:multimedia/ffmpeg \
		libcurl.so:ftp/curl

USES=		alias gmake pkgconfig tar:bzip2

PLIST_FILES=	bin/pianobar \
		man/man1/pianobar.1.gz

MAKE_ARGS+=	CC="${CC}" PREFIX="${PREFIX}"

CFLAGS+=	-I${LOCALBASE}/include -std=c99
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
