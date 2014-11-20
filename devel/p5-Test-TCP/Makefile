# $FreeBSD$

PORTNAME=	Test-TCP
PORTVERSION=	2.06
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TOKUHIROM
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for testing TCP program

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-Test-SharedFork>=0.19:${PORTSDIR}/devel/p5-Test-SharedFork
BUILD_DEPENDS:=	${RUN_DEPENDS}
# XXX: test t/05_sigint.t fails.  Check it later.

USES=	perl5
USE_PERL5=	configure
NO_ARCH=	YES

.include <bsd.port.mk>
