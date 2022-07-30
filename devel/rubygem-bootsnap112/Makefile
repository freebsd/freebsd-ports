PORTNAME=	bootsnap
PORTVERSION=	1.12.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	112

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Boot large ruby/rails apps faster

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-msgpack>=1.2<2:devel/rubygem-msgpack

USES=		gem
USE_RUBY=	yes

PORTSCOUT=	limit:^1\.12\.

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/bootsnap

.include <bsd.port.mk>
