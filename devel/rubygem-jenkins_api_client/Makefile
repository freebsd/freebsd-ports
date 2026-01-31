PORTNAME=	jenkins_api_client
PORTVERSION=	2.3.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Jenkins JSON API Client
WWW=		https://github.com/arangamani/jenkins_api_client

LICENSE=	MIT

RUN_DEPENDS=	rubygem-addressable>=2.7<3:www/rubygem-addressable \
		rubygem-base64>=0:converters/rubygem-base64 \
		rubygem-json>=1.0:devel/rubygem-json \
		rubygem-logger>=0:devel/rubygem-logger \
		rubygem-mixlib-shellout>=1.1.0:devel/rubygem-mixlib-shellout \
		rubygem-nokogiri>=1.6<2:textproc/rubygem-nokogiri \
		rubygem-socksify>=1.7.0:www/rubygem-socksify \
		rubygem-terminal-table>=1.4.0:textproc/rubygem-terminal-table \
		rubygem-thor>=0.16.0:devel/rubygem-thor

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/jenkinscli

.include <bsd.port.mk>
