PORTNAME=	qcoro
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.0
CATEGORIES=	devel kde
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Coroutines for Qt
WWW=		https://github.com/danvratil/qcoro

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSES/MIT.txt

FLAVORS=	qt5 qt6
FLAVOR?=	qt5

USES=		cmake compiler:c++20-lang gl pkgconfig qt:${FLAVOR:S/qt//}
USE_GITHUB=	yes
GH_ACCOUNT=	danvratil
_USE_GL_qt5=	# empty
_USE_GL_qt6=	opengl
USE_GL=		${_USE_GL_${FLAVOR}}
_USE_QT_qt5=	core dbus declarative gui network websockets \
		buildtools:build concurrent:build qmake:build testlib:build
_USE_QT_qt6=	base declarative websockets
USE_QT=		${_USE_QT_${FLAVOR}}

CMAKE_OFF=	QCORO_BUILD_EXAMPLES
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_ARGS=	-DUSE_QT_VERSION=${FLAVOR:S/qt//}

PLIST_SUB=	QT_VER=${FLAVOR:S/qt//} \
		SHORTVER=${DISTVERSION:R:R} \
		FULLVER=${DISTVERSION}

.include <bsd.port.options.mk>

.if ${ARCH:Mpowerpc*}
USES+=		llvm:min=16
.endif

.include <bsd.port.mk>
