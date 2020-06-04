# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	Test-Cukes
PORTVERSION=	0.11
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	BBD test tool inspired by Cucumber

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Moose>=0:devel/p5-Moose \
		p5-Carp-Assert>=0.20:devel/p5-Carp-Assert \
		p5-Exporter-Lite>=0.02:devel/p5-Exporter-Lite \
		p5-Try-Tiny>=0.07:lang/p5-Try-Tiny

USES=		perl5
USE_PERL5=	modbuildtiny

.include <bsd.port.mk>
