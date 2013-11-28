# Created by: chinsan
# $FreeBSD$

PORTNAME=	Net_DNS
PORTVERSION=	1.0.7
PORTREVISION=	1
CATEGORIES=	dns net pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Resolver library used to communicate with a DNS server

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

PORTSCOUT=	skipv:1.00b2,1.00b1
USE_PHP=	mhash
PEAR_AUTOINSTALL=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
