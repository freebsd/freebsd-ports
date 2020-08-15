# $FreeBSD$

PORTNAME=	Module-Build-WithXSpp
PORTVERSION=	0.14
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SMUELLER
PKGNAMEPREFIX=	p5-

MAINTAINER=	bokutin@bokut.in
COMMENT=	XS++ enhanced flavour of Module::Build

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Module-Build>=0.26:devel/p5-Module-Build
RUN_DEPENDS=	p5-ExtUtils-CppGuess>=0.04:devel/p5-ExtUtils-CppGuess \
		p5-ExtUtils-XSpp>=0.11:devel/p5-ExtUtils-XSpp \
		p5-Module-Build>=0.26:devel/p5-Module-Build

USES=		perl5
USE_PERL5=	modbuild
PLIST_FILES=	${SITE_MAN3_REL}/Module::Build::WithXSpp.3.gz \
		${SITE_PERL}/Module/Build/WithXSpp.pm

NO_ARCH=	yes

.include <bsd.port.mk>
