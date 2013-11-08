# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	Base
PORTVERSION=	1.8
CATEGORIES=	devel pear
MASTER_SITES=	http://components.ez.no/get/
PKGNAMEPREFIX=	pear-${PEAR_CHANNEL}_

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	Base package that all ezc components packages rely on

LICENSE=	BSD

BUILD_DEPENDS=	pear>=1.4.2:${PORTSDIR}/devel/pear \
		${PEARDIR}/.channels/components.ez.no.reg:${PORTSDIR}/devel/pear-channel-ezc
RUN_DEPENDS=	pear>=1.4.2:${PORTSDIR}/devel/pear \
		${PEARDIR}/.channels/components.ez.no.reg:${PORTSDIR}/devel/pear-channel-ezc

PEAR_CHANNEL=	ezc
PEAR_AUTOINSTALL=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
