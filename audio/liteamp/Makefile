# New ports collection makefile for:	liteamp
# Date created:		24 June 2003
# Whom:			Hye-Shik Chang <perky@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	liteamp
PORTVERSION=	0.2.3
CATEGORIES=	audio gnome
MASTER_SITES=	http://download.kldp.net/liteamp/

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Light-weight Music Player for GNOME2

LIB_DEPENDS=	ao.3:${PORTSDIR}/audio/libao \
		mad.1:${PORTSDIR}/audio/mad \
		ogg.4:${PORTSDIR}/audio/libogg \
		vorbisfile.3:${PORTSDIR}/audio/libvorbis

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	libgnomeui gnomeprefix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	LDFLAGS="-L${LOCALBASE}/lib" CPPFLAGS="-I${LOCALBASE}/include"

MAN1=		liteamp.1

.include <bsd.port.mk>
