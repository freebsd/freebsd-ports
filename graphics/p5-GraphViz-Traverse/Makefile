# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	GraphViz-Traverse
PORTVERSION=	0.02
PORTREVISION=	6
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Build a GraphViz object via callback traversal

BUILD_DEPENDS=	p5-GraphViz>=0:${PORTSDIR}/graphics/p5-GraphViz
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAN3=	GraphViz::Traverse.3 GraphViz::Traverse::Filesystem.3

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
