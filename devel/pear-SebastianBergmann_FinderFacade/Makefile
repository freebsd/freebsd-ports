# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	FinderFacade
PORTVERSION=	1.2.2
CATEGORIES=	devel pear
PKGNAMEPREFIX=	pear-SebastianBergmann_

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Convenience wrapper for Symfony Finder component

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	pear-TheSeer_fDOMDocument>=1.6.6:devel/pear-TheSeer_fDOMDocument \
		pear-Symfony_Component_Finder>=2.3.4:devel/pear-Symfony_Component_Finder \
		pear-channel-phpunit>=20110327:devel/pear-channel-phpunit

RUN_DEPENDS=	pear-TheSeer_fDOMDocument>=1.6.6:devel/pear-TheSeer_fDOMDocument \
		pear-Symfony_Component_Finder>=2.3.4:devel/pear-Symfony_Component_Finder \
		pear-channel-phpunit>=20110327:devel/pear-channel-phpunit

NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	sebastianbergmann
GH_PROJECT=	finder-facade

NO_BUILD=	yes

PHP_DIR=	share/PHP

PLIST_FILES=	${PHP_DIR}/${PORTNAME}/FinderFacade.php

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${PHP_DIR}/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKSRC}/src/FinderFacade.php \
		${STAGEDIR}${PREFIX}/${PHP_DIR}/${PORTNAME}

.include <bsd.port.mk>
