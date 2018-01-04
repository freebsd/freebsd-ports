# $FreeBSD$

PORTNAME=	Carla
DISTVERSION=	1.9.7b-279
DISTVERSIONSUFFIX=	-g3758c005
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Audio LV2 plugin host for Jack and PulseAudio

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/GPL.txt

LIB_DEPENDS=	liblo.so:audio/liblo \
		libsndfile.so:audio/libsndfile
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyliblo>0:audio/py-pyliblo@${PY_FLAVOR}

USES=		compiler:c++11-lib desktop-file-utils gmake localbase \
		pkgconfig pyqt:5 python:3.4+ shared-mime-info tar:bz2
USE_GITHUB=	yes
GH_ACCOUNT=	falkTX
USE_PYQT=	core_run gui_run svg_run widgets_run sip_build xml_build
USE_GNOME=	gtk20 gtk30
USE_QT5=	core gui widgets buildtools_build
USE_XORG=	x11
USE_LDCONFIG=	${PREFIX}/lib/carla

MAKE_ARGS=	BSD=true \
		HAVE_QT4=false \
		EXTERNAL_PLUGINS=false

OPTIONS_DEFINE=		FFMPEG FLUIDSYNTH LINUXSAMPLER
OPTIONS_DEFAULT=	FFMPEG FLUIDSYNTH JACK LINUXSAMPLER
OPTIONS_MULTI=		BACKEND
OPTIONS_MULTI_BACKEND=	JACK PULSEAUDIO
BACKEND_DESC=		Audio backend
LINUXSAMPLER_DESC=	Use LinuxSampler: a software audio sampler

FFMPEG_LIB_DEPENDS=		libavutil.so:multimedia/ffmpeg
FFMPEG_MAKE_ARGS_OFF=		HAVE_FFMPEG=false
FLUIDSYNTH_LIB_DEPENDS=		libfluidsynth.so:audio/fluidsynth
FLUIDSYNTH_MAKE_ARGS_OFF=	HAVE_FLUIDSYNTH=false
LINUXSAMPLER_LIB_DEPENDS=	liblinuxsampler.so:audio/linuxsampler
LINUXSAMPLER_MAKE_ARGS_OFF=	HAVE_LINUXSAMPLER=false
JACK_RUN_DEPENDS=		${LOCALBASE}/lib/libjack.so:audio/jack
PULSEAUDIO_LIB_DEPENDS=		libpulse-simple.so:audio/pulseaudio
PULSEAUDIO_MAKE_ARGS_OFF=	HAVE_PULSEAUDIO=false

post-install:
	@${REINPLACE_CMD} -i '' -e 's|^PYTHON=.*|PYTHON=${PYTHON_CMD}|' ${STAGEDIR}${PREFIX}/bin/carla*

devel-features: patch
	@${ECHO} "Developer command: show build features"
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} features

.include <bsd.port.mk>
