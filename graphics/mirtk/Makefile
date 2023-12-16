PORTNAME=	mirtk
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.0-178
PORTREVISION=	10
DISTVERSIONSUFFIX=	-g973ce2f
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Medical Image Registration ToolKit (MIRTK)
WWW=		https://mirtk.github.io/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs \
		nifticlib>0:science/nifticlib
LIB_DEPENDS=	libpng16.so:graphics/png

USES=		cmake compiler:c++11-lang eigen:3 perl5 python
USE_GITHUB=	yes
GH_ACCOUNT=	BioMedIA
GH_PROJECT=	${PORTNAME:tu}
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		TBB VTK
OPTIONS_DEFAULT=	TBB VTK

TBB_DESC=		Build with TBB
TBB_CMAKE_BOOL=		WITH_TBB
TBB_LIB_DEPENDS=	libtbb.so:devel/onetbb

VTK_DESC=		Build with the VTK toolkit
VTK_CMAKE_BOOL=		WITH_VTK
VTK_LIB_DEPENDS=	libvtkCommonCore-${VTK_VER}.so:math/vtk${VTK_VER:R} \
			libexpat.so:textproc/expat2

.include <../../math/vtk9/Makefile.version>
.include <bsd.port.mk>
