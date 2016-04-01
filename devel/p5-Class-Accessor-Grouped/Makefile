# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Class-Accessor-Grouped
PORTVERSION=	0.10012
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RIBASUSHI
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Lets you build groups of accessors

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Module-Runtime>=0.012:devel/p5-Module-Runtime \
		p5-Class-XSAccessor>=1.19:devel/p5-Class-XSAccessor \
		p5-MRO-Compat>=0:devel/p5-MRO-Compat \
		p5-Sub-Name>=0.05:devel/p5-Sub-Name
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0.31:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
