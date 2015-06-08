# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Moo
PORTVERSION=	2.000001
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:HAARG
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Minimalist Object Orientation (with Moose compatibility)

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Method-Modifiers>=1.10:${PORTSDIR}/devel/p5-Class-Method-Modifiers \
		p5-Devel-GlobalDestruction>=0.11:${PORTSDIR}/devel/p5-Devel-GlobalDestruction \
		p5-Module-Runtime>=0.014:${PORTSDIR}/devel/p5-Module-Runtime \
		p5-Role-Tiny>=2:${PORTSDIR}/devel/p5-Role-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Fatal>=0.003:${PORTSDIR}/devel/p5-Test-Fatal

OPTIONS_DEFINE=	XS

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

XS_BUILD_DEPENDS=	p5-Class-XSAccessor>=1.18:${PORTSDIR}/devel/p5-Class-XSAccessor \
			p5-Scalar-List-Utils>=0:${PORTSDIR}/lang/p5-Scalar-List-Utils
XS_RUN_DEPENDS:=	${XS_BUILD_DEPENDS}

.include <bsd.port.mk>
