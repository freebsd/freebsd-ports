# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	fDOMDocument
PORTVERSION=	1.3.2
CATEGORIES=	devel www pear
MASTER_SITES=	http://pear.netpirates.net/get/
PKGNAMEPREFIX=	pear-TheSeer_

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	Extension to PHP\'s standard DOM

LICENSE=	BSD

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/.channels/pear.netpirates.net.reg:${PORTSDIR}/devel/pear-channel-theseer
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/.channels/pear.netpirates.net.reg:${PORTSDIR}/devel/pear-channel-theseer

USE_PHP=	dom xml
PEAR_CHANNEL=	theseer
PEAR_AUTOINSTALL=	yes

IGNORE_WITH_PHP=52

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
