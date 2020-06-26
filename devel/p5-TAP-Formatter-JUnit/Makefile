# $FreeBSD$

PORTNAME=	TAP-Formatter-JUnit
PORTVERSION=	0.11
PORTREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for Harness output delegate for JUnit output

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	\
	p5-Moose>0:devel/p5-Moose \
	p5-MooseX-NonMoose>0:devel/p5-MooseX-NonMoose \
	p5-File-Slurp>0:devel/p5-File-Slurp \
	p5-XML-Generator>0:textproc/p5-XML-Generator \
	p5-List-MoreUtils>0:lang/p5-List-MoreUtils
TEST_DEPENDS=	p5-IO-Stringy>=0:devel/p5-IO-Stringy

USES=		perl5
USE_PERL5=	modbuild
NO_ARCH=	YES

.include <bsd.port.mk>
