# Created by: Matthias Fechner <mfechner@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jaeger-client
PORTVERSION=	0.10.0
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	OpenTracing Tracer implementation for Jaeger in Ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-opentracing>=0.3:devel/rubygem-opentracing \
		rubygem-thrift>=0:devel/rubygem-thrift

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
