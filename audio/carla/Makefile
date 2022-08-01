PORTNAME=	Carla
DISTVERSIONPREFIX=	v
DISTVERSION=	2.5.0
CATEGORIES=	audio

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	5aba957f3cf0fb4dcef4d2add679603e6c048fb4.diff:-p1

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Audio plugin host for Jack and PulseAudio

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/GPL.txt

LIB_DEPENDS=	liblo.so:audio/liblo \
		libsndfile.so:audio/libsndfile
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyliblo>0:audio/py-pyliblo@${PY_FLAVOR}

USES=		compiler:c++11-lib desktop-file-utils gl gmake gnome localbase \
		pkgconfig pyqt:5 python:3.4+ qt:5 sdl shared-mime-info shebangfix \
		tar:bz2 xorg
USE_PYQT=	pyqt5 sip
USE_GNOME=	gtk20 gtk30
USE_QT=		core gui widgets buildtools_build
USE_GL=		gl
USE_XORG=	x11
USE_SDL=	sdl2
USE_LDCONFIG=	${PREFIX}/lib/carla

CONFLICTS_BUILD=	rtaudio rtmidi

SHEBANG_FILES=	data/carla-single data/carla-bridge-lv2-modgui source/native-plugins/resources/* source/frontend/*

USE_GITHUB=	yes
GH_ACCOUNT=	falkTX

MAKE_ARGS=	HAVE_QT4=false \
		EXTERNAL_PLUGINS=false \
		PREFIX=${LOCALBASE}
# Give the Makefile the proper versioned binaries of PyQt
BINARY_ALIAS=	pyuic5=${LOCALBASE}/bin/pyuic5-${PYTHON_VER} \
		pyrcc5=${LOCALBASE}/bin/pyrcc5-${PYTHON_VER}

OPTIONS_DEFINE=		FFMPEG FLUIDSYNTH LINUXSAMPLER
OPTIONS_DEFAULT=	FFMPEG FLUIDSYNTH JACK
OPTIONS_DEFAULT_amd64=	LINUXSAMPLER
OPTIONS_DEFAULT_i386=	LINUXSAMPLER
OPTIONS_MULTI=		BACKEND
OPTIONS_MULTI_BACKEND=	JACK PULSEAUDIO
BACKEND_DESC=		Audio backend

FFMPEG_LIB_DEPENDS=		libavutil.so:multimedia/ffmpeg
FFMPEG_MAKE_ARGS_OFF=		HAVE_FFMPEG=false

FLUIDSYNTH_LIB_DEPENDS=		libfluidsynth.so:audio/fluidsynth
FLUIDSYNTH_MAKE_ARGS_OFF=	HAVE_FLUIDSYNTH=false

LINUXSAMPLER_DESC=		Use LinuxSampler: a software audio sampler
LINUXSAMPLER_LIB_DEPENDS=	liblinuxsampler.so:audio/linuxsampler
LINUXSAMPLER_MAKE_ARGS_OFF=	HAVE_LINUXSAMPLER=false

JACK_BUILD_DEPENDS=		jackit>0:audio/jack
JACK_RUN_DEPENDS=		${LOCALBASE}/lib/libjack.so:audio/jack
JACK_MAKE_ARGS_OFF=		HAVE_JACK=false

PULSEAUDIO_LIB_DEPENDS=		libpulse-simple.so:audio/pulseaudio
PULSEAUDIO_MAKE_ARGS_OFF=	HAVE_PULSEAUDIO=false

CFLAGS_powerpc64le=	-DEEL_TARGET_PORTABLE
CFLAGS_powerpc64=	-DEEL_TARGET_PORTABLE
CFLAGS_powerpc=	-DEEL_TARGET_PORTABLE

post-install:
	@${REINPLACE_CMD} -i '' -e ' \
		s|^PYTHON=.*|PYTHON=${PYTHON_CMD}|; \
		s|#!/bin/bash|#!/bin/sh|' \
		${STAGEDIR}${PREFIX}/bin/carla*
	${RMDIR} ${STAGEDIR}${PREFIX}/share/carla/resources/translations

devel-features: patch
	@${ECHO} "Developer command: show build features"
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} features

.include <bsd.port.mk>
