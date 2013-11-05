# Created by: ijliao
# $FreeBSD$

PORTNAME=	GraphViz-Data-Structure
PORTVERSION=	0.19
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Visualise data structures

BUILD_DEPENDS=	p5-GraphViz>=0:${PORTSDIR}/graphics/p5-GraphViz \
		${LOCALBASE}/bin/dot:${PORTSDIR}/graphics/graphviz
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
