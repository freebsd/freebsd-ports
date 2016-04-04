# Created by: glarkin
# $FreeBSD$

PORTNAME=	MooseX-StrictConstructor
PORTVERSION=	0.19
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Make your MooseX object constructors blow up on unknown attributes

LICENSE=	ART20

BUILD_DEPENDS=	p5-Moose>=0.94:devel/p5-Moose \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Fatal>=0:devel/p5-Test-Fatal

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
