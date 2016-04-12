# $FreeBSD$

PORTNAME=	TAP-Harness-JUnit
PORTVERSION=	0.42
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to generate JUnit compatible output from TAP

RUN_DEPENDS=	\
	p5-XML-Simple>0:textproc/p5-XML-Simple
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-Test-Deep>0:devel/p5-Test-Deep

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
