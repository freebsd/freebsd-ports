# New ports collection makefile for:	KnightCap
# Version required:			3.5
# Date created:				10 May 1998
# Whom:					Andrey Zakhvatov
#
# $Id$
#

DISTNAME=	KnightCap-3.5
PKGNAME=	knightcap-3.5
CATEGORIES=	games x11
MASTER_SITES=	ftp://samba.anu.edu.au/pub/KnightCap/

MAINTAINER=	andy@icc.surw.chel.su

LIB_DEPENDS=	MesaGL\\.13\\.:${PORTSDIR}/graphics/Mesa \
		MesaGLU\\.13\\.:${PORTSDIR}/graphics/Mesa \
		glut\\.3\\.:${PORTSDIR}/graphics/Mesa

FETCH_BEFORE_ARGS=	-P
ALL_TARGET=	KnightCap
USE_X11=	yes
WRKSRC=		${WRKDIR}/Export

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/KnightCap ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/KnightCap
	@ ${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/KnightCap
.endif

.include <bsd.port.mk>
