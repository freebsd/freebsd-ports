# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	staticReflection
PORTVERSION=	1.0.0
CATEGORIES=	devel pear
MASTER_SITES=	http://pear.pdepend.org/get/
PKGNAMEPREFIX=	pear-${PEAR_CHANNEL}_

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	staticReflection package for PHP

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PEARDIR}/.channels/pear.pdepend.org.reg:devel/pear-channel-pdepend
RUN_DEPENDS=	${PEARDIR}/.channels/pear.pdepend.org.reg:devel/pear-channel-pdepend

USE_PHP=	tokenizer
PEAR_CHANNEL=	pdepend
USES=	pear

.include <bsd.port.mk>
