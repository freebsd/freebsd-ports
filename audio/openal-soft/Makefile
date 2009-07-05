# New ports collection makefile for:	openal-soft
# Date created:		2009-02-01
# Whom:			Marcus von Appen <mva@sysfault.org>
#
# $FreeBSD$
#

PORTNAME=	openal-soft
PORTVERSION=	1.8.466
CATEGORIES=	audio
MASTER_SITES=	http://kcat.strangesoft.net/openal-releases/

MAINTAINER=	mva@FreeBSD.org
COMMENT=	A software implementation of the OpenAL specification

CONFLICTS=	openal-200[0-9]*

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_LDCONFIG=	yes
CMAKE_USE_PTHREAD=	yes
CMAKE_ARGS+=	-DALSA:BOOL=OFF -DPORTAUDIO:BOOL=OFF -DSOLARIS:BOOL=OFF \
		-DDSOUND:BOOL=OFF

OPTIONS=	PULSEAUDIO	"Enable sound streaming using PulseAudio" off

.include <bsd.port.pre.mk>

.if defined(WITH_PULSEAUDIO)
LIB_DEPENDS+=	pulse-simple.0:${PORTSDIR}/audio/pulseaudio
CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib"
CMAKE_ARGS+=	-DPULSEAUDIO:BOOL=ON
.else
CMAKE_ARGS+=	-DPULSEAUDIO:BOOL=OFF
.endif

.include <bsd.port.post.mk>
