# $FreeBSD$

PORTNAME=	blobstore_client
PORTVERSION=	1.3177.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	BOSH blobstore client

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-aws-sdk-resources>=2.2.0:${PORTSDIR}/devel/rubygem-aws-sdk-resources \
		rubygem-bosh_common>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-bosh_common \
		rubygem-httpclient>=2.4.0:${PORTSDIR}/www/rubygem-httpclient \
		rubygem-multi_json>=1.1:${PORTSDIR}/devel/rubygem-multi_json

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/blobstore_client_console

.include <bsd.port.mk>
