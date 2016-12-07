# Created by: Sarod Yatawatta <sarod@cs.pdn.ac.lk>
# $FreeBSD$

PORTNAME=	pdnmesh
PORTVERSION=	0.2.2
PORTREVISION=	9
CATEGORIES=	cad
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-source/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mesh generator and solver for Finite Element problems

LICENSE=	GPLv2+

LIB_DEPENDS=	libgtkglext-x11-1.0.so:x11-toolkits/gtkglext

OPTIONS_DEFINE=	ATLAS DOCS EXAMPLES
ATLAS_DESC=	Enable ATLAS support

USES=		fortran pkgconfig
USE_GL=		glu
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
LDFLAGS+=	-lm

DESKTOP_ENTRIES="pdnMesh" "${COMMENT}" "" "${PORTNAME}" "" true

ATLAS_USES=		blaslapack:atlas
ATLAS_CONFIGURE_ON=--with-blas=cblas --with-lapack=alapack
ATLAS_USES_OFF=		blaslapack
ATLAS_CONFIGURE_OFF=--with-blas=blas --with-lapack=lapack

post-patch:
	@${REINPLACE_CMD}-e \
		'/^SUBDIRS/s|doc|| ; \
		 s|^pkgdata_DATA|#pkgdata_DATA|' ${WRKSRC}/Makefile.in

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} \
		&& ${INSTALL_DATA} ChangeLog ${STAGEDIR}${DOCSDIR} \
		&& ${INSTALL_DATA} README ${STAGEDIR}${DOCSDIR})
	${MKDIR} ${STAGEDIR}${DOCSDIR}/tutorial
	(cd ${WRKSRC}/doc/tutorial \
		&& ${INSTALL_DATA} README ${STAGEDIR}${DOCSDIR}/tutorial \
		&& ${INSTALL_DATA} tutorial.* ${STAGEDIR}${DOCSDIR}/tutorial)
post-install-EXAMPLES-on:
	(cd ${WRKSRC}/doc/examples && \
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
	${RM} ${STAGEDIR}${EXAMPLESDIR}/Makefile*

.include <bsd.port.mk>
