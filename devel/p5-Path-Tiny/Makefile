PORTNAME=	Path-Tiny
PORTVERSION=	0.150
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DAGOLDEN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	File path utility
WWW=		https://metacpan.org/release/Path-Tiny

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	p5-Test-FailWarnings>=0:devel/p5-Test-FailWarnings \
		p5-Test-MockRandom>=0:devel/p5-Test-MockRandom

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
