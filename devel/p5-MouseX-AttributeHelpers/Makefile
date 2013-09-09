# $FreeBSD$

PORTNAME=	MouseX-AttributeHelpers
PORTVERSION=	0.07
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MASAKI
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to extend your attribute interfaces

RUN_DEPENDS=	\
	p5-Mouse>=0.40:${PORTSDIR}/devel/p5-Mouse
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Any-Moose>=0:${PORTSDIR}/devel/p5-Any-Moose \
		p5-Test-Deep>=0:${PORTSDIR}/devel/p5-Test-Deep \
		p5-Test-UseAllModules>=0:${PORTSDIR}/devel/p5-Test-UseAllModules \
		p5-Test-Data>=0:${PORTSDIR}/devel/p5-Test-Data

USES=		perl5
USE_PERL5=	configure

MAN3=	MouseX::AttributeHelpers.3 \
	MouseX::AttributeHelpers::Base.3 \
	MouseX::AttributeHelpers::Bool.3 \
	MouseX::AttributeHelpers::Collection::Array.3 \
	MouseX::AttributeHelpers::Collection::Bag.3 \
	MouseX::AttributeHelpers::Collection::Hash.3 \
	MouseX::AttributeHelpers::Collection::ImmutableHash.3 \
	MouseX::AttributeHelpers::Collection::List.3 \
	MouseX::AttributeHelpers::Counter.3 \
	MouseX::AttributeHelpers::Number.3 \
	MouseX::AttributeHelpers::String.3 \
	MouseX::README.3

.include <bsd.port.mk>
