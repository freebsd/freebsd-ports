PORTNAME=	mirtk
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.0-179
PORTREVISION=	1
DISTVERSIONSUFFIX=	-gef71a17
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Medical Image Registration ToolKit (MIRTK)
WWW=		https://mirtk.github.io/ \
		https://github.com/BioMedIA/MIRTK

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs \
		nifticlib>0:science/nifticlib
LIB_DEPENDS=	libpng16.so:graphics/png

USES=		cmake compiler:c++11-lang eigen:3 perl5 python
USE_CXXSTD=	c++14
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	BioMedIA
GH_PROJECT=	${PORTNAME:tu}

OPTIONS_DEFINE=		TBB VTK
OPTIONS_DEFAULT=	TBB #VTK

TBB_DESC=		Build with TBB
TBB_CMAKE_BOOL=		WITH_TBB
TBB_LIB_DEPENDS=	libtbb.so:devel/onetbb

VTK_DESC=		Build with the VTK toolkit
VTK_CMAKE_BOOL=		WITH_VTK
VTK_LIB_DEPENDS=	libvtkCommonCore-${VTK_VER}.so:math/vtk${VTK_VER:R} \
			libexpat.so:textproc/expat2
VTK_BROKEN=		causes compilation failure due to use of deprecated feature using std::bind1st, see https://github.com/BioMedIA/MIRTK/issues/789

.include <../../math/vtk9/Makefile.version>
.include <bsd.port.mk>
