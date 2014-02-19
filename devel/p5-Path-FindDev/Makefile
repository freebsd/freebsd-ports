# Created by: Frederic Culot <culot@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Path-FindDev
PORTVERSION=	0.4.1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:KENTNL
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Find a development path in an upper hierarchy

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Tiny>=0.010:${PORTSDIR}/devel/p5-Class-Tiny \
		p5-Path-IsDev>=0.2.2:${PORTSDIR}/devel/p5-Path-IsDev \
		p5-Path-Tiny>=0.038:${PORTSDIR}/devel/p5-Path-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Simple>=0.99:${PORTSDIR}/devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
