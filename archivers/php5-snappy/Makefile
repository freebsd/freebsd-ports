# Created by: Melvyn Sopacua <melvyn@magemana.nl>
# $FreeBSD$

PORTNAME=	php5-snappy
PORTVERSION=	0.0.2
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	GOOGLE_CODE
PROJECTHOST=	php-snappy
DISTNAME=	${PROJECTHOST}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PHP extension for the snappy compression algorithm

LICENSE=	BSD2CLAUSE

LIB_DEPENDS+=	libsnappy.so:archivers/snappy
CONFIGURE_ARGS+=	--with-snappy-includedir=${LOCALBASE}/include

USE_PHP=	yes
USE_PHPEXT=	yes
PHP_MODNAME=	snappy
WRKSRC=		${WRKDIR}/${PROJECTHOST}
OPTIONS_DEFINE=	TEST
IGNORE_WITH_PHP=	70

post-build-TEST-on:
	@(cd ${WRKSRC} && ${MAKE} ${MAKE_ENV} NO_INTERACTION=yes ${.TARGET})

post-stage:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/php/${PHP_EXT_DIR}/snappy.so

.include <bsd.port.mk>
