# New ports collection makefile for:	ssystem
# Version required:			1.3
# Date created:				4 August 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.2 1998/09/15 11:45:45 asami Exp $
#

DISTNAME=	ssystem-1.3
CATEGORIES=	astro
MASTER_SITES=	http://www1.las.es/~amil/ssystem/

MAINTAINER=	andy@icc.surw.chel.su

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		MesaGL.14:${PORTSDIR}/graphics/Mesa3 \
		MesaGLU.14:${PORTSDIR}/graphics/Mesa3 \
		glut.3:${PORTSDIR}/graphics/Mesa3

USE_X11=	yes

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/ssystem ${PREFIX}/bin
	@ ${MKDIR} ${PREFIX}/share/ssystem
	@ ${INSTALL_DATA} ${WRKSRC}/*.jpg ${PREFIX}/share/ssystem
	@ ${INSTALL_DATA} ${WRKSRC}/Stars.dat ${PREFIX}/share/ssystem
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/ssystem
.for file in CHANGES LEEME LICENSE README TODO
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/ssystem
.endfor
.endif

.include <bsd.port.mk>
