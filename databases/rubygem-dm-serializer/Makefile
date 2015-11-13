# $FreeBSD$

PORTNAME=	dm-serializer
PORTVERSION=	1.2.2
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	DataMapper plugin for serializing Resources and Collections

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-dm-core>=1.2.0:${PORTSDIR}/databases/rubygem-dm-core \
		rubygem-fastercsv>=1.5:${PORTSDIR}/devel/rubygem-fastercsv \
  		rubygem-json>=1.6:${PORTSDIR}/devel/rubygem-json \
		rubygem-json_pure>=1.6:${PORTSDIR}/devel/rubygem-json_pure \
		rubygem-multi_json>=1.0:${PORTSDIR}/devel/rubygem-multi_json

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
