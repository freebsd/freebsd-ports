# New ports collection makefile for:	glasteroids
# Date created:				16 August 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	glasteroids
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	http://www.honors.montana.edu/~jjc/Glasteroids/
DISTNAME=	Glasteriods

MAINTAINER=	ports@FreeBSD.org

MAKEFILE=	Makefile.FreeBSD

WRKSRC=		${WRKDIR}/Glasteroids

USE_X_PREFIX=	yes
MAKE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}"
USE_MESA=	yes

pre-build:
	@ ${CP} ${FILESDIR}/Makefile.FreeBSD ${WRKSRC}

do-install:
	@ ${INSTALL_PROGRAM} -m 2755 -o root -g games ${WRKSRC}/Glasteroids ${PREFIX}/bin/glasteroids
	@ ${MKDIR} ${PREFIX}/share/glasteroids
	@ ${INSTALL_DATA} ${WRKSRC}/gameText.txf ${PREFIX}/share/glasteroids
	@ cd ${WRKSRC}; tar -cf - scores.txt textures | \
		( cd ${PREFIX}/share/glasteroids; tar -xf - )
	@ ${CHMOD} a+rx ${PREFIX}/share/glasteroids/textures
	@ ${CHMOD} g+rw,a-x ${PREFIX}/share/glasteroids/scores.txt
	@ ${CHOWN} root:games ${PREFIX}/share/glasteroids/scores.txt

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/glasteroids
	@ ${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/glasteroids
	@ ${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/glasteroids
.endif

.include <bsd.port.mk>
