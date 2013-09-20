# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	impact
PORTVERSION=	0.7.06.038
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	cad java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Version%20${PORTVERSION} \
		SF/nemysisfreebsdp/:icons
DISTFILES=	Impact-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	Impact-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dynamic Finite Element Program Suite

LICENSE=	GPLv2

RUN_DEPENDS=	java3d>0:${PORTSDIR}/java/java3d

WRKSRC=		${WRKDIR}/Impact

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes

DATADIR=	${JAVASHAREDIR}/Impact

SUB_FILES=	impact impactgui

PLIST_FILES=	bin/impact \
		bin/impactgui \
		share/pixmaps/impact.png

OPTIONS_DEFINE=	GMSH

GMSH_DESC=	Enable automatic 3D finite element mesh generator

DESKTOP_ENTRIES="Impact" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}gui" "Graphics;3DGraphics;Education;" false

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGMSH}
RUN_DEPENDS+=	gmsh:${PORTSDIR}/cad/gmsh
.endif

post-extract:
	@${FIND} ${WRKSRC} -name CVS -type d -print0 -or -name .cvsignore -type f -print0 | \
		${XARGS} -0 ${RM} -rf

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/impact ${WRKDIR}/impactgui ${PREFIX}/bin
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${DATADIR})

post-install:
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps

	@${FIND} ${DATADIR} ! -type d | \
		${SED} 's|^${PREFIX}/||' >> ${TMPPLIST}
	@${FIND} ${DATADIR} -type d | ${SORT} -r | \
		${SED} 's|^${PREFIX}/|@dirrm |' >> ${TMPPLIST}

.include <bsd.port.mk>
