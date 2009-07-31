# New ports collection makefile for:	CDPlayer.app
# Date created:				13 Sep 2000
# Whom:					Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$
#

PORTNAME=	cdplayer.app
PORTVERSION=	1.7
PORTREVISION=	5
CATEGORIES=	audio windowmaker
MASTER_SITES=	http://freebsd.aeternal.net/ports/
DISTNAME=	CDPlayer.app-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A CD player with CDDB support resembling OpenStep's OmniCD

LIB_DEPENDS=	PropList.2:${PORTSDIR}/devel/libPropList \
		cdaudio.1:${PORTSDIR}/audio/libcdaudio \
		wraster.4:${PORTSDIR}/x11-wm/windowmaker

PLIST_FILES=	GNUstep/Apps/CDPlayer.app/CDPlayer
PLIST_DIRS=	GNUstep/Apps/CDPlayer.app GNUstep/Apps

.include <bsd.port.mk>
