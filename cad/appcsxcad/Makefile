PORTNAME=	appcsxcad
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.2-7
DISTVERSIONSUFFIX=	-gde8c271
PORTREVISION=	1
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Minimal GUI Application using the QCSXCAD library

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

# many dependencies below are induced by vtk8, but not vtk9
LIB_DEPENDS=	\
		libCSXCAD.so:cad/csxcad \
		libexpat.so:textproc/expat2 \
		libfreetype.so:print/freetype2 \
		libhdf5.so:science/hdf5 \
		libpng16.so:graphics/png \
		libQCSXCAD.so:cad/qcsxcad \
		libsz.so:science/libaec \
		libtiff.so:graphics/tiff \
		libvtkCommonCore-8.2.so:math/vtk8 # some related packages don't support vtk9 yet, see https://github.com/thliebig/QCSXCAD/issues/6#issuecomment-901633240

USES=		cmake jpeg pkgconfig qt:5 xorg
USE_QT=		core gui sql widgets xml buildtools_build qmake_build
USE_XORG=	ice sm x11 xext xt
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	thliebig
GH_PROJECT=	AppCSXCAD

CMAKE_ARGS=	-DVTK_DIR=${LOCALBASE}/lib/vtk-8.2/cmake/vtk-8.2

PLIST_FILES=	bin/AppCSXCAD \
		bin/AppCSXCAD.sh

post-install:
	@${REINPLACE_CMD} -i '' -e 's|#!/bin/bash|#!/bin/sh|' ${STAGEDIR}${PREFIX}/bin/AppCSXCAD.sh

.include <bsd.port.mk>
