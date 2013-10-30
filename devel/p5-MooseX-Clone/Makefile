# Created by: chinsan
# $FreeBSD$

PORTNAME=	MooseX-Clone
PORTVERSION=	0.05
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Fine grained cloning support for Moose objects

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Data-Visitor>=0.24:${PORTSDIR}/devel/p5-Data-Visitor \
		p5-Hash-Util-FieldHash-Compat>=0:${PORTSDIR}/devel/p5-Hash-Util-FieldHash-Compat \
		p5-Moose>=0.74:${PORTSDIR}/devel/p5-Moose \
		p5-namespace-clean>=0.08:${PORTSDIR}/devel/p5-namespace-clean
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-use-ok>=0:${PORTSDIR}/devel/p5-Test-use-ok

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
