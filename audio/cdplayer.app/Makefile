# New ports collection makefile for:	CDPlayer.app
# Date created:				13 Sep 2000
# Whom:					Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$
#

PORTNAME=	cdplayer.app
PORTVERSION=	1.7
CATEGORIES=	audio windowmaker
MASTER_SITES=	http://shawcable.linux.tucows.com/files/ \
		http://linux.tucows.blueyonder.co.uk/files/
DISTNAME=	CDPlayer.app-${PORTVERSION}

MAINTAINER=	dsh@vlink.ru

LIB_DEPENDS=	PropList.2:${PORTSDIR}/devel/libPropList \
		cdaudio.1:${PORTSDIR}/audio/libcdaudio \
		wraster.4:${PORTSDIR}/x11-wm/windowmaker

USE_X_PREFIX=	yes

.include <bsd.port.mk>
