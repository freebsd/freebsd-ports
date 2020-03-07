# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	ConsoleTools
PORTVERSION=	1.6.1
CATEGORIES=	devel pear
MASTER_SITES=	http://components.ez.no/get/
PKGNAMEPREFIX=	${PEAR_PKGNAMEPREFIX}${PEAR_CHANNEL}_

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Set of classes to do different actions with the console

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PEAR_PKGNAMEPREFIX}ezc_Base>=1.8:devel/pear-ezc_Base@${PHP_FLAVOR}
RUN_DEPENDS=	${PEAR_PKGNAMEPREFIX}ezc_Base>=1.8:devel/pear-ezc_Base@${PHP_FLAVOR}

PEAR_CHANNEL=	ezc
USES=	pear

.include <bsd.port.mk>
