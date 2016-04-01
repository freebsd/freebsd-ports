# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MooseX-Aliases
PORTVERSION=	0.11
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DOY
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Easy aliasing of methods and attributes in Moose

COMMON_DEPENDS=	p5-Moose>=1.09:devel/p5-Moose
BUILD_DEPENDS=	${COMMON_DEPENDS}
RUN_DEPENDS=	${COMMON_DEPENDS}
TEST_DEPENDS=	p5-Test-Fatal>=0.003:devel/p5-Test-Fatal \
		p5-Test-Simple>=0.88:devel/p5-Test-Simple \
		p5-Test-Requires>=0:devel/p5-Test-Requires

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
