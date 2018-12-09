# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	BSON
PORTVERSION=	1.10.2
DISTVERSIONPREFIX=	v
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MONGODB
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Pure Perl implementation of MongoDB BSON serialization

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Crypt-URandom>=0:security/p5-Crypt-URandom \
		p5-Moo>=2.002004:devel/p5-Moo \
		p5-Tie-IxHash>=0:devel/p5-Tie-IxHash \
		p5-boolean>=0.45:devel/p5-boolean \
		p5-namespace-clean>=0:devel/p5-namespace-clean
TEST_DEPENDS=	p5-JSON-MaybeXS>=0:converters/p5-JSON-MaybeXS \
		p5-Path-Tiny>=0.054:devel/p5-Path-Tiny \
		p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-Fatal>=0:devel/p5-Test-Fatal

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502708
TEST_DEPENDS+=	p5-JSON-PP>=2.97001:converters/p5-JSON-PP
.endif

.include <bsd.port.post.mk>
