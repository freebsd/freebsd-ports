# Created by: ijliao
# $FreeBSD$

PORTNAME=	sudoku_solver
PORTVERSION=	1.20
CATEGORIES=	games
MASTER_SITES=	http://www.techfinesse.com/game/
DISTNAME=	solver

MAINTAINER=	rhurlin@gwdg.de
COMMENT=	A Sudoku Solver in C

WRKSRC=		${WRKDIR}/${DISTNAME}_${PORTVERSION}

ALL_TARGET=	# empty

PLIST_FILES=	bin/sudoku_solver

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e "s,^CC,#CC, ; s,^CFLAGS,#CFLAGS," \
		${WRKSRC}/${MAKEFILE}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/sudoku_solver ${PREFIX}/bin

.include <bsd.port.mk>
