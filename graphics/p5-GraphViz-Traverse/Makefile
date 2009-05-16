# New ports collection makefile for:	p5-GraphViz-Traverse
# Date created:				02 Jun 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	GraphViz-Traverse
PORTVERSION=	0.02
PORTREVISION=	2
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	Build a GraphViz object via callback traversal

BUILD_DEPENDS=	${SITE_PERL}/GraphViz.pm:${PORTSDIR}/graphics/p5-GraphViz
RUN_DEPENDS=	${BUILD_DEPENDS}

MAKE_JOBS_SAFE=  yes

MAN3=	GraphViz::Traverse.3 GraphViz::Traverse::Filesystem.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
