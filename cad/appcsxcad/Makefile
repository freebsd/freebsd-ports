PORTNAME=	appcsxcad
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.2-9
DISTVERSIONSUFFIX=	-g97ba30e
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Minimal GUI Application using the QCSXCAD library

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libCSXCAD.so:cad/csxcad \
		libexpat.so:textproc/expat2 \
		libfreetype.so:print/freetype2 \
		libhdf5.so:science/hdf5 \
		libpng16.so:graphics/png \
		libQCSXCAD.so:cad/qcsxcad \
		libsz.so:science/libaec \
		libtiff.so:graphics/tiff \
		libvtkCommonCore-9.1.so:math/vtk9

USES=		cmake jpeg pkgconfig qt:5 xorg
USE_QT=		core gui sql widgets xml buildtools_build qmake_build
USE_XORG=	ice sm x11 xext xt
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	thliebig
GH_PROJECT=	AppCSXCAD

CMAKE_ARGS=	-DVTK_DIR=${LOCALBASE}/lib/cmake/vtk-9.1

PLIST_FILES=	bin/AppCSXCAD

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/bin/AppCSXCAD.sh # shell script is only needed for Matlab

# an example of file that AppCSXCAD opens (zipped): http://openems.de/forum/download/file.php?id=418&sid=6daebbb2df72b415fa2ec7031ffa6ca9

.include <bsd.port.mk>
