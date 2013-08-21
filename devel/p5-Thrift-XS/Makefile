# New ports collection makefile for:	p5-Thrift-XS
# Date created:		2011-12-15
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Thrift-XS
PORTVERSION=	1.04
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:AGRUNDMA
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Faster Thrift binary protocol encoding and decoding

BUILD_DEPENDS=	p5-Bit-Vector>=0:${PORTSDIR}/math/p5-Bit-Vector \
		p5-HTTP-Message>=0:${PORTSDIR}/www/p5-HTTP-Message \
		p5-IO-String>=0:${PORTSDIR}/devel/p5-IO-String \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	p5-Bit-Vector>=0:${PORTSDIR}/math/p5-Bit-Vector \
		p5-HTTP-Message>=0:${PORTSDIR}/www/p5-HTTP-Message \
		p5-IO-String>=0:${PORTSDIR}/devel/p5-IO-String \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww

TEST_DEPENDS=	p5-Proc-ProcessTable>=0:${PORTSDIR}/devel/p5-Proc-ProcessTable \
		p5-Test-BinaryData>=0:${PORTSDIR}/devel/p5-Test-BinaryData \
		p5-Test-Pod>=1.14:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=1.04:${PORTSDIR}/devel/p5-Test-Pod-Coverage

USE_PERL5=	configure
USES=		perl5

MAN3=		Thrift::XS.3 \
		Thrift::XS::BinaryProtocol.3 \
		Thrift::XS::CompactProtocol.3 \
		Thrift::XS::MemoryBuffer.3

.include <bsd.port.mk>
