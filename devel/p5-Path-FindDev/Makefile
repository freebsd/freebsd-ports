# Created by: Frederic Culot <culot@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Path-FindDev
PORTVERSION=	0.5.2
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:KENTNL
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Find a development path in an upper hierarchy

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Tiny>=0.010:devel/p5-Class-Tiny \
		p5-Path-IsDev>=0.2.2:devel/p5-Path-IsDev \
		p5-Path-Tiny>=0.054:devel/p5-Path-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-CPAN-Meta>0:devel/p5-CPAN-Meta \
		p5-CPAN-Meta-Requirements>2.120:devel/p5-CPAN-Meta-Requirements \
		p5-Test-Simple>=1.001.003:devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
