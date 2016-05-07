# $FreeBSD$

PORTNAME=	IO-Callback
PORTVERSION=	1.12
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to emulate file interface for a code reference

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-IO-String>0:devel/p5-IO-String
BUILD_DEPENDS:=	\
	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-File-Slurp>0:devel/p5-File-Slurp \
	p5-Test-Exception>0:devel/p5-Test-Exception \
	p5-Test-NoWarnings>0:devel/p5-Test-NoWarnings

USES=		perl5
USE_PERL5=	modbuild
NO_ARCH=	YES

.include <bsd.port.mk>
