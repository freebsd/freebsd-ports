# ex:ts=8
# New ports collection makefile for:   freecell-solver
# Date created:                Fab 9, 2001
# Whom:                        Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	freecell-solver
PORTVERSION=	2.14.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=	fc-solve

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A program that automatically solves games of Freecell

USE_PERL5_BUILD=	yes
USE_CMAKE=	yes
USE_LDCONFIG=	yes

.if !defined(NOPORTDOCS)
PORTDOCS=	AUTHORS README TODO USAGE README.win32.txt INSTALL
.endif

MAN6=	fc-solve-board_gen.6 \
	fc-solve.6 \
	freecell-solver-range-parallel-solve.6 \
	make-aisleriot-freecell-board.6 \
	make-gnome-freecell-board.6 \
	make_pysol_freecell_board.py.6 \
	pi-make-microsoft-freecell-board.6

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
.for DOCFILE in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${DOCFILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
