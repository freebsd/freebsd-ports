# New ports collection makefile for:	glasteroids
# Date created:				16 August 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	glasteroids
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.honors.montana.edu/~jjc/Glasteroids/
DISTNAME=	Glasteriods

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3D Asteroids game for X Window System

LIB_DEPENDS=	glut.3:${PORTSDIR}/graphics/libglut

WRKSRC=		${WRKDIR}/Glasteroids

USE_X_PREFIX=	yes
USE_GL=		yes
MAKE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
MAKEFILE=	${FILESDIR}/Makefile.FreeBSD

do-install:
	${INSTALL_PROGRAM} -m 2755 -o root -g games ${WRKSRC}/Glasteroids ${PREFIX}/bin/glasteroids
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/gameText.txf ${DATADIR}
	${TAR} -C ${WRKSRC} -cf - scores.txt textures | \
		${TAR} -C ${DATADIR} --unlink -xf -
	@${CHMOD} a+rx ${DATADIR}/textures
	@${CHMOD} g+rw,a-x ${DATADIR}/scores.txt
	@${CHOWN} root:games ${DATADIR}/scores.txt
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
