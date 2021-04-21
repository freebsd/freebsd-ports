PORTNAME=	speech
DISTVERSION=	${QT5_VERSION}
PORTREVISION=	1
CATEGORIES=	accessibility
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Accessibilty features for Qt5

USES=		compiler:c++11-lang gl pkgconfig qmake:outsource,norecursive \
		qt-dist:5,speech xorg
USE_GL=		gl
USE_QT=		core gui buildtools_build qmake_build

OPTIONS_DEFINE=		ALSA
OPTIONS_MULTI=		BACKEND
OPTIONS_MULTI_BACKEND=	SPEECHD FLITE
OPTIONS_DEFAULT=	SPEECHD
OPTIONS_SUB=		yes

SPEECHD_DESC=		Speech Dispatcher Backend
SPEECHD_USES=		gettext-runtime gnome
SPEECHD_USE=		GNOME=glib20
SPEECHD_LIB_DEPENDS=	libspeechd.so:accessibility/speech-dispatcher
SPEECHD_VARS=		QMAKE_CONFIGURE_ARGS+=--feature-speechd
SPEECHD_VARS_OFF=	QMAKE_CONFIGURE_ARGS+=--no-feature-speechd

FLITE_DESC=		Festival Lite Backend
FLITE_LIB_DEPENDS=	libflite.so:audio/flite
FLITE_USE=		QT=multimedia,network
FLITE_VARS=		QMAKE_CONFIGURE_ARGS+=--feature-flite
FLITE_VARS_OFF=		QMAKE_CONFIGURE_ARGS+=--no-feature-flite --no-feature-flite_alsa

ALSA_IMPLIES=		FLITE
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_VARS=		QMAKE_CONFIGURE_ARGS+=--feature-flite_alsa
ALSA_VARS_OFF=		QMAKE_CONFIGURE_ARGS+=--no-feature-flite_alsa

.include <bsd.port.mk>
