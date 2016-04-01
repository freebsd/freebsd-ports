# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Graph-Writer-GraphViz
PORTVERSION=	0.11
PORTREVISION=	2
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	GraphViz Writer for Graph object

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Graph>=0.54:math/p5-Graph \
		p5-Graph-ReadWrite>=0:graphics/p5-Graph-ReadWrite \
		p5-GraphViz>=2.02:graphics/p5-GraphViz \
		p5-IO-All>=0.30:devel/p5-IO-All
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
