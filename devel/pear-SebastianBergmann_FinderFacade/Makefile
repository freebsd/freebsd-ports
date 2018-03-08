# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	FinderFacade
PORTVERSION=	1.2.2
CATEGORIES=	devel pear
PKGNAMEPREFIX=	${PEAR_PKGNAMEPREFIX}SebastianBergmann_

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Convenience wrapper for Symfony Finder component

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PEAR_PKGNAMEPREFIX}TheSeer_fDOMDocument>=1.6.6:devel/pear-TheSeer_fDOMDocument@${PHP_FLAVOR} \
		${PEAR_PKGNAMEPREFIX}Symfony_Component_Finder>=2.3.4:devel/pear-Symfony_Component_Finder@${PHP_FLAVOR} \

RUN_DEPENDS=	${PEAR_PKGNAMEPREFIX}TheSeer_fDOMDocument>=1.6.6:devel/pear-TheSeer_fDOMDocument@${PHP_FLAVOR} \
		${PEAR_PKGNAMEPREFIX}Symfony_Component_Finder>=2.3.4:devel/pear-Symfony_Component_Finder@${PHP_FLAVOR} \

NO_ARCH=	yes

USES=		pear:env
PEAR_CHANNEL=	phpunit
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
