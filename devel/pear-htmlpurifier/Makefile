# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	htmlpurifier
PORTVERSION=	4.9.2
PORTREVISION=	1
CATEGORIES=	devel pear www
MASTER_SITES=	http://htmlpurifier.org/get/ \
		LOCAL
DISTNAME=	HTMLPurifier-${PORTVERSION}
PKGNAMEPREFIX=	pear-

MAINTAINER=	feld@FreeBSD.org
COMMENT=	PHP HTML filter library

LICENSE=	LGPL21

BUILD_DEPENDS=	${PEARDIR}/.channels/htmlpurifier.org.reg:devel/pear-channel-htmlpurifier.org
RUN_DEPENDS=	${PEARDIR}/.channels/htmlpurifier.org.reg:devel/pear-channel-htmlpurifier.org

PEAR_CHANNEL=	htmlpurifier.org
USES=	pear

NO_ARCH=	yes

.include <bsd.port.mk>
