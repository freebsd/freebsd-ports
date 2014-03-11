# Created by: sec@42.org
# $FreeBSD$

PORTNAME=	gmt
PORTVERSION=	4.5.12
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.soest.hawaii.edu/%SUBDIR%/ \
		ftp://ftp.geologi.uio.no/pub/%SUBDIR%/ \
		ftp://ftp.iag.usp.br/%SUBDIR%/ \
		ftp://ftp.scc.u-tokai.ac.jp/pub/%SUBDIR%/ \
		http://gd.tuwien.ac.at/graphics/visual/%SUBDIR%/ \
		http://gmt.mirror.ac.za/%SUBDIR%/ \
		ftp://ftp.soest.hawaii.edu/gshhg/:gshhg \
		ftp://ftp.scc.u-tokai.ac.jp/pub/gmt/:gshhg
MASTER_SITE_SUBDIR=	${PORTNAME} ${PORTNAME}/legacy
DISTFILES=	${DISTNAME}-src${EXTRACT_SUFX} \
		${GSHHG_DISTNAME}.tar.gz:gshhg

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generic Mapping Tools - data processing and display software package

LICENSE=	GPLv2 LGPL3
LICENSE_COMB=	multi
LICENSE_DISTFILES_GPLv2=	${DISTNAME}${EXTRACT_SUFX}
LICENSE_DISTFILES_LGPL3=	${GSHHG_DISTNAME}${EXTRACT_SUFX}

LIB_DEPENDS=	libnetcdf.so:${PORTSDIR}/science/netcdf4
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_BZIP2=	yes
USES=		gmake shebangfix
SHEBANG_FILES=	gmtswitch doc/examples/*/*.sh src/GMT.in \
		src/gmt_shell_functions.sh.in src/gmtget.in \
		src/gmtlogo.in src/isogmt.in
USE_AUTOTOOLS=	autoconf
CONFIGURE_ARGS=	--datadir=${DATADIR} \
		--with-gshhg-dir=${DATADIR}/coast
INSTALL_TARGET=	install-gmt install-data install-man install-doc
MAKE_JOBS_UNSAFE=	yes

PORTDOCS=	*

PORTSCOUT=	limitw:0,even

OPTIONS_DEFINE=		DEBUG DOCS EPS GDAL IMPERIAL OCTAVE SHARED X11
OPTIONS_DEFAULT=	GDAL SHARED X11
OPTIONS_SUB=		yes

DEBUG_CONFIGURE_ON=	--enable-debug --enable-devdebug
EPS_DESC=		Set .eps as default output format, otherwise .ps
EPS_CONFNIGURE_ON=	--enable-eps
GDAL_DESC=		Compile in experimental GDAL support
GDAL_LIB_DEPENDS=	libgdal.so:${PORTSDIR}/graphics/gdal
GDAL_CONFIGURE_ON=	--enable-gdal
IMPERIAL_DESC=		Choose Imperial (inch) units over metric (cm)
IMPERIAL_CONFIGURE_ON=	--enable-US
OCTAVE_DESC=		Build GMT-octave interface
OCTAVE_RUN_DEPENDS=	octave:${PORTSDIR}/math/octave
OCTAVE_CONFIGURE_ON=	--enable-octave --enable-mex
OCTAVE_CONFIGURE_OFF=	--disable-mex
SHARED_DESC=		Build shared (dynamic) libraries
SHARED_CONFIGURE_ON=	--enable-shared
SHARED_USE=		LDCONFIG=yes
X11_USE=		XORG=x11,xaw,xmu,xt
X11_CONFIGURE_OFF=	--disable-xgrid

STRIP_FILES=	blockmean blockmedian blockmode filter1d fitcircle \
		gmt2rgb gmtconvert gmtdefaults gmtmath gmtselect \
		gmtset grd2cpt grd2xyz grdblend grdclip \
		grdcontour grdcut grdedit grdfft grdfilter \
		grdgradient grdhisteq grdimage grdinfo grdlandmask \
		grdmask grdmath grdpaste grdproject grdreformat \
		grdsample grdtrack grdtrend grdvector grdview \
		grdvolume greenspline makecpt mapproject minmax \
		nearneighbor project ps2raster psbasemap psclip \
		pscoast pscontour pshistogram psimage pslegend \
		psmask psrose psscale pstext pswiggle \
		psxy psxyz sample1d spectrum1d splitxyz \
		surface trend1d trend2d triangulate xyz2grd

# http://www.soest.hawaii.edu/pwessel/gshhg/
GSHHG_DISTNAME=	gshhg-gmt-2.3.0

.include <bsd.port.options.mk>

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/coast
	(cd ${WRKDIR}/${GSHHG_DISTNAME} && ${INSTALL_DATA} README.TXT *.nc \
		${STAGEDIR}${DATADIR}/coast)
.if ${PORT_OPTIONS:MX11}
	(cd ${WRKSRC}/src/xgrid && ${INSTALL_PROGRAM} xgridedit \
		${STAGEDIR}${PREFIX}/bin)
.endif
.for i in ${STRIP_FILES}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${i}
.endfor

.include <bsd.port.mk>
