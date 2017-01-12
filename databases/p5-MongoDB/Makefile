# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MongoDB
PORTVERSION=	1.6.1
DISTVERSIONPREFIX=	v
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Mongo Driver for Perl

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Authen-SCRAM>=0.003:security/p5-Authen-SCRAM \
		p5-BSON>=1:databases/p5-BSON \
		p5-Class-XSAccessor>0:devel/p5-Class-XSAccessor \
		p5-DateTime>=0.78:devel/p5-DateTime \
		p5-Moose>=2:devel/p5-Moose \
		p5-Safe-Isa>=0:devel/p5-Safe-Isa \
		p5-Syntax-Keyword-Junction>=0:devel/p5-Syntax-Keyword-Junction \
		p5-Throwable>=0:devel/p5-Throwable \
		p5-Tie-IxHash>=0:devel/p5-Tie-IxHash \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny \
		p5-boolean>=0:devel/p5-boolean \
		p5-namespace-clean>=0:devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}
BUILD_DEPENDS+=	p5-Config-AutoConf>=0.220:devel/p5-Config-AutoConf \
		p5-Path-Tiny>=0.052:devel/p5-Path-Tiny
TEST_DEPENDS=	p5-Data-Dump>=0:devel/p5-Data-Dump \
		p5-JSON>=2:converters/p5-JSON \
		p5-JSON-MaybeXS>=0:converters/p5-JSON-MaybeXS \
		p5-Test-Deep>=0.111:devel/p5-Test-Deep \
		p5-Test-Fatal>=0:devel/p5-Test-Fatal \
		p5-Test-Warn>=0:devel/p5-Test-Warn

CFLAGS+=	-DBSON_COMPILATION -DMONGO_USE_64_BIT_INT
MAKE_JOBS_UNSAFE=	yes
USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/MongoDB/MongoDB.so

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502200
BUILD_DEPENDS+=	p5-JSON-PP>=2.27300:converters/p5-JSON-PP
RUN_DEPENDS+=	p5-JSON-PP>=2.27300:converters/p5-JSON-PP
.endif

.include <bsd.port.post.mk>
