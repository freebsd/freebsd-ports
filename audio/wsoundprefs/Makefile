# New ports collection makefile for:	WSoundPrefs
# Date created:		12 December 1998
# Whom:			gljohns@bellsouth.net
#
# $FreeBSD$
#

PORTNAME=	wsoundprefs
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	audio windowmaker
MASTER_SITES=	${MASTER_SITE_NETBSD}
DISTNAME=	WSoundPrefs-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A utility for configuring sounds to play for Window Maker events

BUILD_DEPENDS=	wmaker:${PORTSDIR}/x11-wm/windowmaker
LIB_DEPENDS=	PropList.2:${PORTSDIR}/devel/libPropList \
		wsound.1:${PORTSDIR}/audio/wsoundserver
RUN_DEPENDS=	wmaker:${PORTSDIR}/x11-wm/windowmaker

USE_IMAKE=	yes
NO_INSTALL_MANPAGES=yes

.include <bsd.port.mk>
