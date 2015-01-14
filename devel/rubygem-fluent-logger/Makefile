# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fluent-logger
PORTVERSION=	0.4.10
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Structured event logger for Ruby

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-msgpack>=0.5.4:${PORTSDIR}/devel/rubygem-msgpack \
		rubygem-yajl-ruby>=1.0:${PORTSDIR}/devel/rubygem-yajl-ruby

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/fluent-post

.include <bsd.port.mk>
