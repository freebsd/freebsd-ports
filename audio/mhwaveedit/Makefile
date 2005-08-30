# ex:ts=8
# Ports collection makefile for:	mhWaveEdit
# Date created:			Apr 19, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	mhwaveedit
PORTVERSION=	1.4.4
CATEGORIES=	audio
MASTER_SITES=	http://download.gna.org/mhwaveedit/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A graphical program for editing sound files

USE_BZIP2=	yes
USE_GNOME=	gnomehack gnometarget gtk20
WANT_GNOME=	yes
WANT_SDL=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-optimization --without-alsalib

PLIST_FILES=	bin/mhwaveedit \
		share/locale/fr/LC_MESSAGES/mhwaveedit.mo \
		share/locale/ru/LC_MESSAGES/mhwaveedit.mo \
		share/locale/sv/LC_MESSAGES/mhwaveedit.mo

OPTIONS=	DOUBLE_SAMPLES "increase quality for 24/32-bit samplerates" off \
		SNDFILE "libsndfile support" on \
		SAMPLERATE "libsamplerate support" on \
		OSS "OSS sound driver" on \
		PORTAUDIO "PortAudio sound driver" off \
		SDL "SDL sound driver" off \
		JACK "JACK sound driver" off \
		ESD "EsounD sound driver" off

.include <bsd.port.pre.mk>

.if defined(WITH_DOUBLE_SAMPLES)
CONFIGURE_ARGS+=	--with-double-samples
.endif

.if defined(WITH_SNDFILE)
LIB_DEPENDS+=	sndfile.1:${PORTSDIR}/audio/libsndfile
.else
CONFIGURE_ARGS+=	--without-libsndfile
.endif

.if defined(WITH_SAMPLERATE)
LIB_DEPENDS+=	samplerate.1:${PORTSDIR}/audio/libsamplerate
.else
CONFIGURE_ARGS+=	--without-libsamplerate
.endif

.if defined(WITHOUT_OSS)
CONFIGURE_ARGS+=	--without-oss
.endif

.if defined(WITH_PORTAUDIO)
LIB_DEPENDS+=	portaudio.0:${PORTSDIR}/audio/portaudio
.else
CONFIGURE_ARGS+=	--without-portaudio
.endif

.if defined(WITH_SDL)
USE_SDL+=	sdl
.else
CONFIGURE_ARGS+=	--without-sdl
.endif

.if defined(WITH_JACK)
LIB_DEPENDS+=	jack.0:${PORTSDIR}/audio/jack
.else
CONFIGURE_ARGS+=	--without-jack
.endif

.if defined(WITH_ESD)
USE_GNOME+=	esound
.else
CONFIGURE_ARGS+=	--without-esound
.endif

.if exists(${LOCALBASE}/include/ladspa.h)
RUN_DEPENDS+=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^AM_CFLAGS=|#AM_CFLAGS=|g ; \
		 s|-ldl||g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
