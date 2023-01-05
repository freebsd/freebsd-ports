PORTNAME=	d11amp
DISTVERSION=	0.61
CATEGORIES=	audio
MASTER_SITES=	https://www.dettus.net/d11amp/
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	dettus@dettus.net
COMMENT=	Oldskool MP3 player
WWW=		https://www.dettus.net/d11amp/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libmpg123.so:audio/mpg123 \
		libportaudio.so:audio/portaudio	\
		libzip.so:archivers/libzip

USES=		gnome pkgconfig tar:bz2
USE_GNOME=	cairo gdkpixbuf2 gtk40

MAKE_ARGS=	INSTALLMAN=${STAGEDIR}${PREFIX}/man
TEST_ENV=	SHA256_CMD=sha256 TMP_DIR=/tmp/d11amp/
TEST_TARGET=	check

LDFLAGS+=	-Wl,--as-needed

PLIST_FILES=	bin/d11amp \
		man/man1/d11amp.1.gz

post-install:
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/d11amp

.include <bsd.port.mk>
