PORTNAME=	horizon-eda
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.0
PORTREVISION=	2
CATEGORIES=	cad

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	0d801d4807cbed405998688b361bf0543207f1b1.patch:-p1 # fixes opencascade-7.6.0 compatibility, see https://github.com/horizon-eda/horizon/issues/623

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	EDA package for printed circuit board design

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/boost/optional.hpp:devel/boost-libs \
		cppzmq>0:net/cppzmq \
		glm>0:math/glm
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libepoxy.so:graphics/libepoxy \
		libgit2.so:devel/libgit2 \
		libharfbuzz.so:print/harfbuzz \
		libpng16.so:graphics/png \
		libpodofo.so:graphics/podofo \
		libTKSTEP.so:cad/opencascade \
		libuuid.so:misc/e2fsprogs-libuuid \
		libzip.so:archivers/libzip \
		libzmq.so:net/libzmq4

USES=		gmake gnome localbase pkgconfig python:build sqlite # compiler:c++17-lang
USE_GNOME=	atkmm gdkpixbuf2 gtkmm30 librsvg2

USE_GITHUB=	yes
GH_PROJECT=	horizon

MAKE_ARGS=	DEBUGFLAGS= OPTIMIZE=

BINARY_ALIAS=	python3=${PYTHON_CMD}

LLVM_VER=	12 # workaround for bug#253551
BUILD_DEPENDS+=	clang${LLVM_VER}:devel/llvm${LLVM_VER}
CPP=		clang-cpp${LLVM_VER}
CC=		clang${LLVM_VER}
CXX=		clang++${LLVM_VER}

post-install: # https://github.com/horizon-eda/horizon/issues/558
	cd ${STAGEDIR}${PREFIX}/bin && ${STRIP_CMD} horizon-eda

.include <bsd.port.mk>
