# New ports collection makefile for:	freesweep
# Date created:				25 July 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	freesweep
PORTVERSION=	0.88
CATEGORIES=	games
MASTER_SITES=	http://www.upl.cs.wisc.edu/~hartmann/sweep/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Minesweeper-style game for text-mode terminals

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-prefsdir=${PREFIX}/share/freesweep \
		--with-scoresdir=${PREFIX}/share/freesweep \
		--disable-debug-log
ALL_TARGET=	# empty

MAN6=		freesweep.6

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/freesweep ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/freesweep.6 ${PREFIX}/man/man6
	@${MKDIR} ${PREFIX}/share/freesweep
	${INSTALL_DATA} ${WRKSRC}/sweeprc ${PREFIX}/share/freesweep
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/freesweep
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${PREFIX}/share/doc/freesweep
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/freesweep
.endif

.include <bsd.port.mk>
