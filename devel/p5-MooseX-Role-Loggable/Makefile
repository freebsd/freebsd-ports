# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MooseX-Role-Loggable
PORTVERSION=	0.113
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Extensive, yet simple, logging role using Log::Dispatchouli

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Log-Dispatchouli>=0:devel/p5-Log-Dispatchouli \
		p5-Moo>=1.000001:devel/p5-Moo \
		p5-MooX-Types-MooseLike>=0:devel/p5-MooX-Types-MooseLike \
		p5-Safe-Isa>=0:devel/p5-Safe-Isa \
		p5-Sys-Syslog>=0.25:sysutils/p5-Sys-Syslog \
		p5-namespace-sweep>=0:devel/p5-namespace-sweep
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Fatal>=0:devel/p5-Test-Fatal

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
