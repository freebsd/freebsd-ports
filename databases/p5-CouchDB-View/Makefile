# New ports collection makefile for:	p5-CouchDB-View
# Date created:		2011-09-03
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	CouchDB-View
PORTVERSION=	0.003
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Handle and create CouchDB views in Perl

BUILD_DEPENDS=	p5-Data-Dump-Streamer>=0:${PORTSDIR}/devel/p5-Data-Dump-Streamer \
		p5-JSON-XS>=0:${PORTSDIR}/converters/p5-JSON-XS \
		p5-PadWalker>=0:${PORTSDIR}/devel/p5-PadWalker \
		p5-URI>=0:${PORTSDIR}/net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Deep>=0:${PORTSDIR}/devel/p5-Test-Deep

USE_PERL5=	configure
USES=		perl5

MAN3=		CouchDB::View.3 \
		CouchDB::View::Document.3 \
		CouchDB::View::Server.3

.include <bsd.port.mk>
