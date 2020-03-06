# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	phpDox
PORTVERSION=	0.5.0
CATEGORIES=	devel pear
MASTER_SITES=	http://pear.netpirates.net/get/
PKGNAMEPREFIX=	${PEAR_PKGNAMEPREFIX}TheSeer_

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PHP Documentation generation framework and tool

BROKEN=		unfetchable

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PEAR_PKGNAMEPREFIX}TheSeer_DirectoryScanner>=1.1.0:devel/pear-TheSeer_DirectoryScanner@${PHP_FLAVOR} \
		${PEAR_PKGNAMEPREFIX}TheSeer_fDOMDocument>=1.2.3:devel/pear-TheSeer_fDOMDocument@${PHP_FLAVOR} \
		${PEAR_PKGNAMEPREFIX}TheSeer_fXSL>=1.0.4:devel/pear-TheSeer_fXSL@${PHP_FLAVOR} \
		${PEAR_PKGNAMEPREFIX}ezc_ConsoleTools>=1.6:devel/pear-ezc_ConsoleTools@${PHP_FLAVOR} \
		${PEAR_PKGNAMEPREFIX}pdepend_staticReflection>=0.2.1:devel/pear-pdepend-staticReflection@${PHP_FLAVOR}
RUN_DEPENDS=	${PEAR_PKGNAMEPREFIX}TheSeer_DirectoryScanner>=1.1.0:devel/pear-TheSeer_DirectoryScanner@${PHP_FLAVOR} \
		${PEAR_PKGNAMEPREFIX}TheSeer_fDOMDocument>=1.2.3:devel/pear-TheSeer_fDOMDocument@${PHP_FLAVOR} \
		${PEAR_PKGNAMEPREFIX}TheSeer_fXSL>=1.0.4:devel/pear-TheSeer_fXSL@${PHP_FLAVOR} \
		${PEAR_PKGNAMEPREFIX}ezc_ConsoleTools>=1.6:devel/pear-ezc_ConsoleTools@${PHP_FLAVOR} \
		${PEAR_PKGNAMEPREFIX}pdepend_staticReflection>=0.2.1:devel/pear-pdepend-staticReflection@${PHP_FLAVOR}

USE_PHP=	dom tokenizer xsl iconv
PEAR_CHANNEL=	theseer
USES=		pear php

.include <bsd.port.mk>
