# New ports collection makefile for:	liteamp
# Date created:		24 June 2003
# Whom:			Hye-Shik Chang <perky@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	liteamp
PORTVERSION=	0.2.3.2
PORTREVISION=	3
CATEGORIES=	audio gnome
MASTER_SITES=	http://download.kldp.net/liteamp/

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Light-weight Music Player for GNOME2

LIB_DEPENDS=	ao.3:${PORTSDIR}/audio/libao \
		mad.2:${PORTSDIR}/audio/mad \
		vorbisfile.4:${PORTSDIR}/audio/libvorbis

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	libgnomeui gnomeprefix
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	LDFLAGS="-L${LOCALBASE}/lib" CPPFLAGS="-I${LOCALBASE}/include"

MAN1=		liteamp.1

post-patch:
	${REINPLACE_CMD} -e '15s,^,#include <pthread.h>,' \
		${WRKSRC}/src/decoder.c

.include <bsd.port.mk>
