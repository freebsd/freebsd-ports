# Created by: Melvyn Sopacua <melvyn@magemana.nl>
# $FreeBSD$

PORTNAME=	php5-snappy
PORTVERSION=	0.1.5
CATEGORIES=	archivers

MAINTAINER=	joneum@bsdproject.de
COMMENT=	PHP extension for the snappy compression algorithm

LICENSE=	BSD3CLAUSE PHP301
LICENSE_COMB=	multi
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/COPYING.snappy
LICENSE_FILE_PHP301=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsnappy.so:archivers/snappy

USE_GITHUB=	yes
GH_ACCOUNT=	kjdev
GH_PROJECT=	php-ext-snappy

USES=		php:ext
PHP_MODNAME=	snappy
CONFIGURE_ARGS=	--with-snappy-includedir=${LOCALBASE}/include

do-test:
	(cd ${WRKSRC} && ${DO_MAKE_BUILD} NO_INTERACTION=yes test < /dev/null)

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/php/${PHP_EXT_DIR}/snappy.so

.include <bsd.port.mk>
