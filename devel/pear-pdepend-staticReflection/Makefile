# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	staticReflection
PORTVERSION=	1.0.0
CATEGORIES=	devel pear
MASTER_SITES=	http://pear.pdepend.org/get/
PKGNAMEPREFIX=	pear-${PEAR_CHANNEL}_

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	staticReflection package for PHP

LICENSE=	BSD

BUILD_DEPENDS=	pear>=1.6.0:${PORTSDIR}/devel/pear \
		${PEARDIR}/.channels/pear.pdepend.org.reg:${PORTSDIR}/devel/pear-channel-pdepend
RUN_DEPENDS=	pear>=1.6.0:${PORTSDIR}/devel/pear \
		${PEARDIR}/.channels/pear.pdepend.org.reg:${PORTSDIR}/devel/pear-channel-pdepend

USE_PHP=	tokenizer
PEAR_CHANNEL=	pdepend
PEAR_AUTOINSTALL=	yes
IGNORE_WITH_PHP=52

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
