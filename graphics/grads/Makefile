# Created by: Greg Lewis <glewis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	grads
PORTVERSION=	1.9b4
PORTREVISION=	14
CATEGORIES=	graphics science math
MASTER_SITES=	ftp://grads.iges.org/grads/1.9/:src \
		ftp://cola.gmu.edu/grads/1.9/:src \
		ftp://grads.iges.org/grads/:other \
		ftp://cola.gmu.edu/grads/:other
DISTFILES=	${PORTNAME}-src-${PORTVERSION}${EXTRACT_SUFX}:src \
		example.tar.gz:other
EXTRACT_ONLY=	${PORTNAME}-src-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	The Grid Analysis and Display System

BUILD_DEPENDS=	${LOCALBASE}/lib/libudunits2.a:science/udunits \
		${LOCALBASE}/lib/libsx.a:x11/libsx
LIB_DEPENDS=	libgd.so:graphics/gd \
		libpng.so:graphics/png

USES=		jpeg ncurses
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		SUPPLIBS="${LOCALBASE}"
CONFIGURE_ARGS+=	--enable-dyn-supplibs \
			--with-readline \
			--with-printim \
			--with-gui \
			--with-x

OPTIONS_DEFINE=	HDF NETCDF DOCS EXAMPLES
OPTIONS_DEFAULT=	NETCDF
HDF_DESC=	Build hdf-support (only hdf OR netcdf is supported)
NETCDF_DESC=	Build netcdf-support

PORTDATA=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	*
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
PORTEXAMPLES=	*
.endif

.if ${PORT_OPTIONS:MHDF}
BROKEN=			Fails to package
LIB_DEPENDS+=		libmfhdf.so:science/hdf
CONFIGURE_ARGS+=	--with-hdf
PLIST_SUB+=		NETCDF="@comment " HDF=""
.endif

.if ${PORT_OPTIONS:MNETCDF}
LIB_DEPENDS+=		libnetcdf.so:science/netcdf
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
	${MKDIR} "${STAGEDIR}${DATADIR}"
	cd ${WRKSRC}/data && ${COPYTREE_SHARE} . "${STAGEDIR}${DATADIR}"
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} "${STAGEDIR}${EXAMPLESDIR}"
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . "${STAGEDIR}${EXAMPLESDIR}"
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} "${STAGEDIR}${DOCSDIR}"
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . "${STAGEDIR}${DOCSDIR}"
.endif

.include <bsd.port.mk>
