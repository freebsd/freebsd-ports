PORTNAME=	midipp
DISTVERSIONPREFIX=	v
DISTVERSION=		2.1.7
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	MIDI playback, recording, and live performance tool
WWW=		https://github.com/hselasky/midipp

LICENSE=	BSD2CLAUSE

USES=		compiler:c++11-lang gl qmake qt:5 tar:bzip2 desktop-file-utils
USE_GL=		gl
USE_QT=		buildtools:build core gui network printsupport widgets

USE_GITHUB=	yes
GH_ACCOUNT=	hselasky

GH_TUPLE=	hselasky:libumidi:v2.1.8:a/libumidi

OPTIONS_DEFINE= DEBUG CDEV ALSAMIDI JACK
OPTIONS_DEFAULT= CDEV ALSAMIDI JACK

QMAKE_ARGS= " HAVE_STATIC=YES"

ALSAMIDI_DESC= MIDI via ALSA
ALSAMIDI_QMAKE_ON= " HAVE_ALSA=YES"
ALSAMIDI_LIB_DEPENDS= libasound.so:audio/alsa-lib

CDEV_DESC= MIDI via raw character device(s)
CDEV_QMAKE_ON= " HAVE_CDEV=YES"

JACK_QMAKE_ON= " HAVE_JACK=YES"
JACK_LIB_DEPENDS= libjack.so:audio/jack

DEBUG_MAKE_ARGS= " HAVE_DEBUG=YES"

PLIST_FILES= \
	bin/midipp \
	share/pixmaps/midipp.png \
	share/applications/midipp.desktop

.include <bsd.port.mk>
