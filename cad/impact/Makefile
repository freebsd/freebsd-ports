PORTNAME=	impact
PORTVERSION=	0.7.06.038
PORTREVISION=	4
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
WWW=		https://impact.sourceforge.net/

LICENSE=	GPLv2

DEPRECATED=	Does not work as intended	# PR 288493
EXPIRATION_DATE=2025-10-31

RUN_DEPENDS=	java3d>0:java/java3d

USES=		java zip

WRKSRC=		${WRKDIR}/Impact

NO_BUILD=	yes

DATADIR=	${JAVASHAREDIR}/Impact

SUB_FILES=	impact impactgui

PLIST_FILES=	bin/impact \
		bin/impactgui \
		share/pixmaps/impact.png \
		${DATADIR_REL}/.classpath \
		${DATADIR_REL}/.project \
		${DATADIR_REL}/.vcm_meta
PORTDATA=	*

DESKTOP_ENTRIES="Impact" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}gui" "Graphics;3DGraphics;Education;" false

OPTIONS_DEFINE=	GMSH

GMSH_DESC=		Automatic 3D finite element mesh generator
GMSH_RUN_DEPENDS=	gmsh:cad/gmsh

post-extract:
	@${FIND} ${WRKSRC} -name CVS -type d -print0 -or -name .cvsignore -type f -print0 | \
		${XARGS} -0 ${RM} -r

do-install:
	(cd ${WRKDIR} && ${INSTALL_SCRIPT} impact impactgui \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
