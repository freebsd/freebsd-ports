# New ports collection makefile for:	gmt
# Date created:		10 May 2001
# Whom:			sec@42.org
#
# $FreeBSD$
#

PORTNAME=	gmt
PORTVERSION=	4.5.8
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	ftp://falcon.grdl.noaa.gov/pub/${PORTNAME}/	\
		ftp://ftp.soest.hawaii.edu/${PORTNAME}/		\
		ftp://ftp.geologi.uio.no/pub/${PORTNAME}/	\
		ftp://ibis.grdl.noaa.gov/pub/${PORTNAME}/	\
		ftp://gd.tuwien.ac.at/pub/${PORTNAME}/		\
		ftp://ftp.iag.usp.br/pub/${PORTNAME}/		\
		ftp://ftp.scc.u-tokai.ac.jp/pub/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Generic Mapping Tools data processing and display software package

WRKSRC=		${WRKDIR}/${PORTNAME:U}${DISTVERSION}
USE_BZIP2=	yes
USE_AUTOTOOLS=	autoconf
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--datadir=${DATADIR}
USE_GMAKE=	yes
USE_XORG=	x11 xaw xmu xt

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	SHARED EPS DEBUG IMPERIAL GDAL NETCDF OCTAVE
OPTIONS_DEFAULT=	SHARED GDAL NETCDF
SHARED_DESC=	Build shared (dynamic) libraries
EPS_DESC=	defaults .eps, otherwise .ps
IMPERIAL_DESC=	Choose Imperial (inch) units over metric (cm)
GDAL_DESC=	Compile in experimental GDAL support
NETCDF_DESC=	With netCDF (7) support
OCTAVE_DESC=	With OCTAVE support

.include "Makefile.man"
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNETCDF}
LIB_DEPENDS+=		netcdf:${PORTSDIR}/science/netcdf4
CONFIGURE_ARGS+=	--enable-netcdf
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-debug --enable-devdebug
.endif

.if ${PORT_OPTIONS:MDEVDEBUG}
CONFIGURE_ARGS+=	--enable-devdebug
.endif

.if ${PORT_OPTIONS:MSHARED}
USE_LDCONFIG=		yes
CONFIGURE_ARGS+=	--enable-shared
.endif

.if ${PORT_OPTIONS:MIMPERIAL}
CONFIGURE_ARGS+=	--enable-US
.endif

.if ${PORT_OPTIONS:MEPS}
CONFIGURE_ARGS+=	--enable-eps
.endif

.if ${PORT_OPTIONS:MGDAL}
LIB_DEPENDS+=		gdal.17:${PORTSDIR}/graphics/gdal
CONFIGURE_ARGS+=	--enable-gdal
.endif

.if ${PORT_OPTIONS:MOCTAVE}
RUN_DEPENDS+=		octave:${PORTSDIR}/math/octave
CONFIGURE_ARGS+=	--enable-octave
CONFIGURE_ARGS+=	--enable-mex
.else
CONFIGURE_ARGS+=	--disable-mex
.endif

INSTALL_TARGET=		install-gmt install-data install-man install-doc

.if ${ARCH} == "amd64" || ${ARCH} == "ia64" || \
    ${ARCH} == "alpha" || ${ARCH} == "sparc64"
CONFIGURE_ARGS+=	--enable-64
.else
CONFIGURE_ARGS+=	--disable-64
.endif

.include <bsd.port.mk>
