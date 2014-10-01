# Created by: William Grzybowski <wg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Console
PORTVERSION=	2.4.4
CATEGORIES=	devel pear
PKGNAMEPREFIX=	pear-Symfony_Component_
MASTER_SITES=	http://pear.symfony.com/get/
DIST_SUBDIR=	Symfony2

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Symfony2 Console Component

LICENSE=	MIT

BUILD_DEPENDS+= ${PEARDIR}/.channels/pear.symfony.com.reg:${PORTSDIR}/devel/pear-channel-symfony2
RUN_DEPENDS+=	${PEARDIR}/.channels/pear.symfony.com.reg:${PORTSDIR}/devel/pear-channel-symfony2

USES=		pear
PEAR_CHANNEL=	symfony2

IGNORE_WITH_PHP=52

.include <bsd.port.mk>
