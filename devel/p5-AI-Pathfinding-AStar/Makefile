# New ports collection makefile for:	AI::Pathfinding::AStar
# Date created:				26 August 2004
# Whom:					Aaron Dalton <aaron@daltons.ca>
#
# $FreeBSD$
#

PORTNAME=	AI-Pathfinding-AStar
PORTVERSION=	0.06
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	AI
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Perl implementation of the A* pathfinding algorithm

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Heap/Simple/XS.pm:${PORTSDIR}/devel/p5-Heap-Simple-XS
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		AI::Pathfinding::AStar.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		uses devel/p5-Heap-Simple, which requires perl5.6. Install lang/perl5 or lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
