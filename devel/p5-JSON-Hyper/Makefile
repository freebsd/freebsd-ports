# Created by: Tom Judge <tj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	JSON-Hyper
PORTVERSION=	0.011
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Extract links from JSON objects

LICENSE=	MIT

BUILD_DEPENDS=	p5-JSON>=2.0:${PORTSDIR}/converters/p5-JSON \
		p5-JSON-Path>=0:${PORTSDIR}/devel/p5-JSON-Path \
		p5-URI>=1.30:${PORTSDIR}/net/p5-URI \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
