# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	JSON-RPC-Dispatcher
PORTVERSION=	0.0508
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	JSON-RPC 2.0 server

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-JSON>=2.16:converters/p5-JSON \
		p5-Log-Any>=0.11:devel/p5-Log-Any \
		p5-Moose>=0.93:devel/p5-Moose \
		p5-Plack>=0.9913:www/p5-Plack
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${RM} ${WRKSRC}/lib/JSON/RPC/Dispatcher.pm~

.include <bsd.port.mk>
