# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Devel-Events
PORTVERSION=	0.08
PORTREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 module providing an extensible instrumentation framework

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Moose>=0.33:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-AttributeHelpers>=0.03:${PORTSDIR}/devel/p5-MooseX-AttributeHelpers \
		p5-Set-Object>=0:${PORTSDIR}/devel/p5-Set-Object \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Sub-Uplevel>=0:${PORTSDIR}/devel/p5-Sub-Uplevel \
		p5-Test-use-ok>=0:${PORTSDIR}/devel/p5-Test-use-ok

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
