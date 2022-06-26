PORTNAME=	qcsxcad
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.2-9
DISTVERSIONSUFFIX=	-g3f09a8b
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Qt-GUI for CSXCAD

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libCSXCAD.so:cad/csxcad \
		libexpat.so:textproc/expat2 \
		libfreetype.so:print/freetype2 \
		libpng16.so:graphics/png \
		libtiff.so:graphics/tiff \
		libtinyxml.so:textproc/tinyxml \
		libvtkCommonCore-9.1.so:math/vtk9

USES=		cmake gl jpeg pkgconfig qt:5 xorg
USE_QT=		core gui opengl sql widgets xml buildtools_build qmake_build
USE_XORG=	ice sm x11 xext xt
USE_GL=		gl opengl
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	thliebig
GH_PROJECT=	${PORTNAME:tu}

CMAKE_ARGS=	-DVTK_DIR=${LOCALBASE}/lib/cmake/vtk-9.1

.include <bsd.port.mk>
