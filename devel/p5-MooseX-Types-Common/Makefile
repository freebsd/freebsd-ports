# Created by: Sahil Tandon <sahil@tandon.net>
# $FreeBSD$

PORTNAME=	MooseX-Types-Common
PORTVERSION=	0.001008
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ETHER
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Set of commonly-used type constraints that do not ship with p5-Moose

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Moose>=0.39:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Types>=0.04:${PORTSDIR}/devel/p5-MooseX-Types
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Capture-Tiny>=0:${PORTSDIR}/devel/p5-Capture-Tiny \
		p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal

USES=		perl5
USE_PERL5=	configure

MAN3=		MooseX::Types::Common.3 \
		MooseX::Types::Common::Numeric.3 \
		MooseX::Types::Common::String.3

.include <bsd.port.mk>
