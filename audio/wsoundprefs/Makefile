# New ports collection makefile for:	WSoundPrefs
# Date created:		12 December 1998
# Whom:			gljohns@bellsouth.net
#
# $FreeBSD$
#

PORTNAME=	wsoundprefs
PORTVERSION=	1.1.1
CATEGORIES=	audio windowmaker
MASTER_SITES=	ftp://shadowmere.student.utwente.nl/pub/WindowMaker/
DISTNAME=	WSoundPrefs-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org

BUILD_DEPENDS=	wmaker:${PORTSDIR}/x11-wm/windowmaker
LIB_DEPENDS=	PropList.2:${PORTSDIR}/devel/libPropList \
		wsound.1:${PORTSDIR}/audio/wsoundserver
RUN_DEPENDS=	wmaker:${PORTSDIR}/x11-wm/windowmaker

USE_IMAKE=	yes
NO_INSTALL_MANPAGES=yes

.include <bsd.port.mk>
