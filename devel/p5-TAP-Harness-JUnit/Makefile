# $FreeBSD$

PORTNAME=	TAP-Harness-JUnit
PORTVERSION=	0.41
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to generate JUnit compatible output from TAP

RUN_DEPENDS=	\
	p5-Test-Harness>=3.05:${PORTSDIR}/devel/p5-Test-Harness \
	p5-XML-Simple>0:${PORTSDIR}/textproc/p5-XML-Simple \
	p5-Test-Deep>0:${PORTSDIR}/devel/p5-Test-Deep
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

MAN3=	TAP::Harness::JUnit.3

NO_STAGE=	yes
.include <bsd.port.mk>
