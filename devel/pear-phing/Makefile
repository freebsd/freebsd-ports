# $FreeBSD$

PORTNAME=	phing
PORTVERSION=	2.6.1
CATEGORIES=	devel pear
MASTER_SITES=	http://pear.phing.info/get/
PKGNAMEPREFIX=	pear-

MAINTAINER=	mm@FreeBSD.org
COMMENT=	PHP project build system based on Apache Ant

LICENSE=	LGPL3

PEAR_CHANNEL=	phing
PEAR_AUTOINSTALL=	yes
IGNORE_WITH_PHP=52

BUILD_DEPENDS+= ${PEARDIR}/.channels/pear.phing.info.reg:${PORTSDIR}/devel/pear-channel-phing
RUN_DEPENDS+= ${PEARDIR}/.channels/pear.phing.info.reg:${PORTSDIR}/devel/pear-channel-phing

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
