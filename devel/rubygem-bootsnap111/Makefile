PORTNAME=	bootsnap
PORTVERSION=	1.11.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	111

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Boot large ruby/rails apps faster
WWW=		https://github.com/Shopify/bootsnap

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-msgpack>=1.2<2:devel/rubygem-msgpack

USES=		gem

PORTSCOUT=	limit:^1\.11\.

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/bootsnap

.include <bsd.port.mk>
