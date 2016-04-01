# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Parallel-Prefork
PORTVERSION=	0.14
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:KAZUHO
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Simple prefork server framework

BUILD_DEPENDS=	p5-Proc-Wait3>=0.03:devel/p5-Proc-Wait3 \
		p5-Class-Accessor-Lite>=0.04:devel/p5-Class-Accessor-Lite \
		p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-Scope-Guard>=0:devel/p5-Scope-Guard
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Requires>=0:devel/p5-Test-Requires \
		p5-Test-SharedFork>=0:devel/p5-Test-SharedFork \
		p5-Test-Simple>=0.88:devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
