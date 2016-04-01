# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Dancer-Session-Memcached
PORTVERSION=	0.2.02
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Memcached-based session backend for Dancer

BUILD_DEPENDS=	p5-Cache-Memcached>=0:databases/p5-Cache-Memcached \
		p5-Dancer>=0:www/p5-Dancer
RUN_DEPENDS=	p5-Cache-Memcached>=0:databases/p5-Cache-Memcached \
		p5-Dancer>=0:www/p5-Dancer

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
