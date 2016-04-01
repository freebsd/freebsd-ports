# Created by: Muhammad Moinur Rahman <bofh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Test-Modern
PORTVERSION=	0.013
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TOBYINK
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Precision testing for modern perl

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Exporter-Tiny>=0:devel/p5-Exporter-Tiny \
		p5-Import-Into>=1:devel/p5-Import-Into \
		p5-Module-Runtime>=0.012:devel/p5-Module-Runtime \
		p5-Test-API>=0.004:devel/p5-Test-API \
		p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-Fatal>0:devel/p5-Test-Fatal \
		p5-Test-Warnings>0:devel/p5-Test-Warnings
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Moose>=0:devel/p5-Moose

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
