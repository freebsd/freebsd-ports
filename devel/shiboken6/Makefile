PORTNAME=	shiboken6
DISTVERSION=	${QT6_VERSION}
CATEGORIES=	devel
MASTER_SITES=	QT/official_releases/QtForPython/${PORTNAME}/PySide6-${DISTVERSION}-src
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyside-setup-opensource-src-${DISTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python binding generator for C++ libraries
WWW=		http://qt-project.org

LICENSE=	GPLv2 LGPL21 LGPL3
LICENSE_COMB=	multi

BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers \
		llvm${LLVM_DEFAULT}>0:devel/llvm${LLVM_DEFAULT} \
		git>0:devel/git \
		${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx
LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader \
		libLLVM.so:devel/llvm${LLVM_DEFAULT} \
		libxslt.so:textproc/libxslt

USES=		cmake compiler:c++17-lang gnome localbase python shebangfix tar:xz qt:6
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
USE_PYTHON=	flavors
USE_QT=		5compat base declarative doc imageformats quick3d quicktimeline networkauth shadertools svg tools translations wayland

#SHEBANG_FILES=	shiboken_tool.py

CMAKE_ARGS+=	-DClang_DIR:PATH="${LOCALBASE}/llvm${LLVM_DEFAULT}/lib/cmake/clang" \
		-DLLVM_DIR:PATH="${LOCALBASE}/llvm${LLVM_DEFAULT}/lib/cmake/llvm" \
		-DCMAKE_CXX_FLAGS=-lexecinfo \
		-DCMAKE_STANDARD_LIBRARIES=-lexecinfo \
		-DCMAKE_CXX_STANDARD_LIBRARIES=-lexecinfo \
		-DUSE_PYTHON_VERSION=${PYTHON_VER}


.include <bsd.port.pre.mk>

PLIST_SUB+=	DISTVERSION=${DISTVERSION}
PLIST_SUB+=	PYVERSTR=.cpython-${PYTHON_SUFFIX}${PYTHON_ABIVER}
WRKSRC=		${WRKDIR}/pyside-setup-opensource-src-${DISTVERSION}/sources/shiboken6

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/shiboken_tool.py
.include <bsd.port.post.mk>
