# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	PHPLOC
DISTVERSION=	4.0.1
CATEGORIES=	devel pear
PKGNAMEPREFIX=	pear-SebastianBergmann_

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Tool for quickly measuring the size of a PHP project

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	pear-Symfony_Component_Console>=2.4.4:devel/pear-Symfony_Component_Console \
		pear-SebastianBergmann_FinderFacade>=1.2.2:devel/pear-SebastianBergmann_FinderFacade \
		pear-SebastianBergmann_Git>=1.2.0:devel/pear-SebastianBergmann_Git \
		pear-SebastianBergmann_Version>=2.0.1:devel/pear-SebastianBergmann_Version \
		pear-channel-phpunit>=20110327:devel/pear-channel-phpunit

USES=	php
USE_GITHUB=	yes
GH_ACCOUNT=	sebastianbergmann
GH_PROJECT=	${PORTNAME:tl}

NO_ARCH=	yes

NO_BUILD=	yes

PLIST_FILES=	${DATADIR}/Publisher.php

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/src/Publisher.php ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
