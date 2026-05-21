PORTNAME=	speech
DISTVERSION=	${QT6_VERSION}
CATEGORIES=	accessibility
PKGNAMEPREFIX=	qt6-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Accessibilty features for Qt6

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cyclonedx-python-lib>0:textproc/py-cyclonedx-python-lib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spdx-tools>=0.8.3:misc/py-spdx-tools@${PY_FLAVOR} \
		vulkan-headers>=1.4:graphics/vulkan-headers

USES=		cmake compiler:c++17-lang gl pkgconfig python:build qt-dist:6
USE_GL=		opengl
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}
USE_QT=		base declarative multimedia

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
FLITE_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Flite

SPEECHD_LIB_DEPENDS=	libspeechd.so:accessibility/speech-dispatcher
SPEECHD_USES=		gettext-runtime gnome
SPEECHD_USE=		GNOME=glib20
SPEECHD_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_SpechDispatcher

.include <bsd.port.mk>
