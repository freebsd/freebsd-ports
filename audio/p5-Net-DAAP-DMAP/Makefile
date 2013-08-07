# New ports collection makefile for:	p5-Net-DAAP-DMAP
# Date created:		2004-08-08
# Whom:			Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-DAAP-DMAP
PORTVERSION=	1.27
PORTREVISION=	1
CATEGORIES=	audio perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Perl module for reading and writing DAAP structures

BUILD_DEPENDS=	p5-Math-BigInt>0:${PORTSDIR}/math/p5-Math-BigInt
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Data-HexDump>0:${PORTSDIR}/devel/p5-Data-HexDump \
		p5-Test-Differences>0:${PORTSDIR}/devel/p5-Test-Differences

USES=		perl5
USE_PERL5=	configure

MAN3=		Net::DAAP::DMAP.3

.include <bsd.port.mk>
