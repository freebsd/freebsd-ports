# $FreeBSD$

PORTNAME=	blobstore_client
PORTVERSION=	1.3098.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	BOSH blobstore client

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-aws-sdk>=1.60.2:${PORTSDIR}/devel/rubygem-aws-sdk \
		rubygem-bosh_common>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-bosh_common \
		rubygem-fog>=1.31.0:${PORTSDIR}/devel/rubygem-fog \
		rubygem-fog-aws>=0.7.6:${PORTSDIR}/net/rubygem-fog-aws \
		rubygem-httpclient>=2.4.0:${PORTSDIR}/www/rubygem-httpclient \
		rubygem-multi_json>=1.1:${PORTSDIR}/devel/rubygem-multi_json

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/blobstore_client_console

.include <bsd.port.mk>
