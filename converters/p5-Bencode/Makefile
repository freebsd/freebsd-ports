PORTNAME=	Bencode
PORTVERSION=	1.502
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ARISTOTLE
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	BitTorrent bencode serialisation format
WWW=		https://metacpan.org/release/Bencode

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Exporter-Tidy>=0:devel/p5-Exporter-Tidy
TEST_DEPENDS=	p5-Test-Differences>=0:devel/p5-Test-Differences

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
