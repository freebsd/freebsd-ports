# Created by: Tom Judge <tj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	JSON-Hyper
PORTVERSION=	0.011
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Extract links from JSON objects

LICENSE=	MIT

BUILD_DEPENDS=	p5-JSON>=2.0:converters/p5-JSON \
		p5-JSON-Path>=0:devel/p5-JSON-Path \
		p5-URI>=1.30:net/p5-URI \
		p5-libwww>=0:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
