# Created by: chinsan
# $FreeBSD$

PORTNAME=	Geometry-Primitive
PORTVERSION=	0.24
PORTREVISION=	1
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:GPHAT
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Primitive Geometry Entities

RUN_DEPENDS=	p5-Check-ISA>=0.04:devel/p5-Check-ISA \
		p5-JSON-Any>=1.22:converters/p5-JSON-Any \
		p5-Moose>=0.92:devel/p5-Moose \
		p5-MooseX-Clone>=0.04:devel/p5-MooseX-Clone \
		p5-MooseX-Storage>=0.17:devel/p5-MooseX-Storage
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
