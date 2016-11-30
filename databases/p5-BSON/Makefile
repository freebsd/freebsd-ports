# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	BSON
PORTVERSION=	1.2.2
DISTVERSIONPREFIX=	v
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MONGODB
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Pure Perl implementation of MongoDB BSON serialization

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Moo>=2.002004:devel/p5-Moo \
		p5-namespace-clean>=0:devel/p5-namespace-clean \
		p5-Tie-IxHash>=0:devel/p5-Tie-IxHash
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-JSON-MaybeXS>=0:converters/p5-JSON-MaybeXS \
		p5-Path-Tiny>=0.054:devel/p5-Path-Tiny \
		p5-Test-Deep>=0:devel/p5-Test-Deep

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
