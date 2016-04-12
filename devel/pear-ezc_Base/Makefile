# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	Base
PORTVERSION=	1.8
CATEGORIES=	devel pear
MASTER_SITES=	http://components.ez.no/get/
PKGNAMEPREFIX=	pear-${PEAR_CHANNEL}_

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	Base package that all ezc components packages rely on

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PEARDIR}/.channels/components.ez.no.reg:devel/pear-channel-ezc
RUN_DEPENDS=	${PEARDIR}/.channels/components.ez.no.reg:devel/pear-channel-ezc

PEAR_CHANNEL=	ezc
USES=	pear

.include <bsd.port.mk>
