# $FreeBSD$

PORTNAME=	Data-Perl
PORTVERSION=	0.002009
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Base classes wrapping fundamental Perl data types

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Method-Modifiers>=0:devel/p5-Class-Method-Modifiers \
		p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-Module-Runtime>=0:devel/p5-Module-Runtime \
		p5-Role-Tiny>=0:devel/p5-Role-Tiny \
		p5-strictures>=1:devel/p5-strictures
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
