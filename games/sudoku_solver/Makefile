# ex:ts=8
# Ports collection makefile for:	sudoku_solver
# Date created:			Apr 9, 2006
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	sudoku_solver
PORTVERSION=	1.11
CATEGORIES=	games
MASTER_SITES=	http://www.techfinesse.com/game/
DISTNAME=	solver_${PORTVERSION}

MAINTAINER=	ijliao@FreeBSD.org
COMMENT=	A Sudoku Solver in C

ALL_TARGET=	# empty

PLIST_FILES=	bin/sudoku_solver

post-patch:
	@${REINPLACE_CMD} -e "s,^CC,#CC, ; s,^CFLAGS,#CFLAGS," \
		${WRKSRC}/${MAKEFILE}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/sudoku_solver ${PREFIX}/bin

.include <bsd.port.mk>
