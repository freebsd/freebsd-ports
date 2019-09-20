# $FreeBSD$

PORTNAME=	X-Tiny
PORTVERSION=	0.20
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Base class for a bare-bones exception factory

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Module-Runtime>=0.016:devel/p5-Module-Runtime
TEST_DEPENDS=	p5-Test-FailWarnings>=0:devel/p5-Test-FailWarnings
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

PLIST_FILES=	${SITE_PERL_REL}/X/Tiny.pm \
		${SITE_PERL_REL}/X/Tiny/Base.pm \
		${SITE_MAN3_REL}/X::Tiny.3.gz \
		${SITE_MAN3_REL}/X::Tiny::Base.3.gz

.include <bsd.port.mk>
