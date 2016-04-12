# Created by: Fernan Aguero <fernan@iib.unsam.edu.ar>
# $FreeBSD$

PORTNAME=	SVG-Graph
PORTVERSION=	0.04
PORTREVISION=	1
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CJFIELDS
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Visualize your data in Scalable Vector Graphics (SVG) format

LICENSE=	ART20

BUILD_DEPENDS=	p5-Math-Spline>=0:math/p5-Math-Spline \
		p5-SVG>=0:textproc/p5-SVG \
		p5-Statistics-Descriptive>=0:math/p5-Statistics-Descriptive \
		p5-Tree-DAG_Node>=0:devel/p5-Tree-DAG_Node
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
