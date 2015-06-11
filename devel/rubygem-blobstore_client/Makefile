# $FreeBSD$

PORTNAME=	blobstore_client
PORTVERSION=	1.2941.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	BOSH blobstore client

RUN_DEPENDS=	rubygem-bosh_common>=1.2941.0:${PORTSDIR}/devel/rubygem-bosh_common \
		rubygem-fog>=1.27.0:${PORTSDIR}/devel/rubygem-fog \
		rubygem-httpclient>=2.4.0:${PORTSDIR}/www/rubygem-httpclient \
		rubygem-multi_json>=1.1:${PORTSDIR}/devel/rubygem-multi_json \
		rubygem-ruby-atmos-pure>=1.0.5:${PORTSDIR}/devel/rubygem-ruby-atmos-pure \
		rubygem-aws-sdk>=1.60.2:${PORTSDIR}/devel/rubygem-aws-sdk

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=yes

PLIST_FILES=	bin/blobstore_client_console

.include <bsd.port.mk>
