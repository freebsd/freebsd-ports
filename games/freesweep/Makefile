# New ports collection makefile for:	freesweep
# Version required:			0.86
# Date created:				25 July 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=	freesweep-0.86
CATEGORIES=	games
MASTER_SITES=	http://www.upl.cs.wisc.edu/~hartmann/sweep/

MAINTAINER=	andy@icc.surw.chel.su

ALL_TARGET=
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN6=		freesweep.6

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/freesweep ${PREFIX}/bin
	@ ${INSTALL_MAN} ${WRKSRC}/freesweep.6 ${PREFIX}/man/man6

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/freesweep
	@ ${INSTALL_DATA} ${WRKSRC}/CHANGES ${PREFIX}/share/doc/freesweep
	@ ${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/freesweep
.endif

.include <bsd.port.mk>
