# New ports collection makefile for:	p5-JSON-RPC-Dispatcher
# Date created:				21 April, 2010
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	JSON-RPC-Dispatcher
PORTVERSION=	0.0503
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A JSON-RPC 2.0 server

BUILD_DEPENDS=	p5-JSON>=2.16:${PORTSDIR}/converters/p5-JSON \
		p5-Log-Any>=0.11:${PORTSDIR}/devel/p5-Log-Any \
		p5-Moose>=0.93:${PORTSDIR}/devel/p5-Moose \
		p5-Plack>=0.9913:${PORTSDIR}/www/p5-Plack
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		JSON::RPC::Dispatcher.3 \
		JSON::RPC::Dispatcher::App.3 \
		JSON::RPC::Dispatcher::Procedure.3

post-patch:
	${RM} ${WRKSRC}/lib/JSON/RPC/Dispatcher.pm.orig

.include <bsd.port.mk>
