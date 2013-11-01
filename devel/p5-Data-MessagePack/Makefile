# $FreeBSD$

PORTNAME=	Data-MessagePack
PORTVERSION=	0.48
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:GFUJI
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for MessagePack

TEST_DEPENDS=	p5-Test-Requires>=0:${PORTSDIR}/devel/p5-Test-Requires \
		p5-Test-LeakTrace>0:${PORTSDIR}/devel/p5-Test-LeakTrace

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS=	--xs

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
