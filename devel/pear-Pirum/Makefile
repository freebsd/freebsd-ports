# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	Pirum
PORTVERSION=	1.1.5
CATEGORIES=	devel www pear
MASTER_SITES=	http://pear.pirum-project.org/get/
PKGNAMEPREFIX=	pear-

MAINTAINER=	joneum@bsdproject.de
COMMENT=	Simple PEAR channel server manager

LICENSE=	MIT

BUILD_DEPENDS=	${PEARDIR}/.channels/pear.pirum-project.org.reg:devel/pear-channel-pirum
RUN_DEPENDS=	${PEARDIR}/.channels/pear.pirum-project.org.reg:devel/pear-channel-pirum

PEAR_CHANNEL=	pirum
USES=	pear

.include <bsd.port.mk>
