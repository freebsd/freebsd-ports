# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MooseX-Types
PORTVERSION=	0.35
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DROLSKY
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Organise your Moose types in libraries

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Carp-Clan>=6.00:${PORTSDIR}/devel/p5-Carp-Clan \
		p5-Moose>=0.61:${PORTSDIR}/devel/p5-Moose \
		p5-Sub-Install>=0.924:${PORTSDIR}/devel/p5-Sub-Install \
		p5-Sub-Name>=0:${PORTSDIR}/devel/p5-Sub-Name \
		p5-namespace-clean>=0.19:${PORTSDIR}/devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal \
		p5-Test-Requires>=0:${PORTSDIR}/devel/p5-Test-Requires

PERL_CONFIGURE=	yes

MAN3=		MooseX::Types.3 \
		MooseX::Types::Base.3 \
		MooseX::Types::CheckedUtilExports.3 \
		MooseX::Types::Combine.3 \
		MooseX::Types::Moose.3 \
		MooseX::Types::TypeDecorator.3 \
		MooseX::Types::UndefinedType.3 \
		MooseX::Types::Util.3 \
		MooseX::Types::Wrapper.3

.include <bsd.port.mk>
