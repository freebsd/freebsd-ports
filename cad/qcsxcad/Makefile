PORTNAME=	qcsxcad
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.2-5
DISTVERSIONSUFFIX=	-g0dabbaf
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Qt-GUI for CSXCAD

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

# many dependencies below are induced by vtk8, but not vtk9
LIB_DEPENDS=	\
		libCSXCAD.so:cad/csxcad \
		libexpat.so:textproc/expat2 \
		libfreetype.so:print/freetype2 \
		libpng16.so:graphics/png \
		libtiff.so:graphics/tiff \
		libtinyxml.so:textproc/tinyxml \
		libvtkCommonCore-8.2.so:math/vtk8

USES=		cmake jpeg pkgconfig qt:5 xorg
USE_QT=		core gui sql widgets xml buildtools_build qmake_build
USE_XORG=	ice sm x11 xext xt
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	thliebig
GH_PROJECT=	${PORTNAME:tu}

CMAKE_ARGS=	-DVTK_DIR=${LOCALBASE}/lib/vtk-8.2/cmake/vtk-8.2

.include <bsd.port.mk>
