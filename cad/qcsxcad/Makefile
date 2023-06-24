PORTNAME=	qcsxcad
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.2-9
PORTREVISION=	4
DISTVERSIONSUFFIX=	-g3f09a8b
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Qt-GUI for CSXCAD
WWW=		https://github.com/thliebig/QCSXCAD

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libCSXCAD.so:cad/csxcad \
		libexpat.so:textproc/expat2 \
		libfreetype.so:print/freetype2 \
		libpng16.so:graphics/png \
		libtiff.so:graphics/tiff \
		libtinyxml.so:textproc/tinyxml \
		libvtkCommonCore-${VTK_VER}.so:math/vtk${VTK_VER:R}

USES=		cmake gl jpeg pkgconfig qt:5 xorg
USE_QT=		core gui opengl sql widgets xml buildtools:build qmake:build
USE_XORG=	ice sm x11 xext xt
USE_GL=		gl opengl
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	thliebig
GH_PROJECT=	${PORTNAME:tu}

CMAKE_ARGS=	-DVTK_DIR=${LOCALBASE}/lib/cmake/vtk-${VTK_VER}

.include <../../math/vtk9/Makefile.version>
.include <bsd.port.mk>
