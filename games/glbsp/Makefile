# New ports collection makefile for: glbsp
# Date created:		22 Jan 2004
# Whom:			Igor Pokrovsky <tiamat@comset.net>
#
# $FreeBSD$
#

PORTNAME=	glbsp
PORTVERSION=	2.05
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_src_${PORTVERSION:S/.//}

MAINTAINER=	tiamat@comset.net
COMMENT=	BSP node builder for OpenGL ports of the DOOM game engine

.ifdef (WITH_GUI_VERSION)
LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk
.endif

USE_GMAKE=	yes
USE_REINPLACE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

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
post-patch:
	@${REINPLACE_CMD} -e 's|%%FLTK_CONFIG%%|${X11BASE}\/bin\/fltk-config|g' \
		${WRKSRC}/fltk/makefile.unx
.endif

do-build:
	${SETENV} CC=${CC} "CFLAGS=${CFLAGS}" \
		${GMAKE} -C ${WRKSRC}/cmdline -f makefile.unx all
.ifdef (WITH_GUI_VERSION)
	${SETENV} CC=${CC} CXX=${CXX} "CFLAGS=${CFLAGS}" "CXXFLAGS=${CXXFLAGS}" \
		${GMAKE} -C ${WRKSRC}/fltk -f makefile.unx all
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cmdline/glbsp ${PREFIX}/bin
.ifdef (WITH_GUI_VERSION)
	${INSTALL_PROGRAM} ${WRKSRC}/fltk/glBSPX ${PREFIX}/bin
.endif

.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/USAGE.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
