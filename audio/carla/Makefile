# $FreeBSD$

PORTNAME=	Carla
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.0
PORTREVISION=	3
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Audio LV2 plugin host for Jack and PulseAudio

BROKEN=		unfetchable

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/GPL.txt

LIB_DEPENDS=	liblo.so:audio/liblo \
		libsndfile.so:audio/libsndfile
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyliblo>0:audio/py-pyliblo@${PY_FLAVOR}

CONFLICTS_BUILD=	rtaudio-* rtmidi-*

USES=		compiler:c++11-lib desktop-file-utils gl gmake gnome localbase \
		pkgconfig pyqt:5 python:3.4+ qt:5 shared-mime-info shebangfix \
		tar:bz2 xorg
USE_GITHUB=	yes
GH_ACCOUNT=	falkTX
USE_PYQT=	core_run gui_run sip svg_run widgets_run xml_build  # "sip" should be "sip_build", but "import PyQt5.QtCore" wants "sip". See bug#225040
USE_GNOME=	gtk20 gtk30
USE_QT=		core gui widgets buildtools_build
USE_GL=		gl
USE_XORG=	x11
USE_LDCONFIG=	${PREFIX}/lib/carla
SHEBANG_FILES=	data/carla-single source/native-plugins/resources/*

MAKE_ARGS=	HAVE_QT4=false \
		EXTERNAL_PLUGINS=false \
# Give the Makefile the proper versioned binaries of PyQt
BINARY_ALIAS=	pyuic5=${LOCALBASE}/bin/pyuic5-${PYTHON_VER} \
		pyrcc5=${LOCALBASE}/bin/pyrcc5-${PYTHON_VER}

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
	@${REINPLACE_CMD} -i '' -e ' \
		s|^PYTHON=.*|PYTHON=${PYTHON_CMD}|; \
		s|#!/bin/bash|#!/bin/sh|' \
		${STAGEDIR}${PREFIX}/bin/carla*

devel-features: patch
	@${ECHO} "Developer command: show build features"
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} features

.include <bsd.port.mk>
