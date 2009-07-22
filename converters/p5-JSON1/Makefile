# New ports collection makefile for:	JSON
# Date created:		19 Aug 2005
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	JSON
PORTVERSION=	1.15
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to convert to JSON (JavaScript Object Notation)

RUN_DEPENDS=	${SITE_PERL}/HTTP/Request.pm:${PORTSDIR}/www/p5-libwww
BUILD_DEPENDS=	${RUN_DEPENDS}

CONFLICTS=	p5-JSON-2.*
PERL_CONFIGURE=	yes
NO_LATEST_LINK=	yes
MAN3=		Apache::JSONRPC.3 JSON.3 JSON::Converter.3 \
		JSON::PP.3 JSON::PP5005.3 JSON::PP56.3 JSON::Parser.3 \
		JSONRPC.3 JSONRPC::Transport::HTTP.3

.include <bsd.port.mk>
