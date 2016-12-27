# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	ConsoleTools
PORTVERSION=	1.6.1
CATEGORIES=	devel pear
MASTER_SITES=	http://components.ez.no/get/
PKGNAMEPREFIX=	pear-${PEAR_CHANNEL}_

MAINTAINER=	joneum@bsdproject.de
COMMENT=	Set of classes to do different actions with the console

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	pear-ezc_Base>=1.8:devel/pear-ezc_Base \
		${PEARDIR}/.channels/components.ez.no.reg:devel/pear-channel-ezc
RUN_DEPENDS=	pear-ezc_Base>=1.8:devel/pear-ezc_Base \
		${PEARDIR}/.channels/components.ez.no.reg:devel/pear-channel-ezc

PEAR_CHANNEL=	ezc
USES=	pear

.include <bsd.port.mk>
