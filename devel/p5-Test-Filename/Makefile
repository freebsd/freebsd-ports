# $FreeBSD$

PORTNAME=	Test-Filename
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for portable filename comparison

RUN_DEPENDS=	\
	p5-Path-Tiny>0:${PORTSDIR}/devel/p5-Path-Tiny
BUILD_DEPENDS=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-Test-Tester>0:${PORTSDIR}/devel/p5-Test-Tester

USES=		perl5
USE_PERL5=	configure

MAN3=	Test::Filename.3

.include <bsd.port.mk>
