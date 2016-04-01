# $FreeBSD$

PORTNAME=	Path-Iterator-Rule
PORTVERSION=	1.008
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DAGOLDEN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for iterative, recursive file finder

LICENSE=	APACHE20

RUN_DEPENDS=	\
	p5-Data-Clone>0:devel/p5-Data-Clone \
	p5-Number-Compare>=0.02:math/p5-Number-Compare \
	p5-Text-Glob>0:textproc/p5-Text-Glob \
	p5-Try-Tiny>0:lang/p5-Try-Tiny \
	p5-namespace-clean>0:devel/p5-namespace-clean
BUILD_DEPENDS=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-File-pushd>0:devel/p5-File-pushd \
	p5-Path-Tiny>0:devel/p5-Path-Tiny \
	p5-Test-Deep>0:devel/p5-Test-Deep \
	p5-Test-Filename>0:devel/p5-Test-Filename

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	YES

.include <bsd.port.mk>
