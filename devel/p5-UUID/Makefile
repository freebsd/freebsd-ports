PORTNAME=	UUID
PORTVERSION=	0.36
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Universally Unique Identifier library for Perl
WWW=		https://metacpan.org/release/UUID

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Devel-CheckLib>=1.14:devel/p5-Devel-CheckLib
TEST_DEPENDS=	p5-Data-UUID>=0:devel/p5-Data-UUID \
		p5-Digest-SHA1>=0:security/p5-Digest-SHA1 \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny

USES=		perl5
USE_PERL5=	configure

TEST_ENV=	TEST_VERBOSE=1

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/UUID/UUID.so

.include <bsd.port.mk>
