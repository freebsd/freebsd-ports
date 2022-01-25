PORTNAME=	bootsnap
PORTVERSION=	1.9.4
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	19

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Boot large ruby/rails apps faster

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-msgpack>=1.0<2:devel/rubygem-msgpack

USES=		gem
USE_RUBY=	yes

PLIST_FILES=	bin/bootsnap

PORTSCOUT=	limit:^1\.9\.

.include <bsd.port.mk>
