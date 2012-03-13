# New ports collection makefile for:	p5-Bread-Board-Declare
# Date created:		2011-09-05
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Bread-Board-Declare
PORTVERSION=	0.12
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DOY
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Create Bread::Board containers as normal Moose objects

BUILD_DEPENDS=	p5-Bread-Board>=0.22:${PORTSDIR}/devel/p5-Bread-Board \
		p5-Class-Load>=0.07:${PORTSDIR}/devel/p5-Class-Load \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Moose>=2.0200:${PORTSDIR}/devel/p5-Moose
RUN_DEPENDS=	p5-Bread-Board>=0.22:${PORTSDIR}/devel/p5-Bread-Board \
		p5-Class-Load>=0.07:${PORTSDIR}/devel/p5-Class-Load \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Moose>=2.0200:${PORTSDIR}/devel/p5-Moose

TEST_DEPENDS=	p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal

PERL_CONFIGURE=	yes

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

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
TEST_DEPENDS+=	p5-Test-Simple>=0.88:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
