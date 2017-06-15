# $FreeBSD$

PORTNAME=	dm-serializer
PORTVERSION=	1.2.2
PORTREVISION=	2
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	DataMapper plugin for serializing Resources and Collections

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-dm-core>=1.2.0:databases/rubygem-dm-core \
		rubygem-fastercsv>=1.5:devel/rubygem-fastercsv \
		rubygem-json1>=1.6:devel/rubygem-json1 \
		rubygem-json_pure1>=1.6:devel/rubygem-json_pure1 \
		rubygem-multi_json>=1.0:devel/rubygem-multi_json

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
