# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Test-Classy
PORTVERSION=	0.10
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
#MASTER_SITE_SUBDIR=	CPAN:ISHIGAKI
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Write your unit tests in other modules than *.t

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Data-Inheritable>=0:devel/p5-Class-Data-Inheritable \
		p5-Class-Inspector>=0:devel/p5-Class-Inspector \
		p5-Data-Dump>=0:devel/p5-Data-Dump \
		p5-Module-Find>=0.05:devel/p5-Module-Find \
		p5-Sub-Install>=0.920:devel/p5-Sub-Install \
		p5-Term-Encoding>=0:devel/p5-Term-Encoding
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-UseAllModules>=0.09:devel/p5-Test-UseAllModules

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
