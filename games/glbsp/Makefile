# New ports collection makefile for: glbsp
# Date created:		22 Jan 2004
# Whom:			Igor Pokrovsky <tiamat@comset.net>
#
# $FreeBSD$
#

PORTNAME=	glbsp
PORTVERSION=	2.10c
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_src_${PORTVERSION:S/.//}

MAINTAINER=	ip@doom.homeunix.org
COMMENT=	BSP node builder for OpenGL ports of the DOOM game engine

.ifdef (WITH_GUI_VERSION)
LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk
.endif

USE_GMAKE=	yes
USE_REINPLACE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/[[:alpha:]]//}

.if !defined (WITH_GUI_VERSION)
PLIST_SUB=	GUI_VERSION="@comment "
.else
PLIST_SUB=	GUI_VERSION=""
.endif

.ifndef (WITH_GUI_VERSION)
pre-everything::
	@${ECHO_CMD} "***********************************************************"
	@${ECHO_CMD} "Define WITH_GUI_VERSION=yes to build FLTK based GUI version"
	@${ECHO_CMD} "***********************************************************"
.endif

.ifdef (WITH_GUI_VERSION)
post-build:
	${SETENV} CC=${CC} \
		  CXX=${CXX} \
		  CFLAGS="${CFLAGS}" \
		  CXXFLAGS="${CXXFLAGS}" \
		  X11BASE=${X11BASE} \
		  LOCALBASE=${LOCALBASE} \
		${GMAKE} -C ${WRKSRC} -f GUI.mak all
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/glbsp ${PREFIX}/bin
.ifdef (WITH_GUI_VERSION)
	${INSTALL_PROGRAM} ${WRKSRC}/glBSPX ${PREFIX}/bin
.endif

.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/USAGE.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
