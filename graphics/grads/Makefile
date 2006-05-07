# New ports collection makefile for:	GrADS
# Date created:		25 October 2002
# Whom:			Greg Lewis <glewis@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	grads
PORTVERSION=	1.9b3
CATEGORIES=	graphics science math
MASTER_SITES=	ftp://grads.iges.org/grads/1.9/:src \
		ftp://grads.iges.org/grads/:other
DISTNAME=	${PORTNAME}-${PORTVERSION}
DISTFILES=	${DISTNAME}-src${EXTRACT_SUFX}:src \
		example.tar.gz:other
EXTRACT_ONLY=	${DISTNAME}-src${EXTRACT_SUFX}

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	The Grid Analysis and Display System

BUILD_DEPENDS=	${LOCALBASE}/lib/libudunits.a:${PORTSDIR}/science/udunits \
		${X11BASE}/lib/libsx.a:${PORTSDIR}/x11/libsx
LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		SUPPLIBS="${LOCALBASE}"
CONFIGURE_ARGS+=	--enable-dyn-supplibs \
			--with-readline \
			--with-printim \
			--with-gui \
			--with-x

OPTIONS=	HDF "Build hdf-support (only hdf OR netcdf is supported)" on \
		NETCDF "Build netcdf-support" off

.include <bsd.port.pre.mk>

.if defined(WITH_HDF)
LIB_DEPENDS+=		mfhdf.2:${PORTSDIR}/science/hdf
CONFIGURE_ARGS+=	--with-hdf
PLIST_SUB+=		NETCDF="@comment " HDF=""
.endif

.if defined(WITH_NETCDF)
LIB_DEPENDS+=		netcdf.1:${PORTSDIR}/science/netcdf
CONFIGURE_ARGS+=	--with-nc
PLIST_SUB+=		NETCDF="" HDF="@comment "
.endif

post-extract:
	${MKDIR} "${WRKSRC}/examples"
	cd "${WRKSRC}/examples" && ${TAR} -xzf "${DISTDIR}/example.tar.gz"

post-configure:
	${REINPLACE_CMD} -e "s:%%DATADIR%%:${DATADIR}:" ${WRKSRC}/src/gx.h

post-install:
	${MKDIR} "${DATADIR}"
	cd ${WRKSRC}/data && ${FIND} . \
		| ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} "${DATADIR}"
	${MKDIR} "${EXAMPLESDIR}"
	cd ${WRKSRC}/examples && ${FIND} . \
		| ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} "${EXAMPLESDIR}"
.if !defined(NOPORTDOCS)
	${MKDIR} "${DOCSDIR}"
	cd ${WRKSRC}/doc && ${FIND} . \
		| ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} "${DOCSDIR}"
.endif

.include <bsd.port.post.mk>
