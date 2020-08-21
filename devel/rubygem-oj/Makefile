# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	oj
PORTVERSION=	3.10.9
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast JSON parser and serializer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgmp.so:math/gmp
RUN_DEPENDS=	rubygem-bigdecimal>=2.0<3:math/rubygem-bigdecimal

USES=		gem
USE_RUBY=	yes

.include <bsd.port.mk>
