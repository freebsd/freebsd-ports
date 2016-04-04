# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Hash-AutoHash-Args
PORTVERSION=	1.18
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Object-oriented processing of keyword-based argument lists

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Hash-AutoHash>=1.17:devel/p5-Hash-AutoHash
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Deep>=0.110:devel/p5-Test-Deep \
		p5-Test-Pod>=1.48:devel/p5-Test-Pod

USE_PERL5=	modbuild
USES=		perl5

.include <bsd.port.mk>
