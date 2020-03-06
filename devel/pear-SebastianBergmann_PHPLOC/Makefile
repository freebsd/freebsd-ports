# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	PHPLOC
DISTVERSION=	4.0.1
CATEGORIES=	devel pear
PKGNAMEPREFIX=	${PEAR_PKGNAMEPREFIX}SebastianBergmann_

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Tool for quickly measuring the size of a PHP project

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PEAR_PKGNAMEPREFIX}Symfony_Component_Console>=2.4.4:devel/pear-Symfony_Component_Console@${PHP_FLAVOR} \
		${PEAR_PKGNAMEPREFIX}SebastianBergmann_FinderFacade>=1.2.2:devel/pear-SebastianBergmann_FinderFacade@${PHP_FLAVOR} \
		${PEAR_PKGNAMEPREFIX}SebastianBergmann_Git>=1.2.0:devel/pear-SebastianBergmann_Git@${PHP_FLAVOR} \
		${PEAR_PKGNAMEPREFIX}SebastianBergmann_Version>=2.0.1:devel/pear-SebastianBergmann_Version@${PHP_FLAVOR} \

USES=	php pear:env
PEAR_CHANNEL=	phpunit
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
