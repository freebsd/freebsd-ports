# New ports collection makefile for:	JSON
# Date created:		19 Aug 2005
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	JSON
PORTVERSION=	1.05
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/M/MA/MAKAMAKA
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to convert to JSON (JavaScript Object Notation)

BUILD_DEPENDS=	${SITE_PERL}/HTTP/Request.pm:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
MAN3=		Apache::JSONRPC.3 JSON.3 JSON::Converter.3 JSON::Parser.3 \
		JSONRPC.3 JSONRPC::Transport::HTTP.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		Port requires perl 5.6.0 or later. Install lang/perl5.8 and try again
.endif
.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/CGI.pm:${PORTSDIR}/www/p5-CGI.pm
.endif

.include <bsd.port.post.mk>
