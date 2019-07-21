# $FreeBSD$

PORTNAME=	Redis-Fast
PORTVERSION=	0.23
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bokutin@bokut.in
COMMENT=	Perl binding for Redis database

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-File-Which>=0:sysutils/p5-File-Which \
		p5-Module-Build-XSUtil>=0.02:devel/p5-Module-Build-XSUtil \
		gmake:devel/gmake
RUN_DEPENDS=	p5-Try-Tiny>=0:lang/p5-Try-Tiny
TEST_DEPENDS=	p5-Parallel-ForkManager>=0:devel/p5-Parallel-ForkManager \
		p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-Fatal>=0:devel/p5-Test-Fatal \
		p5-Test-LeakTrace>=0:devel/p5-Test-LeakTrace \
		p5-Test-SharedFork>=0:devel/p5-Test-SharedFork \
		p5-Test-TCP>=0:devel/p5-Test-TCP \
		p5-Test-UNIXSock>=0:devel/p5-Test-UNIXSock \
		redis>=0:databases/redis

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
