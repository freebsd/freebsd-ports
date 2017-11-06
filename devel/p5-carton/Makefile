# $FreeBSD$

PORTNAME=	carton
PORTVERSION=	1.0.28
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MIYAGAWA
PKGNAMEPREFIX=	p5-
DISTNAME=	Carton-v${PORTVERSION}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl module dependency manager

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	\
	p5-App-cpanminus>=1.703:devel/p5-App-cpanminus \
	p5-JSON>=2.53:converters/p5-JSON \
	p5-Module-CPANfile>=0.9031:devel/p5-Module-CPANfile \
	p5-Module-Reader>=0.002:devel/p5-Module-Reader \
	p5-Path-Tiny>=0.033:devel/p5-Path-Tiny \
	p5-Class-Tiny>=1.001:devel/p5-Class-Tiny \
	p5-Try-Tiny>=0.09:lang/p5-Try-Tiny
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	YES

.include <bsd.port.mk>
