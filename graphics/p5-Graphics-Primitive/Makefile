# Created by: chinsan
# $FreeBSD$

PORTNAME=	Graphics-Primitive
PORTVERSION=	0.61
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:GPHAT
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Device and library agnostic graphic primitives

RUN_DEPENDS=	p5-Forest>=0.06:${PORTSDIR}/devel/p5-Forest \
		p5-Geometry-Primitive>=0.16:${PORTSDIR}/graphics/p5-Geometry-Primitive \
		p5-Graphics-Color>=0.20:${PORTSDIR}/graphics/p5-Graphics-Color \
		p5-JSON-Any>=1.22:${PORTSDIR}/converters/p5-JSON-Any \
		p5-Moose>=0.90:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Clone>=0.04:${PORTSDIR}/devel/p5-MooseX-Clone \
		p5-MooseX-Storage>=0.17:${PORTSDIR}/devel/p5-MooseX-Storage
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
