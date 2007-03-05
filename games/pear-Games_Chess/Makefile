# Ports collection makefile for:  pear-Games_Chess
# Date created:			  19 October 2005
# Whom:				  Mark Huizer <xaa+ports@timewasters.nl>
#
# $FreeBSD$
#

PORTNAME=	Games_Chess
PORTVERSION=	0.9.0
CATEGORIES=	games devel pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR methods for constructing and validating chess games in PGN

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Games
FILES=		Chess.php \
		Chess/Crazyhouse.php Chess/Losers.php Chess/Player.php \
		Chess/Result.php Chess/Standard.php

EXAMPLES=	HTMLChess.php images/B.gif images/N.gif images/Q.gif \
		images/blank.gif images/K.gif images/P.gif images/R.gif \
		images/dark/b.gif images/dark/k.gif images/dark/p.gif \
		images/dark/r.gif images/dark/blank.gif images/dark/n.gif \
		images/dark/q.gif

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
