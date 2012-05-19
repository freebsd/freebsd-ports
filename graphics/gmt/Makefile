# New ports collection makefile for:	gmt
# Date created:		10 May 2001
# Whom:			sec@42.org
#
# $FreeBSD$
#

PORTNAME=	gmt
PORTVERSION=	4.5.8
PORTREVISION=	2
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

OPTIONS=	SHARED "Build shared (dynamic) libraries" on \
		EPS "defaults .eps, otherwise .ps" off \
		DEBUG "Compile for debugging code" off \
		DEVDEBUG "Extra debugging for developers" off \
		IMPERIAL "Choose Imperial (inch) units over metric (cm)" off \
		GDAL "Compile in experimental GDAL support" on \
		NETCDF "With netCDF (7) support" on \
		OCTAVE "With OCTAVE support" off

.include "Makefile.man"
.include <bsd.port.options.mk>

.if defined(WITH_NETCDF)
LIB_DEPENDS+=		netcdf:${PORTSDIR}/science/netcdf4
CONFIGURE_ARGS+=	--enable-netcdf
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if defined(WITH_DEVDEBUG)
CONFIGURE_ARGS+=	--enable-devdebug
.endif

.if defined(WITH_SHARED)
USE_LDCONFIG=		yes
CONFIGURE_ARGS+=	--enable-shared
.endif

.if defined(WITH_IMPERIAL)
CONFIGURE_ARGS+=	--enable-US
.endif

.if defined(WITH_EPS)
CONFIGURE_ARGS+=	--enable-eps
.endif

.if defined(WITH_GDAL)
LIB_DEPENDS+=		gdal.17:${PORTSDIR}/graphics/gdal
CONFIGURE_ARGS+=	--enable-gdal
.endif

.if defined(WITH_OCTAVE)
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
