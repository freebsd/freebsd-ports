# Created by: sec@42.org
# $FreeBSD$

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
USES=		gmake
USE_BZIP2=	yes
USE_AUTOTOOLS=	autoconf
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--datadir=${DATADIR}
USE_XORG=	x11 xaw xmu xt
MAKE_JOBS_UNSAFE=	yes

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

NETCDF_LIB_DEPENDS=	libnetcdf.so:${PORTSDIR}/science/netcdf4
NETCDF_CONFIGURE_ON=	--enable-netcdf
DEBUG_CONFIGURE_ON=	--enable-debug --enable-devdebug
SHARED_CONFIGURE_ON=	--enable-shared
IMPERIAL_CONFIGURE_ON=	--enable-US
EPS_CONFNIGURE_ON=	--enable-eps
GDAL_LIB_DEPENDS=	libgdal.so:${PORTSDIR}/graphics/gdal
GDAL_CONFIGURE_ON=	--enable-gdal
OCTAVE_RUN_DEPENDS=	octave:${PORTSDIR}/math/octave
OCTAVE_CONFIGURE_ON=	--enable-octave --enable-mex
OCTAVE_CONFIGURE_OFF=	--disable-mex

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSHARED}
USE_LDCONFIG=	yes
.endif

INSTALL_TARGET=		install-gmt install-data install-man install-doc

.if ${ARCH} == "amd64" || ${ARCH} == "ia64" || ${ARCH} == "sparc64"
CONFIGURE_ARGS+=	--enable-64
.else
CONFIGURE_ARGS+=	--disable-64
.endif

.include <bsd.port.mk>
