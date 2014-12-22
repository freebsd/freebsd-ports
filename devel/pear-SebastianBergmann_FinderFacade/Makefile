# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	FinderFacade
PORTVERSION=	1.1.0
CATEGORIES=	devel pear
MASTER_SITES=	http://pear.phpunit.de/get/
PKGNAMEPREFIX=	pear-SebastianBergmann_

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	Convenience wrapper for Symfony's Finder component

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	pear-TheSeer_fDOMDocument>=1.3.1:${PORTSDIR}/devel/pear-TheSeer_fDOMDocument \
		pear-Symfony_Component_Finder>=2.2.0:${PORTSDIR}/devel/pear-Symfony_Component_Finder \
		${PEARDIR}/.channels/pear.phpunit.de.reg:${PORTSDIR}/devel/pear-channel-phpunit
RUN_DEPENDS=	pear-TheSeer_fDOMDocument>=1.3.1:${PORTSDIR}/devel/pear-TheSeer_fDOMDocument \
		pear-Symfony_Component_Finder>=2.2.0:${PORTSDIR}/devel/pear-Symfony_Component_Finder \
		${PEARDIR}/.channels/pear.phpunit.de.reg:${PORTSDIR}/devel/pear-channel-phpunit

PEAR_CHANNEL=	phpunit
USES=	pear

.include <bsd.port.mk>
