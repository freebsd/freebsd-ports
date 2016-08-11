# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Moo
PORTVERSION=	2.002004
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:HAARG
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Minimalist Object Orientation (with Moose compatibility)

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Method-Modifiers>=1.10:devel/p5-Class-Method-Modifiers \
		p5-Devel-GlobalDestruction>=0.11:devel/p5-Devel-GlobalDestruction \
		p5-Module-Runtime>=0.014:devel/p5-Module-Runtime \
		p5-Role-Tiny>=2:devel/p5-Role-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Fatal>=0.003:devel/p5-Test-Fatal

OPTIONS_DEFINE=	XS

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

XS_BUILD_DEPENDS=	p5-Class-XSAccessor>=1.18:devel/p5-Class-XSAccessor
XS_RUN_DEPENDS=		${XS_BUILD_DEPENDS}

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502200 && ${PORT_OPTIONS:MXS}
BUILD_DEPENDS+=	p5-Scalar-List-Utils>=0:lang/p5-Scalar-List-Utils
RUN_DEPENDS+=	p5-Scalar-List-Utils>=0:lang/p5-Scalar-List-Utils
.endif

.include <bsd.port.post.mk>
