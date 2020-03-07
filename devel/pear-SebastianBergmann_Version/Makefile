# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	Version
DISTVERSION=	2.0.1
CATEGORIES=	devel pear
PKGNAMEPREFIX=	${PEAR_PKGNAMEPREFIX}SebastianBergmann_

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Managing the version number of Git-hosted PHP projects

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	pear:env
PEAR_CHANNEL=	phpunit
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
