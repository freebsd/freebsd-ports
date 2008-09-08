# Ports collection makefile for:  pear-Games_Chess
# Date created:			  19 October 2005
# Whom:				  Mark Huizer <xaa+ports@timewasters.nl>
#
# $FreeBSD$
#

PORTNAME=	Games_Chess
PORTVERSION=	1.0.1
CATEGORIES=	games devel pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR methods for constructing and validating chess games in PGN

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Games
FILES=		Chess/Crazyhouse.php Chess/Losers.php Chess/Standard.php \
		Chess.php
EXAMPLES=	images/dark/b.gif images/dark/blank.gif images/dark/k.gif \
		images/dark/n.gif images/dark/p.gif images/dark/q.gif \
		images/dark/r.gif images/B.gif images/blank.gif images/K.gif \
		images/N.gif images/P.gif images/Q.gif images/R.gif \
		HTMLChess.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
