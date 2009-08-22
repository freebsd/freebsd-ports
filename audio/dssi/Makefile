# New ports collection makefile for:	dssi
# Date created:		2007-01-12
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	dssi
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	API for audio processing plugins

LIB_DEPENDS=	dssialsacompat.0:${PORTSDIR}/audio/libdssialsacompat \
		lo.7:${PORTSDIR}/audio/liblo \
		jack.0:${PORTSDIR}/audio/jack \
		sndfile.1:${PORTSDIR}/audio/libsndfile \
		samplerate.1:${PORTSDIR}/audio/libsamplerate
BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
RUN_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa

GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
USE_GMAKE=	yes
USE_GNOME=	gnomehack
MAN1=		dssi_osc_send.1 dssi_osc_update.1 jack-dssi-host.1

.if defined(WITH_QT)
USE_QT_VER=	3
PLIST_SUB=	WITH_QT=""
.else
PLIST_SUB=	WITH_QT="@comment "
.endif

.include <bsd.port.mk>
