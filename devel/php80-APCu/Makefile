PORTNAME=	APCu
DISTVERSIONPREFIX=	v
DISTVERSION=	5.1.28
CATEGORIES=	devel

PATCH_SITES=	https://github.com/krakjoe/apcu/commit/
PATCHFILES=	90899684be91c4f750512c2f840f487286ecb807.patch:-p1

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	APC User Caching (php80)
WWW=		https://github.com/krakjoe/apcu

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		localbase
USE_GITHUB=	yes
GH_ACCOUNT=	krakjoe
GH_PROJECT=	apcu

PLIST_FILES=	${DATADIR}/apc.php

.include "${.CURDIR}/../../lang/php80-legacy/Makefile.inc"

PHP_MODNAME=	${GH_PROJECT}

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/apc.php ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
