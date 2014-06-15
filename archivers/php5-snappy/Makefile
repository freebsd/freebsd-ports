# Created by: Melvyn Sopacua <melvyn@magemana.nl>
# $FreeBSD$

PORTNAME=	php5-snappy
PORTVERSION=	0.0.2
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PROJECTHOST=	php-snappy
DISTNAME=	${PROJECTHOST}-${PORTVERSION}

MAINTAINER=	melvyn@magemana.nl
COMMENT=	PHP extension for the snappy compression algorithm

LICENSE=	BSD2CLAUSE

LIB_DEPENDS+=	libsnappy.so:${PORTSDIR}/archivers/snappy
CONFIGURE_ARGS+=	--with-snappy-includedir=${LOCALBASE}/include

USE_PHP=	yes
USE_PHPEXT=	yes
PHP_MODNAME=	snappy
WRKSRC=		${WRKDIR}/${PROJECTHOST}
OPTIONS_DEFINE=	TEST

.include <bsd.port.options.mk>
test: build
	@(cd ${WRKSRC} && ${MAKE} ${MAKE_ENV} NO_INTERACTION=yes ${.TARGET})

.if !empty(${PORT_OPTIONS:MTEST})
post-stage: test
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/php/20100525/snappy.so
.else
post-stage:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/php/20100525/snappy.so
.endif

.include <bsd.port.mk>
