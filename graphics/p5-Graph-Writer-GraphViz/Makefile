# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Graph-Writer-GraphViz
PORTVERSION=	0.11
PORTREVISION=	1
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	GraphViz Writer for Graph object

BUILD_DEPENDS=	p5-Graph>=0.54:${PORTSDIR}/math/p5-Graph \
		p5-Graph-ReadWrite>=0:${PORTSDIR}/graphics/p5-Graph-ReadWrite \
		p5-GraphViz>=2.02:${PORTSDIR}/graphics/p5-GraphViz \
		p5-IO-All>=0.30:${PORTSDIR}/devel/p5-IO-All
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PERL5=	configure
USES=		perl5

MAN3=		Graph::Writer::GraphViz.3

.include <bsd.port.mk>
