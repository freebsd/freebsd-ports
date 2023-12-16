PORTNAME=	horizon-eda
DISTVERSIONPREFIX=	v
DISTVERSION=	2.5.0
PORTREVISION=	2
CATEGORIES=	cad

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	1efad3028a1953af2cf62b518a54ffeb309977bc.patch:-p1 # https://github.com/horizon-eda/horizon/issues/727

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	EDA package for printed circuit board design
WWW=		https://horizon-eda.org/

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
		libpodofo09.so:graphics/podofo09 \
		libTKSTEP.so:cad/opencascade \
		libuuid.so:misc/e2fsprogs-libuuid \
		libzip.so:archivers/libzip \
		libzmq.so:net/libzmq4

USES=		desktop-file-utils gmake gnome libarchive localbase pkgconfig python:build sqlite # compiler:c++17-lang
USE_GNOME=	atkmm gdkpixbuf2 gtkmm30 librsvg2

USE_GITHUB=	yes
GH_PROJECT=	horizon

MAKE_ARGS=	DEBUGFLAGS= OPTIMIZE=

BINARY_ALIAS=	python3=${PYTHON_CMD}

LLVM_VER=	12 # workaround for bug#263870
BUILD_DEPENDS+=	clang${LLVM_VER}:devel/llvm${LLVM_VER}
CPP=		clang-cpp${LLVM_VER}
CC=		clang${LLVM_VER}
CXX=		clang++${LLVM_VER}

# Patch sources to force using include files installed by graphics/podofo09
post-patch:
	@${REINPLACE_CMD} -e '/^#include/s|podofo/podofo.h|podofo09/podofo.h|' \
		${WRKSRC}/src/export_pdf/export_pdf.cpp \
		${WRKSRC}/src/export_pdf/export_pdf_board.cpp \
		${WRKSRC}/src/python_module/board.cpp \
		${WRKSRC}/src/python_module/schematic.cpp \
		${WRKSRC}/src/imp/pdf_export_window.cpp \
		${WRKSRC}/src/export_pdf/export_pdf_util.hpp \
		${WRKSRC}/src/export_pdf/canvas_pdf.hpp

post-install: # https://github.com/horizon-eda/horizon/issues/558
	@cd ${STAGEDIR}${PREFIX}/bin && ${STRIP_CMD} horizon-eda horizon-imp

.include <bsd.port.mk>
