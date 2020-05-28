# $FreeBSD$

PORTNAME=	shiboken2
DISTVERSION=	5.14.2.2
CATEGORIES=	devel
MASTER_SITES=	QT/official_releases/QtForPython/shiboken2/PySide2-${DISTVERSION}-src
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyside-setup-opensource-src-${DISTVERSION}

MAINTAINER=	cmt@FreeBSD.org
COMMENT=	Python binding generator for C++ libraries

LICENSE=	GPLv2 LGPL21 LGPL3
LICENSE_COMB=	multi

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR} \
		git>0:devel/git
LIB_DEPENDS=	libclang.so:devel/llvm${LLVM_DEFAULT} \
		libxslt.so:textproc/libxslt

USES=		cmake compiler:c++11-lang gnome python:3.5+ qt:5 shebangfix tar:xz
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
USE_PYTHON=	flavors
USE_QT=		buildtools_build core gui network qmake_build testlib \
		xml xmlpatterns

SHEBANG_FILES=	shiboken_tool.py

CONFIGURE_ENV+=	LLVM_CONFIG=${LOCALBASE}/bin/llvm-config${LLVM_DEFAULT}
CMAKE_ARGS+=	"-DCMAKE_CXX_FLAGS=-lexecinfo" \
		"-DCMAKE_STANDARD_LIBRARIES=-lexecinfo" \
		"-DCMAKE_CXX_STANDARD_LIBRARIES=-lexecinfo" \
		"-DUSE_PYTHON_VERSION=${PYTHON_VER}"

.include <bsd.port.pre.mk>

PLIST_SUB+=	DISTVERSION=${DISTVERSION}
PLIST_SUB+=	PYVERSTR=.cpython-${PYTHON_SUFFIX}${PYTHON_ABIVER}

WRKSRC=		${WRKDIR}/pyside-setup-opensource-src-${DISTVERSION:C/^([0-9].[0-9]+.[0-9])(.[0-9])?/\1/}/sources/shiboken2

.include <bsd.port.post.mk>
