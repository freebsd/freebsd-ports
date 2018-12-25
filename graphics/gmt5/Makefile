# $FreeBSD$

PORTNAME=	gmt5
DISTVERSION=	5.4.4
DISTVERSIONSUFFIX=	-src
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.soest.hawaii.edu/%SUBDIR%/ \
		ftp://ftp.geologi.uio.no/pub/%SUBDIR%/ \
		ftp://ftp.iag.usp.br/%SUBDIR%/ \
		ftp://ftp.scc.u-tokai.ac.jp/pub/%SUBDIR%/ \
		http://gd.tuwien.ac.at/graphics/visual/%SUBDIR%/ \
		http://gmt.mirror.ac.za/%SUBDIR%/ \
		ftp://ftp.soest.hawaii.edu/gshhg/:gshhg \
		ftp://ftp.scc.u-tokai.ac.jp/pub/gmt/:gshhg
MASTER_SITE_SUBDIR=	gmt gmt/legacy
DISTNAME=	gmt-${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	lbartoletti@tuxfamily.org
COMMENT=	Generic Mapping Tools - data processing and display software package

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

LIB_DEPENDS=	libnetcdf.so:science/netcdf \
		libcurl.so:ftp/curl \
		libpcre.so:devel/pcre \
		libfftw3f_threads.so:math/fftw3-float \
		libgdal.so:graphics/gdal
RUN_DEPENDS=	bash:shells/bash
BUILD_DEPENDS=	${LOCALBASE}/share/dcw-gmt/dcw-gmt.nc:graphics/gmt5-dcw \
		${LOCALBASE}/share/gshhg-gmt/binned_GSHHS_c.nc:graphics/gmt5-gshhg

WRKSRC=		${WRKDIR}/gmt-${PORTVERSION}

USES=		shebangfix cmake
SHEBANG_GLOB=	*.sh *.in
SHEBANG_FILES=	share/tools/ncdeflate src/img/img2google src/gmtswitch

USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=RelWithDebInfo \
		-DCMAKE_C_FLAGS=-fstrict-aliasing \
		-DCMAKE_INSTALL_PREFIX=${PREFIX} \
		-DDCW_ROOT=${LOCALBASE}/share/gmt5-dcw \
		-DGSHHG_ROOT=${LOCALBASE}/share/gmt5-gshhg \
		-DGMT_INSTALL_MODULE_LINKS=off \
		-DGMT_INSTALL_TRADITIONAL_FOLDERNAMES=off \
		-DGMT_DATADIR=share/${PORTNAME} \
		-DGMT_DOCDIR=share/doc/${PORTNAME} \
		-DGMT_MANDIR=share/doc/${PORTNAME}/man \
		-DGMT_INSTALL_NAME_SUFFIX=-gmt5

.include <bsd.port.mk>
