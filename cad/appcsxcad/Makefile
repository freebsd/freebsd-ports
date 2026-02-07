PORTNAME=	appcsxcad
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.3
PORTREVISION=	1
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Minimal GUI Application using the QCSXCAD library
WWW=		https://github.com/thliebig/AppCSXCAD

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libCSXCAD.so:cad/csxcad \
		libhdf5.so:science/hdf5 \
		libQCSXCAD.so:cad/qcsxcad \
		libvtkCommonCore-${VTK_VER}.so:math/vtk${VTK_VER:R}

USES=		cmake gl pkgconfig qt:5 xorg
USE_QT=		core gui opengl widgets xml buildtools:build qmake:build
USE_GL=		opengl
USE_XORG=	ice sm x11 xext xt
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	thliebig
GH_PROJECT=	AppCSXCAD

CMAKE_ARGS=	-DVTK_DIR=${LOCALBASE}/lib/cmake/vtk-${VTK_VER}

PLIST_FILES=	bin/AppCSXCAD

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/bin/AppCSXCAD.sh # shell script is only needed for Matlab

# an example of file that AppCSXCAD opens (zipped): http://openems.de/forum/download/file.php?id=418&sid=6daebbb2df72b415fa2ec7031ffa6ca9

.include <../../math/vtk9/Makefile.version>
.include <bsd.port.mk>
