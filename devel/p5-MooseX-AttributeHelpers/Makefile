# New ports collection makefile for:	devel/p5-MooseX-AttributeHelpers
# Date created:				27 Jul 2008
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MooseX-AttributeHelpers
PORTVERSION=	0.12
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	Extend your attribute interfaces

RUN_DEPENDS=	p5-Moose>=0.45:${PORTSDIR}/devel/p5-Moose
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=	MooseX::AttributeHelpers.3 \
	MooseX::AttributeHelpers::Base.3 \
	MooseX::AttributeHelpers::Bool.3 \
	MooseX::AttributeHelpers::Collection.3 \
	MooseX::AttributeHelpers::Collection::Array.3 \
	MooseX::AttributeHelpers::Collection::Bag.3 \
	MooseX::AttributeHelpers::Collection::Hash.3 \
	MooseX::AttributeHelpers::Collection::ImmutableHash.3 \
	MooseX::AttributeHelpers::Collection::List.3 \
	MooseX::AttributeHelpers::Counter.3 \
	MooseX::AttributeHelpers::Meta::Method::Curried.3 \
	MooseX::AttributeHelpers::Meta::Method::Provided.3 \
	MooseX::AttributeHelpers::MethodProvider::Array.3 \
	MooseX::AttributeHelpers::MethodProvider::Bag.3 \
	MooseX::AttributeHelpers::MethodProvider::Bool.3 \
	MooseX::AttributeHelpers::MethodProvider::Counter.3 \
	MooseX::AttributeHelpers::MethodProvider::Hash.3 \
	MooseX::AttributeHelpers::MethodProvider::ImmutableHash.3 \
	MooseX::AttributeHelpers::MethodProvider::List.3 \
	MooseX::AttributeHelpers::MethodProvider::String.3 \
	MooseX::AttributeHelpers::Number.3 \
	MooseX::AttributeHelpers::String.3

post-extract:
	@${PERL} -i -ne 'print unless m,build_requires,' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
