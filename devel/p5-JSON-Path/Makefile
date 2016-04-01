# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	JSON-Path
PORTVERSION=	0.205
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Search nested hashref/arrayref structures using JSONPath

LICENSE=	MIT

BUILD_DEPENDS=	p5-Exporter-Tiny>=0:devel/p5-Exporter-Tiny \
		p5-JSON>=0:converters/p5-JSON \
		p5-LV>=0:devel/p5-LV
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
