# ex:ts=8
# New ports collection makefile for:   freecell-solver
# Date created:                Fab 9, 2001
# Whom:                        Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	freecell-solver
PORTVERSION=	1.6.3
CATEGORIES=	games
MASTER_SITES=	http://vipe.technion.ac.il/~shlomif/freecell-solver/ \
		http://fc-solve.berlios.de/

MAINTAINER=	ijliao@FreeBSD.org

USE_GMAKE=	yes
ALL_TARGET=	fc-solve

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fc-solve ${PREFIX}/bin

.include <bsd.port.mk>
