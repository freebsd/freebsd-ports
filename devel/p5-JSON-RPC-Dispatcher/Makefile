# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	JSON-RPC-Dispatcher
PORTVERSION=	0.0506
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	JSON-RPC 2.0 server

RUN_DEPENDS=	p5-JSON>=2.16:${PORTSDIR}/converters/p5-JSON \
		p5-Log-Any>=0.11:${PORTSDIR}/devel/p5-Log-Any \
		p5-Moose>=0.93:${PORTSDIR}/devel/p5-Moose \
		p5-Plack>=0.9913:${PORTSDIR}/www/p5-Plack
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

post-patch:
	${RM} ${WRKSRC}/lib/JSON/RPC/Dispatcher.pm.orig

.include <bsd.port.mk>
