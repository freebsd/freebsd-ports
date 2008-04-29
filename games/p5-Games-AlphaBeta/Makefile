# New ports collection makefile for:	p5-Games-AlphaBeta
# Date created: 			27 July 2005
# Whom: 				Aaron Dalton <aaron@daltons.ca>
#
# $FreeBSD$
#

PORTNAME=	Games-AlphaBeta
PORTVERSION=	0.4.6
CATEGORIES=	games perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Game-tree search with object oriented interface

BUILD_DEPENDS=	${SITE_PERL}/File/Find/Rule.pm:${PORTSDIR}/devel/p5-File-Find-Rule \
		${SITE_PERL}/Pod/Coverage/CountParents.pm:${PORTSDIR}/devel/p5-Pod-Coverage \
		${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN1=		othello-demo.1
MAN3=		Games::AlphaBeta.3 Games::AlphaBeta::Position.3 \
		Games::AlphaBeta::Reversi.3 \
		Games::Sequential.3 Games::Sequential::Position.3

.include <bsd.port.mk>

