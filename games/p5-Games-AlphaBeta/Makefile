# New ports collection makefile for:	p5-Games-AlphaBeta
# Date created: 			27 July 2005
# Whom: 				Aaron Dalton <aaron@daltons.ca>
#
# $FreeBSD$
#

PORTNAME=	Games-AlphaBeta
PORTVERSION=	0.4.5
CATEGORIES=	games perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Games
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@daltons.ca
COMMENT=	Game-tree search with object oriented interface

BUILD_DEPENDS=	${SITE_PERL}/Games/Sequential.pm:${PORTSDIR}/games/p5-Games-Sequential
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	 yes

MAN3=		Games::AlphaBeta.3 Games::AlphaBeta::Position.3 \
		Games::AlphaBeta::Reversi.3

.include <bsd.port.mk>
