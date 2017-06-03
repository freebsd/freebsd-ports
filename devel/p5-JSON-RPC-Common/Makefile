# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	JSON-RPC-Common
PORTVERSION=	0.11
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Transport agnostic JSON RPC helper objects

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-libwww>=5:www/p5-libwww \
		p5-Moose>=0.81:devel/p5-Moose \
		p5-JSON>=2.11:converters/p5-JSON \
		p5-MooseX-Types>=0:devel/p5-MooseX-Types \
		p5-Try-Tiny>0:lang/p5-Try-Tiny \
		p5-URI>0:net/p5-URI \
		p5-namespace-clean>=0.20:devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
