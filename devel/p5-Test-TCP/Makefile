# $FreeBSD$

PORTNAME=	Test-TCP
PORTVERSION=	2.02
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TOKUHIROM
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for testing TCP program

RUN_DEPENDS=	\
	p5-Test-SharedFork>=0.19:${PORTSDIR}/devel/p5-Test-SharedFork
BUILD_DEPENDS:=	${RUN_DEPENDS}
# XXX: test t/05_sigint.t fails.  Check it later.

USES=	perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
