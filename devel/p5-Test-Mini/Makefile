# Created by: Kurt Lidl <kurt.lidl@cello.com>
# $FreeBSD$

PORTNAME=	Test-Mini
PORTVERSION=	v1.1.3
PORTREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PVANDE
PKGNAMEPREFIX=	p5-

MAINTAINER=	kurt.lidl@cello.com
COMMENT=	Provides lightweight unit testing framework

BUILD_DEPENDS=	p5-Data-Inspect>=0.03:devel/p5-Data-Inspect \
		p5-Exception-Class>=1.30:devel/p5-Exception-Class \
		p5-IO-stringy>=2.110:devel/p5-IO-stringy \
		p5-MRO-Compat>=0.10:devel/p5-MRO-Compat \
		p5-Text-Outdent>=0.01:devel/p5-Text-Outdent \
		p5-Try-Tiny>=0.04:lang/p5-Try-Tiny \
		p5-aliased>=0.30:devel/p5-aliased \
		p5-namespace-clean>=0.14:devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
