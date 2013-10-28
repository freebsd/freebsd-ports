# Created by: andrey@kostenko.name
# $FreeBSD$

PORTNAME=	Config-MVP
PORTVERSION=	2.200006
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Multivalue-property package-oriented configuration

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Load>=0.17:${PORTSDIR}/devel/p5-Class-Load \
		p5-Module-Runtime>=0:${PORTSDIR}/devel/p5-Module-Runtime \
		p5-Moose>=0.91:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-OneArgNew>=0:${PORTSDIR}/devel/p5-MooseX-OneArgNew \
		p5-Params-Util>=0:${PORTSDIR}/devel/p5-Params-Util \
		p5-Role-HasMessage>=0:${PORTSDIR}/devel/p5-Role-HasMessage \
		p5-Role-Identifiable>=0:${PORTSDIR}/devel/p5-Role-Identifiable \
		p5-Throwable>=0:${PORTSDIR}/devel/p5-Throwable \
		p5-Tie-IxHash>=0:${PORTSDIR}/devel/p5-Tie-IxHash \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Capture-Tiny>=0:${PORTSDIR}/devel/p5-Capture-Tiny \
		p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
TEST_DEPENDS+=	p5-Test-Simple>=0.96:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
