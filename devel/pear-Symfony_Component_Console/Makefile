# Created by: William Grzybowski <wg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Console
PORTVERSION=	2.4.4
CATEGORIES=	devel pear
MASTER_SITES=	http://pear.symfony.com/get/
PKGNAMEPREFIX=	pear-Symfony_Component_
DIST_SUBDIR=	Symfony2

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Symfony2 Console Component

LICENSE=	MIT

BUILD_DEPENDS+= ${PEARDIR}/.channels/pear.symfony.com.reg:devel/pear-channel-symfony2
RUN_DEPENDS+=	${PEARDIR}/.channels/pear.symfony.com.reg:devel/pear-channel-symfony2

USES=		pear
PEAR_CHANNEL=	symfony2

.include <bsd.port.mk>
