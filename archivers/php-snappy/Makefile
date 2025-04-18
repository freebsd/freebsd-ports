PORTNAME=	snappy
PORTVERSION=	0.2.3
CATEGORIES=	archivers
MASTER_SITES=	https://github.com/kjdev/php-ext-snappy/releases/download/${PORTVERSION}/
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PHP extension for the snappy compression algorithm
WWW=		https://github.com/kjdev/php-ext-snappy

LICENSE=	BSD3CLAUSE PHP301
LICENSE_COMB=	multi
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/snappy/COPYING
LICENSE_FILE_PHP301=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsnappy.so:archivers/snappy

USES=		localbase php:ext tar:tgz

CONFIGURE_ARGS=	--with-snappy-includedir=${LOCALBASE}/include

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/php/${PHP_EXT_DIR}/snappy.so

do-test:
	cd ${WRKSRC} && ${DO_MAKE_BUILD} NO_INTERACTION=yes test < /dev/null

.include <bsd.port.mk>
