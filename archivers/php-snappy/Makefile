PORTNAME=	snappy
PORTVERSION=	0.2.1
CATEGORIES=	archivers
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PHP extension for the snappy compression algorithm

LICENSE=	BSD3CLAUSE PHP301
LICENSE_COMB=	multi
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/COPYING.snappy
LICENSE_FILE_PHP301=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsnappy.so:archivers/snappy

USES=		php:ext

CONFIGURE_ARGS=	--with-snappy-includedir=${LOCALBASE}/include

USE_GITHUB=	yes
GH_ACCOUNT=	kjdev
GH_PROJECT=	php-ext-snappy

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/php/${PHP_EXT_DIR}/snappy.so

do-test:
	cd ${WRKSRC} && ${DO_MAKE_BUILD} NO_INTERACTION=yes test < /dev/null

.include <bsd.port.mk>
