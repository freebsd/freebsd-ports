# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	htmlpurifier
PORTVERSION=	4.6.0
CATEGORIES=	devel pear www
MASTER_SITES=	http://htmlpurifier.org/get/ \
		LOCAL
DISTNAME=	HTMLPurifier-${PORTVERSION}
PKGNAMEPREFIX=	pear-

MAINTAINER=	feld@FreeBSD.org
COMMENT=	PHP HTML filter library

LICENSE=	LGPL21

BUILD_DEPENDS=	${PEARDIR}/.channels/htmlpurifier.org.reg:${PORTSDIR}/devel/pear-channel-htmlpurifier
RUN_DEPENDS:=	${BUILD_DEPENDS}

PEAR_CHANNEL=	htmlpurifier
PEAR_AUTOINSTALL=	yes

PLIST_FILES+=	%%PEARDIR%%/.channels/.alias/hp.txt

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
