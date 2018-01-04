# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	Version
DISTVERSION=	2.0.1
CATEGORIES=	devel pear
PKGNAMEPREFIX=	pear-SebastianBergmann_

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Managing the version number of Git-hosted PHP projects

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	pear-channel-phpunit>=20110327:devel/pear-channel-phpunit
RUN_DEPENDS=	pear-channel-phpunit>=20110327:devel/pear-channel-phpunit

USES=	php
USE_GITHUB=	yes
GH_ACCOUNT=	sebastianbergmann
GH_PROJECT=	${PORTNAME:tl}

NO_ARCH=	yes

NO_BUILD=	yes

PLIST_FILES=	${DATADIR}/Version.php

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/src/Version.php ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
