PORTNAME=	pyside6-tools
DISTVERSION=	${QT6_VERSION}
CATEGORIES=	devel
MASTER_SITES=	QT/official_releases/QtForPython/shiboken6/PySide6-${DISTVERSION}-src
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyside-setup-opensource-src-${DISTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Pyside6 development tools
WWW:		https://wiki.qt.io/Qt_for_Python

LICENSE=	BSD3CLAUSE GPLv2
LICENSE_COMB=	multi

BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers \
		git>0:devel/git
LIB_DEPENDS=	libshiboken6.abi${PYTHON_MAJOR_VER}.so:devel/shiboken6@${PY_FLAVOR} \
		libpyside6.abi${PYTHON_MAJOR_VER}.so:devel/pyside6@${PY_FLAVOR} \
		libxkbcommon.so:x11/libxkbcommon \
		libzstd.so:archivers/zstd \
		libLLVM-${LLVM_DEFAULT}.so:devel/llvm${LLVM_DEFAULT}

USES=		cmake gl python:3.5+ qt:6 shebangfix tar:xz xorg
USE_GL=		gl
USE_PYTHON=	flavors
USE_QT=		base tools languageserver declarative

SHEBANG_FILES=	pyside_tool.py qtpy2cpp_lib/tests/baseline/basic_test.py

CMAKE_ARGS+=	-DQT6_INSTALL_PREFIX=${LOCALBASE}/lib/qt6 \
		-DCMAKE_EXECUTABLE_SUFFIX=6

PLIST_FILES=	bin/pyside_tool.py

.include <bsd.port.pre.mk>

WRKSRC=		${WRKDIR}/pyside-setup-opensource-src-${DISTVERSION}/sources/pyside-tools

#.if ${ARCH} == amd64 || ${ARCH} == i386
#USE_QT+=	webengine
#.endif

.include <bsd.port.post.mk>
