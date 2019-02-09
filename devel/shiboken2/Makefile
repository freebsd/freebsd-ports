# $FreeBSD$

PORTNAME=	shiboken2
DISTVERSION=	5.12.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_QT}
MASTER_SITE_SUBDIR=	official_releases/QtForPython/shiboken2/PySide2-${DISTVERSION}-src
DISTNAME=	pyside-setup-everywhere-src-${DISTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cmt@FreeBSD.org
COMMENT=	Python binding generator for C++ libraries

LICENSE=	GPLv2 LGPL21 LGPL3
LICENSE_COMB=	multi

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR} \
		git>0:devel/git
LIB_DEPENDS=	libclang.so:devel/llvm${LLVM_DEFAULT} \
		libxslt.so:textproc/libxslt

USES=		cmake gnome python qt:5 shebangfix tar:xz
USE_GNOME=	libxml2
USE_PYTHON=	flavors
USE_QT=		buildtools_build core gui network qmake_build testlib \
		xml xmlpatterns

SHEBANG_FILES=		shiboken_tool.py
python_OLD_COMMAND=	"/usr/bin/env python"

CONFIGURE_ENV+=	LLVM_CONFIG=${LOCALBASE}/bin/llvm-config${LLVM_DEFAULT}
CMAKE_ARGS+=	"-DCMAKE_CXX_FLAGS=-lexecinfo" \
		"-DCMAKE_STANDARD_LIBRARIES=-lexecinfo" \
		"-DCMAKE_CXX_STANDARD_LIBRARIES=-lexecinfo"

PLIST_SUB=	DISTVERSION=${DISTVERSION} \
		PYTHON_VERSION=${PYTHON_VERSION}

WRKSRC=		${WRKDIR}/pyside-setup-everywhere-src-${DISTVERSION}/sources/shiboken2

.include <bsd.port.mk>
