# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MongoDB
PORTVERSION=	2.2.1
DISTVERSIONPREFIX=	v
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Mongo Driver for Perl

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Authen-SASL-SASLprep>=0:security/p5-Authen-SASL-SASLprep \
		p5-Authen-SCRAM>=0.011:security/p5-Authen-SCRAM \
		p5-BSON>=1.12.0:databases/p5-BSON \
		p5-BSON-XS>=0.6.0:databases/p5-BSON-XS \
		p5-Class-XSAccessor>=0:devel/p5-Class-XSAccessor \
		p5-Moo>=2:devel/p5-Moo \
		p5-Net-DNS>=0:dns/p5-Net-DNS \
		p5-Safe-Isa>=1.000007:devel/p5-Safe-Isa \
		p5-Sub-Quote>=0:devel/p5-Sub-Quote \
		p5-Tie-IxHash>=0:devel/p5-Tie-IxHash \
		p5-Type-Tiny>=0:devel/p5-Type-Tiny \
		p5-Type-Tiny-XS>=0:devel/p5-Type-Tiny-XS \
		p5-UUID-URandom>=0:devel/p5-UUID-URandom \
		p5-boolean>=0.25:devel/p5-boolean \
		p5-namespace-clean>=0:devel/p5-namespace-clean
TEST_DEPENDS=	p5-JSON-MaybeXS>=0:converters/p5-JSON-MaybeXS \
		p5-Path-Tiny>=0.058:devel/p5-Path-Tiny \
		p5-Test-Deep>=0.111:devel/p5-Test-Deep \
		p5-Test-Fatal>=0:devel/p5-Test-Fatal

USES=		perl5
USE_PERL5=	configure

MAKE_JOBS_UNSAFE=	yes
NO_ARCH=	yes

.include <bsd.port.mk>
