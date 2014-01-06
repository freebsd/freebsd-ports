# $FreeBSD$

PORTNAME=	JSON
PORTVERSION=	1.15
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
PKGNAMESUFFIX=	1

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to convert to JSON (JavaScript Object Notation)

RUN_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww
BUILD_DEPENDS:=	${RUN_DEPENDS}

CONFLICTS=	p5-JSON-2.*
USES=		perl5
USE_PERL5=	configure
MAN3=		Apache::JSONRPC.3 JSON.3 JSON::Converter.3 \
		JSON::PP.3 JSON::PP5005.3 JSON::PP56.3 JSON::Parser.3 \
		JSONRPC.3 JSONRPC::Transport::HTTP.3

NO_STAGE=	yes
.include <bsd.port.mk>
