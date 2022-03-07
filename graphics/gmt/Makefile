PORTNAME=	gmt
DISTVERSION=	6.3.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/GenericMappingTools/${PORTNAME}/releases/download/${DISTVERSION}/
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Generic Mapping Tools - data processing and display software package

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

LIB_DEPENDS=	libnetcdf.so:science/netcdf \
		libcurl.so:ftp/curl \
		libpcre2-8.so:devel/pcre2 \
		libgdal.so:graphics/gdal \
		libgeos.so:graphics/geos
RUN_DEPENDS=	bash:shells/bash \
		GraphicsMagick>0:graphics/GraphicsMagick \
		ffmpeg>0:multimedia/ffmpeg \
		xdg-open:devel/xdg-utils \

BUILD_DEPENDS=	${LOCALBASE}/share/dcw-gmt/dcw-gmt.nc:graphics/gmt-dcw \
		${LOCALBASE}/share/gshhg-gmt/binned_GSHHS_c.nc:graphics/gmt-gshhg

USES=		blaslapack cmake ghostscript:run shebangfix tar:xz
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

#SHEBANG_GLOB=	*.sh *.in
#SHEBANG_FILES=	share/tools/ncdeflate src/img/img2google src/gmtswitch

CMAKE_ARGS+=	-DDCW_ROOT=${LOCALBASE}/share/dcw-gmt \
		-DCOPY_DCW=off \
		-DGSHHG_ROOT=${LOCALBASE}/share/gshhg-gmt \
		-DCOPY_GSHHG=off \
		-DGMT_DATADIR=share/${PORTNAME} \
		-DGMT_DOCDIR=share/doc/${PORTNAME} \
		-DGMT_MANDIR=share/doc/${PORTNAME}/man \
		-DGMT_EXCLUDE_PCRE=True

.include <bsd.port.mk>
