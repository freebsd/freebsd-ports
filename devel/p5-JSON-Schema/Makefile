# Created by: Tom Judge <tj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	JSON-Schema
PORTVERSION=	0.015
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Validate JSON against a schema

LICENSE=	MIT

BUILD_DEPENDS=	p5-Exporter-Tiny>=0:${PORTSDIR}/devel/p5-Exporter-Tiny \
    		p5-JSON>=2.0:${PORTSDIR}/converters/p5-JSON \
    		p5-JSON-Path>=0:${PORTSDIR}/devel/p5-JSON-Path \
    		p5-JSON-Hyper>=0:${PORTSDIR}/devel/p5-JSON-Hyper \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-autovivification>=0:${PORTSDIR}/devel/p5-autovivification
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
