# $FreeBSD$

PORTNAME=	Test-Moose-More
PORTVERSION=	0.035
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	More tools for testing Moose packages

LICENSE=	LGPL21

BUILD_DEPENDS=	p5-Data-OptList>=0:${PORTSDIR}/devel/p5-Data-OptList \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-Syntax-Keyword-Junction>=0:${PORTSDIR}/devel/p5-Syntax-Keyword-Junction \
		p5-Sub-Exporter-Progressive>=0:${PORTSDIR}/devel/p5-Sub-Exporter-Progressive \
		p5-TAP-SimpleOutput>=0:${PORTSDIR}/devel/p5-TAP-SimpleOutput \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-aliased>=0:${PORTSDIR}/devel/p5-aliased \
		p5-Perl-Version>=0:${PORTSDIR}/devel/p5-Perl-Version

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
