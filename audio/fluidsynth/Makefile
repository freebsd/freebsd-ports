# ports collection makefile for:   fluidsynth
# Date created:        27 Nov 2003
# Whom:                Juha Nygard <juha.nygard1@netikka.fi>
#
# $FreeBSD$
#

PORTNAME=	fluidsynth
PORTVERSION=	1.0.7a
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	fluid

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Real-time software synthesizer based on the SoundFont 2 specifications

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/a//}

USE_GNOME=	gnomehack gnometarget pkgconfig
USE_GETOPT_LONG=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=  yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--disable-lash --disable-ladcca
INSTALLS_SHLIB=	yes

MAN1=		fluidsynth.1

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.if defined(WITH_JACK)
LIB_DEPENDS+=	jack.0:${PORTSDIR}/audio/jack
.else
CONFIGURE_ARGS+=	--disable-jack-support
.endif

.if defined(WITH_LADSPA)
BUILD_DEPENDS+=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
RUN_DEPENDS+=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
CONFIGURE_ARGS+=	--enable-ladspa
.endif

post-patch:
	@${REINPLACE_CMD} -e 's| -O2 | |g ; \
		 s|== "yes"|= "yes"|g' ${WRKSRC}/configure

.include <bsd.port.mk>
