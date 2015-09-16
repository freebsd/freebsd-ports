# $FreeBSD$

PORTNAME=	her
PORTVERSION=	0.7.6
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	ORM that maps REST resources to Ruby objects

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activemodel4>=3.0.0:${PORTSDIR}/databases/rubygem-activemodel4 \
		rubygem-activesupport4>=3.0.0:${PORTSDIR}/devel/rubygem-activesupport4 \
		rubygem-faraday>=0.8:${PORTSDIR}/www/rubygem-faraday \
		rubygem-multi_json>=1.7:${PORTSDIR}/devel/rubygem-multi_json

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
