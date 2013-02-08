# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MooseX-Attribute-Chained
PORTVERSION=	1.0.1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Attribute that returns the instance to allow for chaining

BUILD_DEPENDS=	p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Moose::Meta::Attribute::Custom::Trait::Chained.3 \
		MooseX::Attribute::Chained.3 \
		MooseX::Attribute::ChainedClone.3 \
		MooseX::ChainedAccessors.3 \
		MooseX::ChainedAccessors::Accessor.3 \
		MooseX::Traits::Attribute::Chained.3

.include <bsd.port.mk>
