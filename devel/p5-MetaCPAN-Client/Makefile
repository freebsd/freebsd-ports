# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MetaCPAN-Client
PORTVERSION=	1.008001
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:XSAWYERX
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Comprehensive, DWIM-featured client to the MetaCPAN API

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-JSON-MaybeXS>=0:converters/p5-JSON-MaybeXS \
		p5-Moo>=0:devel/p5-Moo \
		p5-Safe-Isa>=0:devel/p5-Safe-Isa \
		p5-Search-Elasticsearch>=1.10:textproc/p5-Search-Elasticsearch \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Fatal>=0:devel/p5-Test-Fatal \
		p5-Test-Requires>=0:devel/p5-Test-Requires

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
