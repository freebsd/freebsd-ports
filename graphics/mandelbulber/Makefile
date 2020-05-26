# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mandelbulber
DISTVERSION=	2.21
CATEGORIES=	graphics

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	3D Mandelbrot fractal renderer

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgsl.so:math/gsl \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		liblzo2.so:archivers/lzo2

USE_GITHUB=	yes
GH_ACCOUNT=	buddhi1980
GH_PROJECT=	${PORTNAME}2

USES=		cmake compiler:c++11-lang gnome jpeg localbase:ldflags \
		pkgconfig qt:5
USE_QT=		core widgets network gui multimedia testlib \
		qmake_build buildtools_build uitools_build
INSTALLS_ICONS=	yes

CMAKE_SOURCE_PATH=	${WRKSRC}/mandelbulber2/cmake

PORTDOCS=	CONTRIBUTING.md README.md RESOURCES.md
PORTDATA=	*
DATADIR=	${PREFIX}/share/${PORTNAME}2

OPTIONS_DEFINE=	OPENCL OPENMP DOCS
OPTIONS_EXCLUDE=	OPENMP  # not properly supported yet

OPENCL_BUILD_DEPENDS=	opencl>=0:devel/opencl

post-patch-OPENMP-off:
	@${REINPLACE_CMD} -e 's|-fopenmp||' \
		${CMAKE_SOURCE_PATH}/CMakeLists.txt

post-patch-OPENCL-off:
	@${REINPLACE_CMD} -e '/find_package.*OpenCL/ d' \
		${CMAKE_SOURCE_PATH}/CMakeLists.txt

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
