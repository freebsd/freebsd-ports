# Created by: Alex Kapranoff <kappa@rambler-co.ru>
# $FreeBSD$

PORTNAME=	Set-Array
PORTVERSION=	0.30
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RSAVAGE
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Arrays as objects with set operations

LICENSE=	ART10

BUILD_DEPENDS=	p5-Try-Tiny>=0.11:lang/p5-Try-Tiny \
		p5-Want>=0:devel/p5-Want
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-Pod>=0:devel/p5-Test-Pod

USES=		perl5 tar:tgz
USE_PERL5=	configure

.include <bsd.port.mk>
