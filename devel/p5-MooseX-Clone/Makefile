# New ports collection makefile for:	devel/p5-MooseX-Clone
# Date created:				2008/08/30
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	MooseX-Clone
PORTVERSION=	0.04
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Fine grained cloning support for Moose objects

RUN_DEPENDS=	p5-Moose>=0.45:${PORTSDIR}/devel/p5-Moose \
		p5-Data-Visitor>=0:${PORTSDIR}/devel/p5-Data-Visitor \
		p5-Hash-Util-FieldHash-Compat>=0:${PORTSDIR}/devel/p5-Hash-Util-FieldHash-Compat \
		p5-Test-use-ok>=0:${PORTSDIR}/devel/p5-Test-use-ok \
		p5-namespace-clean>=0:${PORTSDIR}/devel/p5-namespace-clean
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=		MooseX::Clone.3 \
		MooseX::Clone::Meta::Attribute::Trait::NoClone.3 \
		MooseX::Clone::Meta::Attribute::Trait::Copy.3 \
		MooseX::Clone::Meta::Attribute::Trait::Clone.3 \
		MooseX::Clone::Meta::Attribute::Trait::StorableClone.3

.include <bsd.port.mk>
