# ex:ts=8
# Ports collection makefile for:	mhWaveEdit
# Date created:			Apr 19, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	mhwaveedit
PORTVERSION=	1.4.19
CATEGORIES=	audio
MASTER_SITES=	http://download.gna.org/mhwaveedit/

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	A graphical program for editing sound files

USE_BZIP2=	yes
USE_GNOME=	gnomehack gnometarget gtk20
WANT_GNOME=	yes
WANT_SDL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-optimization --without-alsalib

PLIST_FILES=	bin/mhwaveedit \
		share/locale/de/LC_MESSAGES/mhwaveedit.mo \
		share/locale/es/LC_MESSAGES/mhwaveedit.mo \
		share/locale/fr/LC_MESSAGES/mhwaveedit.mo \
		share/locale/it/LC_MESSAGES/mhwaveedit.mo \
		share/locale/ru/LC_MESSAGES/mhwaveedit.mo \
		share/locale/sv/LC_MESSAGES/mhwaveedit.mo \
		share/locale/zh_CN/LC_MESSAGES/mhwaveedit.mo \
		share/applications/mhwaveedit.desktop \
		share/pixmaps/mhwaveedit.xpm

PLIST_DIRS=	share/applications

OPTIONS=	DOUBLE_SAMPLES "increase quality for 24/32-bit samplerates" off \
		SNDFILE "libsndfile support" on \
		SAMPLERATE "libsamplerate support" on \
		OSS "OSS sound driver" on \
		PORTAUDIO "PortAudio sound driver" off \
		SDL "SDL sound driver" off \
		ARTS "arts sound driver" off \
		JACK "JACK sound driver" off \
		ESD "EsounD sound driver" off \
		LADSPA "LADSPA support" off

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.if defined(WITH_DOUBLE_SAMPLES)
CONFIGURE_ARGS+=	--with-double-samples
.endif

.if defined(WITHOUT_SNDFILE)
CONFIGURE_ARGS+=	--without-libsndfile
.else
LIB_DEPENDS+=	sndfile.1:${PORTSDIR}/audio/libsndfile
.endif

.if defined(WITHOUT_SAMPLERATE)
CONFIGURE_ARGS+=	--without-libsamplerate
.else
LIB_DEPENDS+=	samplerate.1:${PORTSDIR}/audio/libsamplerate
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

.if defined(WITH_ARTS)
LIB_DEPENDS+=	artsc.0:${PORTSDIR}/audio/arts
.else
CONFIGURE_ARGS+=	--without-arts
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

.if defined(WITH_LADSPA)
BUILD_DEPENDS+=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
RUN_DEPENDS+=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
.else
CONFIGURE_ENV+=	ac_cv_header_ladspa_h=no
.endif

post-extract:
	@${CHMOD} +x ${WRKSRC}/install-sh

post-patch:
	@${REINPLACE_CMD} -e '/AM_CFLAGS=/s|-g||g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
