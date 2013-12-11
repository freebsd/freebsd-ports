# Created by: ijliao
# $FreeBSD$

PORTNAME=	mhwaveedit
PORTVERSION=	1.4.22
CATEGORIES=	audio
MASTER_SITES=	http://download.gna.org/mhwaveedit/

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	A graphical program for editing sound files

LICENSE=	GPLv2

USES=		pkgconfig
NO_STAGE=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack gtk20
WANT_GNOME=	yes
WANT_SDL=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-optimization --without-alsalib \
		--without-arts

PLIST_FILES=	bin/mhwaveedit \
		share/locale/de/LC_MESSAGES/mhwaveedit.mo \
		share/locale/es/LC_MESSAGES/mhwaveedit.mo \
		share/locale/fr/LC_MESSAGES/mhwaveedit.mo \
		share/locale/it/LC_MESSAGES/mhwaveedit.mo \
		share/locale/pl/LC_MESSAGES/mhwaveedit.mo \
		share/locale/ru/LC_MESSAGES/mhwaveedit.mo \
		share/locale/sv/LC_MESSAGES/mhwaveedit.mo \
		share/locale/zh_CN/LC_MESSAGES/mhwaveedit.mo \
		share/applications/mhwaveedit.desktop \
		share/pixmaps/mhwaveedit.xpm

MAN1=		mhwaveedit.1

OPTIONS_DEFINE=	DOUBLE_SAMPLES SNDFILE SAMPLERATE OSS \
		PORTAUDIO SDL JACK \
		ESD PULSEAUDIO LADSPA

DOUBLE_SAMPLES_DESC=	increase quality for 24/32-bit samplerates
SNDFILE_DESC=		libsndfile support
SAMPLERATE_DESC=	libsamplerate support
OSS_DESC=		OSS sound driver
PORTAUDIO_DESC=		PortAudio sound driver
SDL_DESC=		SDL sound driver
JACK_DESC=		JACK sound driver
ESD_DESC=		EsounD sound driver
PULSEAUDIO_DESC=	PULSEAUDIO support
LADSPA_DESC=		LADSPA support

OPTIONS_DEFAULT=SNDFILE SAMPLERATE OSS

.include <bsd.port.options.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.if ${PORT_OPTIONS:MDOUBLE_SAMPLES}
CONFIGURE_ARGS+=	--with-double-samples
.endif

.if empty(PORT_OPTIONS:MSNDFILE)
CONFIGURE_ARGS+=	--without-libsndfile
.else
LIB_DEPENDS+=	libsndfile.so:${PORTSDIR}/audio/libsndfile
.endif

.if empty(PORT_OPTIONS:MSAMPLERATE)
CONFIGURE_ARGS+=	--without-libsamplerate
.else
LIB_DEPENDS+=	libsamplerate.so:${PORTSDIR}/audio/libsamplerate
.endif

.if empty(PORT_OPTIONS:MOSS)
CONFIGURE_ARGS+=	--without-oss
.endif

.if ${PORT_OPTIONS:MPORTAUDIO}
LIB_DEPENDS+=	libportaudio.so:${PORTSDIR}/audio/portaudio
.else
CONFIGURE_ARGS+=	--without-portaudio
.endif

.if ${PORT_OPTIONS:MSDL}
USE_SDL+=	sdl
.else
CONFIGURE_ARGS+=	--without-sdl
.endif

.if ${PORT_OPTIONS:MJACK}
LIB_DEPENDS+=	libjack.so:${PORTSDIR}/audio/jack
.else
CONFIGURE_ARGS+=	--without-jack
.endif

.if ${PORT_OPTIONS:MESD}
USE_GNOME+=	esound
.else
CONFIGURE_ARGS+=	--without-esound
.endif

.if ${PORT_OPTIONS:MPULSEAUDIO}
LIBS_DEPENDS+=	pulse.0:${PORTSDIR}/audio/pulseaudio
CONFIGURE_ARGS+=	--with-pulse
.else
CONFIGURE_ARGS+=	--without-pulse
.endif

.if ${PORT_OPTIONS:MLADSPA}
BUILD_DEPENDS+=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
RUN_DEPENDS+=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
.else
CONFIGURE_ENV+=	ac_cv_header_ladspa_h=no
.endif

post-extract:
	@${CHMOD} +x ${WRKSRC}/install-sh

post-patch:
	@${REINPLACE_CMD} -e '/AM_CFLAGS=/s|-g||g' ${WRKSRC}/configure

.include <bsd.port.mk>
