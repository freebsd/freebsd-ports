# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	BSON-XS
PORTVERSION=	0.8.2
DISTVERSIONPREFIX=	v
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	XS implementation of MongoDB BSON serialization

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Config-AutoConf>=0.220:devel/p5-Config-AutoConf \
		p5-Path-Tiny>=0.052:devel/p5-Path-Tiny \
		${RUN_DEPENDS}
RUN_DEPENDS=	p5-BSON>=1.12.0:databases/p5-BSON
TEST_DEPENDS=	p5-JSON-MaybeXS>=0:converters/p5-JSON-MaybeXS \
		p5-Path-Tiny>=0.054:devel/p5-Path-Tiny \
		p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-Fatal>=0:devel/p5-Test-Fatal \
		p5-Tie-IxHash>=0:devel/p5-Tie-IxHash

USES=		gmake perl5
USE_PERL5=	configure

CFLAGS+=	-DBSON_COMPILATION

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502708
TEST_DEPENDS+=	p5-JSON-PP>=2.97001:converters/p5-JSON-PP
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/BSON/XS/XS.so

.include <bsd.port.post.mk>
