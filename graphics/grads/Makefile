# Created by: Greg Lewis <glewis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	grads
PORTVERSION=	1.9b4
PORTREVISION=	8
CATEGORIES=	graphics science math
MASTER_SITES=	ftp://grads.iges.org/grads/1.9/:src \
		ftp://grads.iges.org/grads/:other
DISTFILES=	${PORTNAME}-src-${PORTVERSION}${EXTRACT_SUFX}:src \
		example.tar.gz:other
EXTRACT_ONLY=	${PORTNAME}-src-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	The Grid Analysis and Display System

BUILD_DEPENDS=	${LOCALBASE}/lib/libudunits2.a:${PORTSDIR}/science/udunits \
		${LOCALBASE}/lib/libsx.a:${PORTSDIR}/x11/libsx
LIB_DEPENDS=	gd:${PORTSDIR}/graphics/gd \
		jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		SUPPLIBS="${LOCALBASE}"
CONFIGURE_ARGS+=	--enable-dyn-supplibs \
			--with-readline \
			--with-printim \
			--with-gui \
			--with-x

OPTIONS_DEFINE=	HDF NETCDF DOCS EXAMPLES
OPTIONS_DEFAULT=	HDF
HDF_DESC=	Build hdf-support (only hdf OR netcdf is supported)
NETCDF_DESC=	Build netcdf-support

.if !defined(NOPORTDATA)
PORTDATA=	*
.endif

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	*
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
PORTEXAMPLES=	*
.endif

.if ${PORT_OPTIONS:MHDF}
LIB_DEPENDS+=		mfhdf.3:${PORTSDIR}/science/hdf
CONFIGURE_ARGS+=	--with-hdf
PLIST_SUB+=		NETCDF="@comment " HDF=""
.endif

.if ${PORT_OPTIONS:MNETCDF}
LIB_DEPENDS+=		netcdf:${PORTSDIR}/science/netcdf4
CONFIGURE_ARGS+=	--with-nc
PLIST_SUB+=		NETCDF="" HDF="@comment "
.endif

post-extract:
	${MKDIR} "${WRKSRC}/examples"
	cd "${WRKSRC}/examples" && ${TAR} -xzf "${DISTDIR}/example.tar.gz"

post-configure:
	${REINPLACE_CMD} -e "s:%%DATADIR%%:${DATADIR}:" ${WRKSRC}/src/gx.h
	${REINPLACE_CMD} -e "s:ludunits:ludunits2:" ${WRKSRC}/src/Makefile

post-install:
.if !defined(NOPORTDATA)
	${MKDIR} "${DATADIR}"
	cd ${WRKSRC}/data && ${COPYTREE_SHARE} . "${DATADIR}"
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} "${EXAMPLESDIR}"
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . "${EXAMPLESDIR}"
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} "${DOCSDIR}"
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . "${DOCSDIR}"
.endif

.include <bsd.port.mk>
