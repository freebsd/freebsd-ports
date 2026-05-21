PORTNAME=	shiboken6-tools
DISTVERSION=	${PYSIDE6_VERSION}
CATEGORIES=	devel
MASTER_SITES=	QT/official_releases/QtForPython/pyside6/PySide6-${DISTVERSION}-src
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyside-setup-everywhere-src-${DISTVERSION}
DIST_SUBDIR=	KDE/Qt/${PYSIDE6_VERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python binding generator for C++ libraries
WWW=		http://qt-project.org

LICENSE=	GPLv2 LGPL21 LGPL3
LICENSE_COMB=	multi

LIB_DEPENDS=	libxslt.so:textproc/libxslt

USES=		cmake compiler:c++17-lang gnome llvm:lib,min=17,max=22,noexport \
		python qt:6 tar:xz
USE_GNOME=	libxml2
USE_LDCONFIG=	${PREFIX}/${PORTNAME}
USE_PYTHON=	flavors
USE_QT=		base

CMAKE_ARGS=	-DClang_DIR:PATH="${LLVM_PREFIX}/lib/cmake/clang" \
		-DLLVM_DIR:PATH="${LLVM_PREFIX}/lib/cmake/llvm" \
		-DUSE_PYTHON_VERSION=${PYTHON_VER} \
		-DBUILD_TESTS:BOOL=false
CONFIGURE_ENV=	LLVM_INSTALL_DIR="${LLVM_PREFIX}/lib/cmake/llvm"

WRKSRC_SUBDIR=	sources/shiboken6_generator
PLIST_SUB=	PYTHON_MAJOR_VER=${PYTHON_MAJOR_VER} \
		SHLIB_VER=${DISTVERSION:R} \
		SHLIB_VERSION=${DISTVERSION}

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/shiboken_tool.py
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-f -d ${PYTHONPREFIX_SITELIBDIR}/shiboken6_generator \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/shiboken6_generator
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-f -d ${PYTHONPREFIX_SITELIBDIR}/shiboken6_generator \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/shiboken6_generator

.include <bsd.port.mk>
