PORTNAME=	horizon-eda
DISTVERSIONPREFIX=	v
DISTVERSION=	2.7.0
PORTREVISION=	2
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	EDA package for printed circuit board design
WWW=		https://horizon-eda.org/ \
		https://github.com/horizon-eda/horizon

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/boost/optional.hpp:devel/boost-libs \
		cmake:devel/cmake-core \
		cppzmq>0:net/cppzmq \
		glm>0:math/glm
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libepoxy.so:graphics/libepoxy \
		libfreeimage.so:graphics/freeimage \
		libgit2.so:devel/libgit2 \
		libpng16.so:graphics/png \
		libpodofo09.so:graphics/podofo09 \
		libspnav.so:misc/libspnav \
		libTKDESTEP.so:cad/opencascade \
		libuuid.so:misc/libuuid \
		libzmq.so:net/libzmq4

USES=		desktop-file-utils gnome libarchive localbase meson pkgconfig python:build sqlite
USE_GNOME=	atkmm gdkpixbuf gtkmm30 librsvg2

USE_GITHUB=	yes
GH_PROJECT=	horizon

BINARY_ALIAS=	python3=${PYTHON_CMD}

# Patch sources to force using include files installed by graphics/podofo09
pre-configure:
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
