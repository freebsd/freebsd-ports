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

BUILD_DEPENDS=	p5-libwww>=5:${PORTSDIR}/www/p5-libwww \
		p5-Moose>=0.81:${PORTSDIR}/devel/p5-Moose \
		p5-JSON>=2.11:${PORTSDIR}/converters/p5-JSON \
		p5-MooseX-Types>=0:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-Try-Tiny>0:${PORTSDIR}/lang/p5-Try-Tiny \
		p5-URI>0:${PORTSDIR}/net/p5-URI \
		p5-namespace-clean>=0.20:${PORTSDIR}/devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502200
TEST_DEPENDS+=	p5-Test-Simple>=1.001.014:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
