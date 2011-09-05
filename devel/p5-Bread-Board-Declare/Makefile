# New ports collection makefile for:	p5-Bread-Board-Declare
# Date created:		2011-09-05
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Bread-Board-Declare
PORTVERSION=	0.10
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DOY
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Create Bread::Board containers as normal Moose objects

BUILD_DEPENDS=	p5-Bread-Board>=0.20:${PORTSDIR}/devel/p5-Bread-Board \
		p5-Moose>=1.21:${PORTSDIR}/devel/p5-Moose
RUN_DEPENDS=	p5-Bread-Board>=0.20:${PORTSDIR}/devel/p5-Bread-Board \
		p5-Moose>=1.21:${PORTSDIR}/devel/p5-Moose

TEST_DEPENDS=	p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal

PERL_CONFIGURE=	yes

MAN3=		Bread::Board::Declare.3 \
		Bread::Board::Declare::BlockInjection.3 \
		Bread::Board::Declare::ConstructorInjection.3 \
		Bread::Board::Declare::Literal.3 \
		Bread::Board::Declare::Meta::Role::Accessor.3 \
		Bread::Board::Declare::Meta::Role::Attribute.3 \
		Bread::Board::Declare::Meta::Role::Class.3 \
		Bread::Board::Declare::Meta::Role::Instance.3 \
		Bread::Board::Declare::Role::Object.3 \
		Bread::Board::Declare::Role::Service.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500808
BUILD_DEPENDS+=	p5-ExtUtils-MakeMaker>=6.30:${PORTSDIR}/devel/p5-ExtUtils-MakeMaker
.endif

.if ${PERL_LEVEL} < 501001
TEST_DEPENDS+=	p5-Test-Simple>=0.88:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
