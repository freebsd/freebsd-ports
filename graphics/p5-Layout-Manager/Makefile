# Created by: chinsan
# $FreeBSD$

PORTNAME=	Layout-Manager
PORTVERSION=	0.35
PORTREVISION=	1
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:GPHAT
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	2D Layout Management

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Geometry-Primitive>=0.16:graphics/p5-Geometry-Primitive \
		p5-Graphics-Primitive>=0.43:graphics/p5-Graphics-Primitive \
		p5-Moose>=0.79:devel/p5-Moose
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
