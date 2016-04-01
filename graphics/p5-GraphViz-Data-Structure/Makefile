# Created by: ijliao
# $FreeBSD$

PORTNAME=	GraphViz-Data-Structure
PORTVERSION=	0.19
PORTREVISION=	1
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Visualise data structures

BUILD_DEPENDS=	dot:graphics/graphviz \
		p5-GraphViz>=0:graphics/p5-GraphViz
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
