# New ports collection makefile for:	ssystem
# Version required:			1.4
# Date created:				4 August 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.3 1998/09/26 23:34:33 steve Exp $
#

DISTNAME=	ssystem-1.4
CATEGORIES=	astro
MASTER_SITES=	http://www1.las.es/~amil/ssystem/ \
		http://www.msu.edu/~kamelkev/

MAINTAINER=	andy@icc.surw.chel.su

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		MesaGL.14:${PORTSDIR}/graphics/Mesa3 \
		MesaGLU.14:${PORTSDIR}/graphics/Mesa3 \
		glut.3:${PORTSDIR}/graphics/Mesa3

USE_X_PREFIX=	yes

FETCH_BEFORE_ARGS=	-b

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
