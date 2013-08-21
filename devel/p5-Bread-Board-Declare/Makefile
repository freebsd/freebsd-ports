# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Bread-Board-Declare
PORTVERSION=	0.14
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DOY
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Create Bread::Board containers as normal Moose objects

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Bread-Board>=0.22:${PORTSDIR}/devel/p5-Bread-Board \
		p5-Class-Load>=0.07:${PORTSDIR}/devel/p5-Class-Load \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Moose>=2.0200:${PORTSDIR}/devel/p5-Moose
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal

USE_PERL5=	configure
USES=		perl5

MAN3=		Bread::Board::Declare.3 \
		Bread::Board::Declare::BlockInjection.3 \
		Bread::Board::Declare::ConstructorInjection.3 \
		Bread::Board::Declare::Literal.3 \
		Bread::Board::Declare::Meta::Role::Attribute.3 \
		Bread::Board::Declare::Meta::Role::Attribute::Container.3 \
		Bread::Board::Declare::Meta::Role::Attribute::Service.3 \
		Bread::Board::Declare::Meta::Role::Class.3 \
		Bread::Board::Declare::Meta::Role::Instance.3 \
		Bread::Board::Declare::Role::Object.3 \
		Bread::Board::Declare::Role::Service.3

.include <bsd.port.mk>
