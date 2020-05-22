# Created by: John Hixson <john@pcbsd.org>
# $FreeBSD$

PORTNAME=	pianobar
PORTVERSION=	2019.02.14
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	https://6xq.net/${PORTNAME}/

MAINTAINER=	jhixson@FreeBSD.org
COMMENT=	Command-line Pandora online radio player

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libao.so:audio/libao \
		libgnutls.so:security/gnutls \
		libjson-c.so:devel/json-c \
		libgcrypt.so:security/libgcrypt \
		libavcodec.so:multimedia/ffmpeg \
		libcurl.so:ftp/curl

MAKE_ENV+=	V=1
USES=		alias gmake localbase pkgconfig tar:bzip2

PLIST_FILES=	bin/pianobar \
		man/man1/pianobar.1.gz

post-install:
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/pianobar

.include <bsd.port.mk>
