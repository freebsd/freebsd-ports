# New ports collection makefile for:	ssystem
# Version required:			1.6
# Date created:				4 August 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=		ssystem-1.6
CATEGORIES=		astro
MASTER_SITES=		http://plasma.gsfc.nasa.gov/Ssystem/ \
			http://www.wam.umd.edu/~kamelkev/Ssystem/ \
			http://www.wam.umd.edu/~kamelkev/

MAINTAINER=		ports@FreeBSD.org

LIB_DEPENDS=		jpeg.9:${PORTSDIR}/graphics/jpeg \
			GL.14:${PORTSDIR}/graphics/Mesa3 \
			GLU.14:${PORTSDIR}/graphics/Mesa3 \
			glut.3:${PORTSDIR}/graphics/Mesa3

MAKEFILE=		Makefile.FreeBSD
FETCH_BEFORE_ARGS=	-b
USE_X_PREFIX=		yes
USE_BISON=		yes

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
