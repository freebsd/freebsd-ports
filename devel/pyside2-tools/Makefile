PORTNAME=	pyside2-tools
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	devel
MASTER_SITES=	QT/official_releases/QtForPython/shiboken2/PySide2-${DISTVERSION}-src
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyside-setup-opensource-src-${DISTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Pyside2 development tools
WWW=		https://wiki.qt.io/Qt_for_Python

LICENSE=	BSD3CLAUSE GPLv2
LICENSE_COMB=	multi

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		git>0:devel/git
LIB_DEPENDS=	libshiboken2.cpython-${PYTHON_SUFFIX}${PYTHON_ABIVER}.so:devel/shiboken2@${PY_FLAVOR} \
		libpyside2.cpython-${PYTHON_SUFFIX}${PYTHON_ABIVER}.so:devel/pyside2@${PY_FLAVOR}

USES=		cmake gl python qt:5 shebangfix tar:xz xorg
USE_GL=		gl
USE_PYTHON=	flavors
USE_QT=		3d buildtools charts core datavis3d declarative \
		designer gui help location multimedia network opengl \
		printsupport qmake:build script scripttools scxml sensors \
		speech sql svg testlib uitools webchannel \
		websockets widgets x11extras xml xmlpatterns

SHEBANG_FILES=	pyside_tool.py

CMAKE_ARGS+=	"-DUSE_PYTHON_VERSION=${PYTHON_VER}"

WRKSRC=		${WRKDIR}/pyside-setup-opensource-src-${DISTVERSION:C/^([0-9].[0-9]+.[0-9])(.[0-9])?/\1/}/sources/pyside2-tools

OPTIONS_DEFINE_i386=	WEBENGINE
OPTIONS_DEFINE_amd64=	WEBENGINE
OPTIONS_DEFAULT_i386=	WEBENGINE
OPTIONS_DEFAULT_amd64=	WEBENGINE

WEBENGINE_DESC=	Enable QtWebEngine support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MWEBENGINE}
USE_QT+=	webengine
.else
CMAKE_ARGS+=	-DDISABLE_QtWebEngine:BOOL=TRUE
.endif

.include <bsd.port.mk>
