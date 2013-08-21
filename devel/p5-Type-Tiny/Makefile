# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Type-Tiny
PORTVERSION=	0.022
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TOBYINK
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tiny, yet Moo(se)-compatible type constraint

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-Class-InsideOut>=0:${PORTSDIR}/devel/p5-Class-InsideOut \
		p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-Moo>=1.002001:${PORTSDIR}/devel/p5-Moo \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-Mouse>=0:${PORTSDIR}/devel/p5-Mouse \
		p5-Role-Tiny>=0:${PORTSDIR}/devel/p5-Role-Tiny \
		p5-Sub-Exporter-Lexical>=0:${PORTSDIR}/devel/p5-Sub-Exporter-Lexical \
		p5-Validation-Class>=0:${PORTSDIR}/devel/p5-Validation-Class

USE_PERL5=	configure
USES=		perl5

MAN3=		Devel::TypeTiny::Perl56Compat.3 \
		Eval::TypeTiny.3 \
		Exporter::TypeTiny.3 \
		Reply::Plugin::TypeTiny.3 \
		Test::TypeTiny.3 \
		Type::Coercion.3 \
		Type::Coercion::Union.3 \
		Type::Exception.3 \
		Type::Exception::Assertion.3 \
		Type::Exception::Compilation.3 \
		Type::Exception::WrongNumberOfParameters.3 \
		Type::Library.3 \
		Type::Params.3 \
		Type::Parser.3 \
		Type::Registry.3 \
		Type::Tiny.3 \
		Type::Tiny::Class.3 \
		Type::Tiny::Duck.3 \
		Type::Tiny::Enum.3 \
		Type::Tiny::Intersection.3 \
		Type::Tiny::Manual.3 \
		Type::Tiny::Manual::Coercions.3 \
		Type::Tiny::Manual::Libraries.3 \
		Type::Tiny::Manual::Params.3 \
		Type::Tiny::Manual::UsingWithMoo.3 \
		Type::Tiny::Manual::UsingWithMoose.3 \
		Type::Tiny::Manual::UsingWithMouse.3 \
		Type::Tiny::Manual::UsingWithOther.3 \
		Type::Tiny::Role.3 \
		Type::Tiny::Union.3 \
		Type::Utils.3 \
		Types::Standard.3 \
		Types::TypeTiny.3

.include <bsd.port.mk>
