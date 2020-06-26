# $FreeBSD$

PORTNAME=	Test-Declare
PORTVERSION=	0.06
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for declarative testing

RUN_DEPENDS=	\
	p5-IO-Stringy>=0:devel/p5-IO-Stringy \
	p5-PPI>0:textproc/p5-PPI \
	p5-Test-Deep>0:devel/p5-Test-Deep \
	p5-Test-Exception>0:devel/p5-Test-Exception
BUILD_DEPENDS=	\
	p5-IO-Stringy>=0:devel/p5-IO-Stringy \
	p5-PPI>0:textproc/p5-PPI \
	p5-Test-Deep>0:devel/p5-Test-Deep \
	p5-Test-Exception>0:devel/p5-Test-Exception

TEST_DEPENDS=	p5-Test-Warn>=0:devel/p5-Test-Warn \
		p5-Test-Output>=0:devel/p5-Test-Output

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
