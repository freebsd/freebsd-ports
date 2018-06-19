# $FreeBSD$

PORTNAME=	Test-UNIXSock
PORTVERSION=	0.2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bokutin@bokut.in
COMMENT=	Testing UNIX domain socket servers

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Module-Build-Tiny>=0.035:devel/p5-Module-Build-Tiny
RUN_DEPENDS=	p5-Test-TCP>=0:devel/p5-Test-TCP \
		p5-Test-SharedFork>=0.29:devel/p5-Test-SharedFork

USES=		perl5
USE_PERL5=	modbuildtiny

.include <bsd.port.mk>
