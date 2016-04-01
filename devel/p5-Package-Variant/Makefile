# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Package-Variant
PORTVERSION=	1.003002
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Parameterizable packages

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Import-Into>=1:devel/p5-Import-Into \
		p5-Module-Runtime>=0.013:devel/p5-Module-Runtime \
		p5-strictures>=2:devel/p5-strictures
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Moo>=0:devel/p5-Moo \
		p5-Test-Fatal>=0:devel/p5-Test-Fatal

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
