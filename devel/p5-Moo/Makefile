# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Moo
PORTVERSION=	2.003006
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:HAARG
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Minimalist Object Orientation (with Moose compatibility)

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Method-Modifiers>=1.10:devel/p5-Class-Method-Modifiers \
		p5-Module-Runtime>=0.014:devel/p5-Module-Runtime \
		p5-Role-Tiny>=2.001004:devel/p5-Role-Tiny \
		p5-Sub-Quote>=2.006006:devel/p5-Sub-Quote
TEST_DEPENDS=	p5-Test-Fatal>=0.003:devel/p5-Test-Fatal \
		${XS_BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

OPTIONS_DEFINE=	XS

XS_BUILD_DEPENDS=	p5-Class-XSAccessor>=1.18:devel/p5-Class-XSAccessor
XS_RUN_DEPENDS=		${XS_BUILD_DEPENDS}

.include <bsd.port.mk>
