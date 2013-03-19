# New ports collection makefile for:		dbus-sharp
# Date Created:					20041011
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#

PORTNAME=	dbus-sharp
PORTVERSION=	0.7.0
PORTEPOCH=	1
CATEGORIES=	devel gnome
MASTER_SITES=	http://cloud.github.com/downloads/mono/${PORTNAME}/

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Mono interface to the D-BUS messaging system

BUILD_DEPENDS=	mono:${PORTSDIR}/lang/mono
RUN_DEPENDS=	mono:${PORTSDIR}/lang/mono

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USES=	pathfix
USE_PKGCONFIG=	build

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.mk>
