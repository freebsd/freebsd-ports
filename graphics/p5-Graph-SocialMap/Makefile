# New ports collection makefile for:	p5-Graph-SocialMap
# Date created:				31 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Graph-SocialMap
PORTVERSION=	0.12
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Graph
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Easy tool to create social network maps

BUILD_DEPENDS=	${SITE_PERL}/Spiffy.pm:${PORTSDIR}/devel/p5-Spiffy \
		${SITE_PERL}/Graph.pm:${PORTSDIR}/math/p5-Graph \
		${SITE_PERL}/Graph/Writer/GraphViz.pm:${PORTSDIR}/graphics/p5-Graph-Writer-GraphViz \
		${SITE_PERL}/Quantum/Superpositions.pm:${PORTSDIR}/lang/p5-Quantum-Superpositions \
		${SITE_PERL}/YAML.pm:${PORTSDIR}/textproc/p5-YAML
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	Graph::SocialMap.3

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=	currently requires at least Perl 5.8 due to dependencies.  Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
