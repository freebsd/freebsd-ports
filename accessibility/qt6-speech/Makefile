PORTNAME=	speech
PORTVERSION=	${QT6_VERSION}
PORTREVISION=	1
CATEGORIES=	accessibility
PKGNAMEPREFIX=	qt6-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Accessibilty features for Qt6

USES=		cmake gl pkgconfig qt-dist:6
USE_GL=		gl opengl
USE_QT=		base declarative

OPTIONS_DEFINE=		ALSA
OPTIONS_DEFAULT=	SPEECHD
OPTIONS_GROUP=		BACKEND
OPTIONS_GROUP_BACKEND=	SPEECHD FLITE
OPTIONS_SUB=		yes
FLITE_DESC=		Festival Lite Backend
SPEECHD_DESC=		Speech Dispatcher Backend

ALSA_IMPLIES=		FLITE
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_ALSA

FLITE_LIB_DEPENDS=	libflite.so:audio/flite
FLITE_USE=		QT=multimedia
FLITE_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Flite

SPEECHD_LIB_DEPENDS=	libspeechd.so:accessibility/speech-dispatcher
SPEECHD_USES=		gettext-runtime gnome
SPEECHD_USE=		GNOME=glib20
SPEECHD_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_SpechDispatcher

.include <bsd.port.mk>
