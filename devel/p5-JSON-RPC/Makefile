# New ports collection makefile for:	p5-JSON-RPC
# Date created:				29 Mar 2009
# Whom:					Vadim Vatlin
#
# $FreeBSD$
#

PORTNAME=	JSON-RPC
PORTVERSION=	0.96
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvatlin@masterhost.ru
COMMENT=	Perl implementation of JSON-RPC 1.1 protocol

RUN_DEPENDS=	p5-CGI.pm>=2.92:${PORTSDIR}/www/p5-CGI.pm \
		p5-JSON>=2.0:${PORTSDIR}/converters/p5-JSON \
		p5-libwww:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	YES

MAN3=		JSON::RPC.3 JSON::RPC::Server.3 JSON::RPC::Client.3 \
		JSON::RPC::Procedure.3 JSON::RPC::Server::CGI.3 JSONRPC.3 \
		JSON::RPC::Server::Daemon.3 JSON::RPC::Server::Apache2.3

.include <bsd.port.mk>
