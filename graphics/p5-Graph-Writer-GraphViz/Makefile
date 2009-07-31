# New ports collection makefile for:	p5-Graph-Writer-GraphViz
# Date created:				31 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Graph-Writer-GraphViz
PORTVERSION=	0.10
PORTREVISION=	3
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GraphViz Writer for Graph object

BUILD_DEPENDS=	${SITE_PERL}/IO/All.pm:${PORTSDIR}/devel/p5-IO-All \
		${SITE_PERL}/GraphViz.pm:${PORTSDIR}/graphics/p5-GraphViz \
		${SITE_PERL}/Graph.pm:${PORTSDIR}/math/p5-Graph \
		${SITE_PERL}/Graph/Writer.pm:${PORTSDIR}/graphics/p5-Graph-ReadWrite
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	Graph::Writer::GraphViz.3

PERL_CONFIGURE=	5.8.0+

.include <bsd.port.mk>
