# New ports collection makefile for:	ssystem
# Version required:			1.5
# Date created:				4 August 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.4 1998/11/02 03:49:24 steve Exp $
#

DISTNAME=		ssystem-1.5
CATEGORIES=		astro
MASTER_SITES=		http://www1.las.es/~amil/ssystem/ \
			http://www.msu.edu/~kamelkev/
FETCH_BEFORE_ARGS=	-b

MAINTAINER=		andy@icc.surw.chel.su

LIB_DEPENDS=		jpeg.9:${PORTSDIR}/graphics/jpeg \
			MesaGL.14:${PORTSDIR}/graphics/Mesa3 \
			MesaGLU.14:${PORTSDIR}/graphics/Mesa3 \
			glut.3:${PORTSDIR}/graphics/Mesa3

MAKEFILE=		Makefile.FreeBSD

USE_X_PREFIX=		yes

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/ssystem ${PREFIX}/bin
	@ ${MKDIR} ${PREFIX}/share/ssystem
	@ ${INSTALL_DATA} ${WRKSRC}/*.jpg ${PREFIX}/share/ssystem
	@ ${INSTALL_DATA} ${WRKSRC}/stars.dat ${PREFIX}/share/ssystem
	@ ${INSTALL_DATA} ${WRKSRC}/ssystem.conf ${PREFIX}/etc

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/ssystem
.for file in CHANGES LEEME LICENSE README README.3D TODO
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/ssystem
.endfor
.endif

.include <bsd.port.mk>
