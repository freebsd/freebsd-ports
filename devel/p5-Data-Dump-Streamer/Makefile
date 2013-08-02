# Created by: mat
# $FreeBSD$

PORTNAME=	Data-Dump-Streamer
PORTVERSION=	2.34
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Stream a highly accurate breadth first data dump in Perl code

BUILD_DEPENDS=	p5-Algorithm-Diff>=0:${PORTSDIR}/devel/p5-Algorithm-Diff \
		p5-B-Utils>=0.05:${PORTSDIR}/devel/p5-B-Utils \
		p5-PadWalker>=0.99:${PORTSDIR}/devel/p5-PadWalker
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-JSON-XS>=0:${PORTSDIR}/converters/p5-JSON-XS

CONFIGURE_ARGS=	DDS
USES=		perl5
USE_PERL5=	modbuild

MAN3=		DDS.3 Data::Dump::Streamer.3

.include <bsd.port.mk>
