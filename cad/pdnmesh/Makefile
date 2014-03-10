# Created by: Sarod Yatawatta <sarod@cs.pdn.ac.lk>
# $FreeBSD$

PORTNAME=	pdnmesh
PORTVERSION=	0.2.2
PORTREVISION=	7
CATEGORIES=	cad
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-source/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mesh generator and solver for Finite Element problems

LICENSE=	GPLv2 # (or later)

LIB_DEPENDS=	libgtkglext-x11-1.0.so:${PORTSDIR}/x11-toolkits/gtkglext

OPTIONS_DEFINE=	ATLAS DOCS EXAMPLES
ATLAS_DESC=	Enable ATLAS support

USES=		fortran pkgconfig
USE_GL=		glu
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
LDFLAGS+=	-lm

DESKTOP_ENTRIES="pdnMesh" "${COMMENT}" "" "${PORTNAME}" "" "true"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MATLAS}
LIB_DEPENDS+=	libatlas.so:${PORTSDIR}/math/atlas
CONFIGURE_ARGS+=--with-blas=cblas --with-lapack=alapack
.else
LIB_DEPENDS+=	libblas.so:${PORTSDIR}/math/blas
LIB_DEPENDS+=	liblapack.so:${PORTSDIR}/math/lapack
CONFIGURE_ARGS+=--with-blas=blas --with-lapack=lapack
.endif

post-patch:
	@${REINPLACE_CMD}-e \
		'/^SUBDIRS/s|doc|| ; \
		 s|^pkgdata_DATA|#pkgdata_DATA|' ${WRKSRC}/Makefile.in

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} \
		&& ${INSTALL_DATA} ChangeLog ${STAGEDIR}${DOCSDIR} \
		&& ${INSTALL_DATA} README ${STAGEDIR}${DOCSDIR})
	${MKDIR} ${STAGEDIR}${DOCSDIR}/tutorial
	(cd ${WRKSRC}/doc/tutorial \
		&& ${INSTALL_DATA} README ${STAGEDIR}${DOCSDIR}/tutorial \
		&& ${INSTALL_DATA} tutorial.* ${STAGEDIR}${DOCSDIR}/tutorial)
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	(cd ${WRKSRC}/doc/examples && \
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
	${RM} ${STAGEDIR}${EXAMPLESDIR}/Makefile*
.endif

.include <bsd.port.mk>
