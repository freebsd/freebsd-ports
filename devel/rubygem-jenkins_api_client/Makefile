# $FreeBSD$

PORTNAME=	jenkins_api_client
PORTVERSION=	1.5.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Jenkins JSON API Client

RUN_DEPENDS=	rubygem-nokogiri>=1.6:textproc/rubygem-nokogiri \
		rubygem-thor>=0.16.0:devel/rubygem-thor \
		rubygem-terminal-table>=1.4.0:textproc/rubygem-terminal-table \
		rubygem-mixlib-shellout>=1.1.0:devel/rubygem-mixlib-shellout \
		rubygem-socksify>=1.7.0:www/rubygem-socksify \
		rubygem-json>=1.0:devel/rubygem-json

USE_RUBY=	yes
USES=		gem
PLIST_FILES=	bin/jenkinscli

.include <bsd.port.mk>
