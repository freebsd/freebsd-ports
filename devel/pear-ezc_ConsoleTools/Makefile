# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	ConsoleTools
PORTVERSION=	1.6.1
CATEGORIES=	devel pear
MASTER_SITES=	http://components.ez.no/get/
PKGNAMEPREFIX=	pear-${PEAR_CHANNEL}_

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	Set of classes to do different actions with the console

LICENSE=	BSD

BUILD_DEPENDS=	pear>=1.4.2:${PORTSDIR}/devel/pear \
		pear-ezc_Base>=1.8:${PORTSDIR}/devel/pear-ezc_Base \
		${PEARDIR}/.channels/components.ez.no.reg:${PORTSDIR}/devel/pear-channel-ezc
RUN_DEPENDS=	pear>=1.4.2:${PORTSDIR}/devel/pear \
		pear-ezc_Base>=1.8:${PORTSDIR}/devel/pear-ezc_Base \
		${PEARDIR}/.channels/components.ez.no.reg:${PORTSDIR}/devel/pear-channel-ezc

PEAR_CHANNEL=	ezc
PEAR_AUTOINSTALL=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
