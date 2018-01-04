# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	PHPCPD
DISTVERSION=	2.0.0
CATEGORIES=	devel pear
PKGNAMEPREFIX=	pear-SebastianBergmann_

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Copy/Paste Detector (CPD) for PHP code

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	pear-ezc_ConsoleTools>=1.6.1:devel/pear-ezc_ConsoleTools \
		pear-SebastianBergmann_FinderFacade>=1.2.2:devel/pear-SebastianBergmann_FinderFacade \
		pear-PHP_Timer>=1.0.9:devel/pear-PHP_Timer \
		pear-channel-phpunit>=20110327:devel/pear-channel-phpunit
RUN_DEPENDS=	pear-ezc_ConsoleTools>=1.6.1:devel/pear-ezc_ConsoleTools \
		pear-SebastianBergmann_FinderFacade>=1.2.2:devel/pear-SebastianBergmann_FinderFacade \
		pear-PHP_Timer>=1.0.9:devel/pear-PHP_Timer \
		pear-channel-phpunit>=20110327:devel/pear-channel-phpunit

USES=	php
USE_GITHUB=	yes
GH_ACCOUNT=	sebastianbergmann
GH_PROJECT=	${PORTNAME:tl}
USE_PHP=	tokenizer

NO_ARCH=	yes


NO_BUILD=	yes

PLIST_FILES=	${DATADIR}/phpcpd.php

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/phpcpd.php ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
