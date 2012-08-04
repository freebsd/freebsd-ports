# New ports collection makefile for:	glui
# Date created:		25 September 2001
# Whom:			mwest@uct.ac.za
#
# $FreeBSD$
#

PORTNAME=	glui
PORTVERSION=	2.36
PORTREVISION=	1
CATEGORIES=	devel graphics
MASTER_SITES=	SF/${PORTNAME}/Source/${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GLUT-based C++ user interface library

USE_GL=		glut
USE_GMAKE=	yes
USE_XORG=	xmu xext x11 xi
USE_LDCONFIG=	yes
MAKEFILE=	makefile

WRKSRC=		${WRKDIR}/${DISTNAME}/src

PLIST_FILES=	include/glui.h lib/libglui.a lib/libglui.so lib/libglui.so.0
PORTDOCS=	*

do-install:
	${INSTALL_DATA} ${WRKSRC}/include/GL/glui.h ${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/lib/libglui.a ${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/lib/libglui.so ${PREFIX}/lib/libglui.so.0
	${LN} -s libglui.so.0 ${PREFIX}/lib/libglui.so
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/glui_manual.pdf ${DOCSDIR}/
.endif

.include <bsd.port.mk>
