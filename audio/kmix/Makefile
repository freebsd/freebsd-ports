# Created by: Raphael Kubo da Costa <rakuco@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kmix
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	2
CATEGORIES=	audio kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Sound mixer for KDE

LICENSE=	GPLv2

USES=		cmake:outsource tar:xz
USE_KDE4=	automoc4 kdehier kdelibs kdeprefix
USE_QT4=	gui phonon xml \
		moc_build qmake_build rcc_build uic_build

OPTIONS_DEFINE=	ALSA PULSEAUDIO

ALSA_LIB_DEPENDS=	libasound.so:${PORTSDIR}/audio/alsa-lib
ALSA_EXTRA_PATCHES=	${FILESDIR}/extrapatch-no_alsa

PULSEAUDIO_LIB_DEPENDS=	libcanberra.so:${PORTSDIR}/audio/libcanberra \
			libpulse.so:${PORTSDIR}/audio/pulseaudio
PULSEAUDIO_USE=		GNOME=glib20
PULSEAUDIO_CMAKE_ON=	-DWITH_Canberra:BOOL=ON \
			-DWITH_PulseAudio:BOOL=ON
PULSEAUDIO_CMAKE_OFF=	-DWITH_Canberra:BOOL=OFF \
			-DWITH_PulseAudio:BOOL=OFF

.include <bsd.port.mk>
