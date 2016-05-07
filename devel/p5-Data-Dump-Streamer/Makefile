# Created by: mat
# $FreeBSD$

PORTNAME=	Data-Dump-Streamer
PORTVERSION=	2.39
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Stream a highly accurate breadth first data dump in Perl code

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Algorithm-Diff>=0:devel/p5-Algorithm-Diff \
		p5-B-Utils>=0.05:devel/p5-B-Utils \
		p5-PadWalker>=0.99:devel/p5-PadWalker
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-JSON-XS>=0:converters/p5-JSON-XS

CONFIGURE_ARGS=	DDS
USES=		perl5
USE_PERL5=	modbuild

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Data/Dump/Streamer/Streamer.so

.include <bsd.port.mk>
