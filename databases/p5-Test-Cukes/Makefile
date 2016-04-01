# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	Test-Cukes
PORTVERSION=	0.10
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	BBD test tool inspired by Cucumber

BUILD_DEPENDS=	p5-Any-Moose>=0.10:devel/p5-Any-Moose \
		p5-Carp-Assert>=0.20:devel/p5-Carp-Assert \
		p5-Exporter-Lite>=0.02:devel/p5-Exporter-Lite \
		p5-Try-Tiny>=0.07:lang/p5-Try-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
