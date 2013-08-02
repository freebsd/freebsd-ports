# New ports collection makefile for:	AI::Pathfinding::AStar
# Date created:				26 August 2004
# Whom:					Aaron Dalton <aaron@daltons.ca>
#
# $FreeBSD$
#

PORTNAME=	AI-Pathfinding-AStar
PORTVERSION=	0.10
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl implementation of the A* pathfinding algorithm

BUILD_DEPENDS=	p5-Heap>=0:${PORTSDIR}/devel/p5-Heap
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		AI::Pathfinding::AStar.3

.include <bsd.port.mk>
