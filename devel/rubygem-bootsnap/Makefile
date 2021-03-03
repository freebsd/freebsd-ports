# $FreeBSD$

PORTNAME=	bootsnap
PORTVERSION=	1.7.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Boot large ruby/rails apps faster

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-msgpack>=1.0<2:devel/rubygem-msgpack

USES=		gem
USE_RUBY=	yes

PLIST_FILES=	bin/bootsnap

.include <bsd.port.mk>
