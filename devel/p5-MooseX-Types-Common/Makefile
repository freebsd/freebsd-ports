# Created by: Sahil Tandon <sahil@tandon.net>
# $FreeBSD$

PORTNAME=	MooseX-Types-Common
PORTVERSION=	0.001012
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
TEST_DEPENDS=	p5-Test-Deep>=0:${PORTSDIR}/devel/p5-Test-Deep \
		p5-Test-Warnings>=0.005:${PORTSDIR}/devel/p5-Test-Warnings

USES=		perl5
USE_PERL5=	modbuildtiny

.include <bsd.port.mk>
