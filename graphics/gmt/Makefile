# $FreeBSD$

PORTNAME=	gmt
DISTVERSION=	6.1.1
PORTREVISION=	2
CATEGORIES=	graphics

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Generic Mapping Tools - data processing and display software package

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

LIB_DEPENDS=	libnetcdf.so:science/netcdf \
		libcurl.so:ftp/curl \
		libpcre.so:devel/pcre \
		libfftw3f_threads.so:math/fftw3-float \
		libgdal.so:graphics/gdal \
		libgeos.so:graphics/geos
RUN_DEPENDS=	bash:shells/bash \
		GraphicsMagick>0:graphics/GraphicsMagick \
		ffmpeg>0:multimedia/ffmpeg \
		xdg-open:devel/xdg-utils \

BUILD_DEPENDS=	${LOCALBASE}/share/dcw-gmt/dcw-gmt.nc:graphics/gmt-dcw \
		${LOCALBASE}/share/gshhg-gmt/binned_GSHHS_c.nc:graphics/gmt-gshhg

USES=		blaslapack cmake ghostscript:run shebangfix
USE_GITHUB=	yes
USE_LDCONFIG=	yes

GH_ACCOUNT=	GenericMappingTools

#SHEBANG_GLOB=	*.sh *.in
#SHEBANG_FILES=	share/tools/ncdeflate src/img/img2google src/gmtswitch

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=RelWithDebInfo \
		-DCMAKE_INSTALL_PREFIX=${PREFIX} \
		-DDCW_ROOT=${LOCALBASE}/share/dcw-gmt \
		-DCOPY_DCW=off \
		-DGSHHG_ROOT=${LOCALBASE}/share/gshhg-gmt \
		-DCOPY_GSHHG=off \
		-DGMT_DATADIR=share/${PORTNAME} \
		-DGMT_DOCDIR=share/doc/${PORTNAME} \
		-DGMT_MANDIR=share/doc/${PORTNAME}/man

.include <bsd.port.mk>
