# New ports collection makefile for:	dssi
# Date created:		2007-01-12
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	dssi
PORTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	dssi

MAINTAINER=	trasz@freebsd.org
COMMENT=	API for audio processing plugins

LIB_DEPENDS=	dssialsacompat.0:${PORTSDIR}/audio/libdssialsacompat \
		lo.6:${PORTSDIR}/audio/liblo \
		jack.0:${PORTSDIR}/audio/jack \
		sndfile.1:${PORTSDIR}/audio/libsndfile \
		samplerate.1:${PORTSDIR}/audio/libsamplerate
BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
RUN_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa

GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
USE_GMAKE=	yes
USE_GNOME=	gnomehack

.if defined(WITH_QT)
USE_QT_VER=	3
PLIST_SUB=	WITH_QT=""
.else
PLIST_SUB=	WITH_QT="@comment "
.endif

.include <bsd.port.mk>
