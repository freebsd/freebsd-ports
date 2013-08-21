# Created by: Tomoyuki Sakurai <tomoyukis@reallyenglish.com>
# $FreeBSD$

PORTNAME=	ffi-rzmq
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	tomoyukis@reallyenglish.com
COMMENT=	ZeroMQ library for ruby using FFI

RUN_DEPENDS=	rubygem-ffi>=0:${PORTSDIR}/devel/rubygem-ffi
LIB_DEPENDS+=	zmq:${PORTSDIR}/devel/zmq

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
