# New ports collection makefile for:	p5-GraphViz-Traverse
# Date created:				02 Jun 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	GraphViz-Traverse
PORTVERSION=	0.02
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	GraphViz
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Build a GraphViz object via callback traversal

BUILD_DEPENDS=	${SITE_PERL}/GraphViz.pm:${PORTSDIR}/graphics/p5-GraphViz
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	GraphViz::Traverse.3 GraphViz::Traverse::Filesystem.3

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	requires at least Perl 5.6.  Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
