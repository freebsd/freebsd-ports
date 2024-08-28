PORTNAME=	rgdal
DISTVERSION=	1.6-7
PORTREVISION=	3
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Bindings for the Geospatial Data Abstraction Library
WWW=		https://cran.r-project.org/web/packages/rgdal/

LICENSE=	GPLv2+

DEPRECATED=	Fails to build and upstream recommends using math/R-cran-sf or math/R-cran-terra instead
EXPIRATION_DATE=	2024-08-30
BROKEN=		does not build

CRAN_DEPENDS=	R-cran-sp>=1.1.0:math/R-cran-sp
BUILD_DEPENDS=	${CRAN_DEPENDS}
LIB_DEPENDS=	libgdal.so:graphics/gdal \
		libproj.so:graphics/proj
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		compiler:c++11-lang cran:auto-plist,compiles pkgconfig

.include <bsd.port.mk>
