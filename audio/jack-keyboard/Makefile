# New ports collection makefile for:	jack-keyboard
# Date created:		2007-01-23
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	jack-keyboard
DISTVERSION=	2.6
CATEGORIES=	audio
MASTER_SITES=	SF \
		http://hselasky.homeunix.org:8192/distfiles/

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	Virtual keyboard for JACK MIDI

LICENSE=	BSD

LIB_DEPENDS=	jack.0:${PORTSDIR}/audio/jack

MAN1=		jack-keyboard.1

MAKE_JOBS_SAFE=	yes
USE_GNOME=	gtk20
USE_CMAKE=	yes
INSTALLS_ICONS=	yes

OPTIONS=	LASH "Build with lash support" on

.include <bsd.port.options.mk>

.if defined(WITH_LASH)
LIB_DEPENDS+=	lash.2:${PORTSDIR}/audio/lash
CMAKE_ARGS+=	-DLashEnable:BOOL=On
.else
CMAKE_ARGS+=	-DLashEnable:BOOL=Off
.endif

.include <bsd.port.mk>
