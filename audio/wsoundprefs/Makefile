# Created by: gljohns@bellsouth.net
# $FreeBSD$

PORTNAME=	wsoundprefs
PORTVERSION=	1.1.1
PORTREVISION=	9
CATEGORIES=	audio windowmaker
MASTER_SITES=	${MASTER_SITE_NETBSD}
DISTNAME=	WSoundPrefs-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A utility for configuring sounds to play for Window Maker events

DEPRECATED=	Depends on the deprecated audio/wsoundserver and expired x11-toolkits/libdockapp
EXPIRATION_DATE=	2012-11-27

BUILD_DEPENDS=	wmaker:${PORTSDIR}/x11-wm/windowmaker
LIB_DEPENDS=	PropList.2:${PORTSDIR}/devel/libPropList \
		wsound.1:${PORTSDIR}/audio/wsoundserver
RUN_DEPENDS=	wmaker:${PORTSDIR}/x11-wm/windowmaker

USE_IMAKE=	yes
USE_XORG=	x11 xext
NO_INSTALL_MANPAGES=yes

.include <bsd.port.mk>
