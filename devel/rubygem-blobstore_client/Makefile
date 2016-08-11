# $FreeBSD$

PORTNAME=	blobstore_client
PORTVERSION=	1.3215.0
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	BOSH blobstore client

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-aws-sdk-resources>=2.2.0:devel/rubygem-aws-sdk-resources \
		rubygem-bosh_common>=${PORTVERSION}:devel/rubygem-bosh_common \
		rubygem-httpclient>=2.7.1:www/rubygem-httpclient \
		rubygem-multi_json>=1.1:devel/rubygem-multi_json

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/blobstore_client_console

.include <bsd.port.mk>
