# New ports collection makefile for:	CDPlayer.app
# Date created:				13 Sep 2000
# Whom:					Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$
#

PORTNAME=	cdplayer.app
PORTVERSION=	1.7
PORTREVISION=	1
CATEGORIES=	audio windowmaker
MASTER_SITES=	http://tucows.mirror.ish.de/linux/files/ \
		http://linux.iconet.com.br/files/
DISTNAME=	CDPlayer.app-${PORTVERSION}

MAINTAINER=	dsh@vlink.ru
COMMENT=	A CD player with CDDB support resembling OpenStep's OmniCD

LIB_DEPENDS=	PropList.2:${PORTSDIR}/devel/libPropList \
		cdaudio.1:${PORTSDIR}/audio/libcdaudio \
		wraster.4:${PORTSDIR}/x11-wm/windowmaker

USE_X_PREFIX=	yes

.include <bsd.port.mk>
