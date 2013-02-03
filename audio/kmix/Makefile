# Created by: Raphael Kubo da Costa <rakuco@FreeBSD.org>
# $FreeBSD$

PORTNAME=		kmix
PORTVERSION=		${KDE4_VERSION}
CATEGORIES=		audio kde
MASTER_SITES=		${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=		KDE

MAINTAINER=		kde@FreeBSD.org
COMMENT=		Sound mixer for KDE

LICENSE=		GPLv2

CONFLICTS_INSTALL=	kdemultimedia-4.[1-8].*

MAKE_JOBS_SAFE=		yes
KDE4_BUILDENV=		yes
USE_KDE4=		automoc4 kdehier kdelibs kdeprefix
USE_QT4=		dbus phonon xml \
			moc_build qmake_build rcc_build uic_build
USE_XZ=			yes

OPTIONS_DEFINE=		ALSA PULSEAUDIO

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MALSA}
LIB_DEPENDS+=		asound.2:${PORTSDIR}/audio/alsa-lib
.else
EXTRA_PATCHES+=		${FILESDIR}/extrapatch-no_alsa
.endif

.if ${PORT_OPTIONS:MPULSEAUDIO}
CMAKE_ARGS+=		-DWITH_Canberra:BOOL=ON \
			-DWITH_PulseAudio:BOOL=ON
LIB_DEPENDS+=		canberra.0:${PORTSDIR}/audio/libcanberra \
			pulse.0:${PORTSDIR}/audio/pulseaudio
USE_GNOME=		glib20
.else
CMAKE_ARGS+=		-DWITH_Canberra:BOOL=OFF \
			-DWITH_PulseAudio:BOOL=OFF
.endif

.include <bsd.port.mk>
