# $FreeBSD$

PORTNAME=	MouseX-Getopt
PORTVERSION=	${DISTVERSION}00
PORTREVISION=	1
DISTVERSION=	0.34
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for a Mouse role to process command line options

RUN_DEPENDS=	\
	p5-Mouse>=0.64:${PORTSDIR}/devel/p5-Mouse \
	p5-Getopt-Long-Descriptive>=0.091:${PORTSDIR}/devel/p5-Getopt-Long-Descriptive
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
