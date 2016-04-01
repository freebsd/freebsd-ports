# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MooseX-Runnable
PORTVERSION=	0.10
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tag a class as a runnable application

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Load>=0:devel/p5-Class-Load \
		p5-List-SomeUtils>=0:devel/p5-List-SomeUtils \
		p5-Moose>=0:devel/p5-Moose \
		p5-MooseX-Getopt>=0:devel/p5-MooseX-Getopt \
		p5-MooseX-Types>=0:devel/p5-MooseX-Types \
		p5-MooseX-Types-Path-Class>=0:devel/p5-MooseX-Types-Path-Class \
		p5-Params-Util>=0:devel/p5-Params-Util \
		p5-Path-Tiny>=0:devel/p5-Path-Tiny \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Fatal>=0:devel/p5-Test-Fatal \
		p5-Test-TableDriven>=0:devel/p5-Test-TableDriven

NO_ARCH=	yes
USE_PERL5=	modbuildtiny
USES=		perl5

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502200
TEST_DEPENDS+=	p5-Test-Simple>=1.001.014:devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
