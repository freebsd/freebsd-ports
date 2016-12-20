# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MetaCPAN-Client
PORTVERSION=	2.003000
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MICKEY
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Comprehensive, DWIM-featured client to the MetaCPAN API

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-IO-Socket-SSL>=1.42:security/p5-IO-Socket-SSL \
		p5-JSON-MaybeXS>=0:converters/p5-JSON-MaybeXS \
		p5-Moo>=0:devel/p5-Moo \
		p5-Net-SSLeay>=1.49:security/p5-Net-SSLeay \
		p5-Ref-Util>=0:devel/p5-Ref-Util \
		p5-Safe-Isa>=0:devel/p5-Safe-Isa \
		p5-Search-Elasticsearch>=2.03:textproc/p5-Search-Elasticsearch \
		p5-URI>=0:net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Fatal>=0:devel/p5-Test-Fatal \
		p5-Test-Requires>=0:devel/p5-Test-Requires

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502400
BUILD_DEPENDS+=	p5-HTTP-Tiny>=0.56:www/p5-HTTP-Tiny
RUN_DEPENDS+=	p5-HTTP-Tiny>=0.56:www/p5-HTTP-Tiny
.endif

post-patch:
	@${REINPLACE_CMD} -e '/use ExtUtils::MakeMaker/ s| 7.1101||' ${WRKSRC}/Makefile.PL

.include <bsd.port.post.mk>
