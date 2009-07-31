# New ports collection makefile for:	gmidimonitor
# Date created:		2007-03-20
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	gmidimonitor
PORTVERSION=	3.4
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://download.gna.org/gmidimonitor/

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	GTK+ application that shows MIDI events

LIB_DEPENDS=	jack.0:${PORTSDIR}/audio/jack \
		lash.2:${PORTSDIR}/audio/lash

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-alsamidi
CONFIGURE_ENV=	"CFLAGS=${CFLAGS} -I${LOCALBASE}/include"
USE_GMAKE=	yes
USE_GNOME=	gtk20 libglade2

.include <bsd.port.mk>
