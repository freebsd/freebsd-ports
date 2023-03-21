PORTNAME=	Data-Dump-Streamer
PORTVERSION=	2.42
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Stream a highly accurate breadth first data dump in Perl code
WWW=		https://metacpan.org/release/Data-Dump-Streamer

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Algorithm-Diff>=0:devel/p5-Algorithm-Diff \
		p5-B-Utils>=0.05:devel/p5-B-Utils \
		p5-PadWalker>=0.99:devel/p5-PadWalker
TEST_DEPENDS=	p5-Cpanel-JSON-XS>=0:converters/p5-Cpanel-JSON-XS

USES=		perl5
USE_PERL5=	modbuild

CONFIGURE_ARGS=	DDS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Data/Dump/Streamer/Streamer.so

.include <bsd.port.mk>
