# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MouseX-NativeTraits
PORTVERSION=	1.09
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Extend your attribute interfaces for Mouse

BUILD_DEPENDS=	p5-Any-Moose>=0.13:${PORTSDIR}/devel/p5-Any-Moose \
		p5-Mouse>=0.82:${PORTSDIR}/devel/p5-Mouse
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Fatal>=0.003:${PORTSDIR}/devel/p5-Test-Fatal

USE_PERL5=	configure
USES=		perl5

MAN3=		Mouse::Meta::Attribute::Custom::Trait::Array.3 \
		Mouse::Meta::Attribute::Custom::Trait::Bool.3 \
		Mouse::Meta::Attribute::Custom::Trait::Code.3 \
		Mouse::Meta::Attribute::Custom::Trait::Counter.3 \
		Mouse::Meta::Attribute::Custom::Trait::Hash.3 \
		Mouse::Meta::Attribute::Custom::Trait::Number.3 \
		Mouse::Meta::Attribute::Custom::Trait::String.3 \
		Mouse::Meta::Attribute::Native.3 \
		MouseX::NativeTraits.3 \
		MouseX::NativeTraits::ArrayRef.3 \
		MouseX::NativeTraits::Bool.3 \
		MouseX::NativeTraits::CodeRef.3 \
		MouseX::NativeTraits::Counter.3 \
		MouseX::NativeTraits::HashRef.3 \
		MouseX::NativeTraits::MethodProvider.3 \
		MouseX::NativeTraits::MethodProvider::ArrayRef.3 \
		MouseX::NativeTraits::MethodProvider::Bool.3 \
		MouseX::NativeTraits::MethodProvider::CodeRef.3 \
		MouseX::NativeTraits::MethodProvider::Counter.3 \
		MouseX::NativeTraits::MethodProvider::HashRef.3 \
		MouseX::NativeTraits::MethodProvider::Num.3 \
		MouseX::NativeTraits::MethodProvider::Str.3 \
		MouseX::NativeTraits::Num.3 \
		MouseX::NativeTraits::Str.3

.include <bsd.port.mk>
