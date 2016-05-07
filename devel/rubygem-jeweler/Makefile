# Created by: Douglas Thrift
# $FreeBSD$

PORTNAME=	jeweler
PORTVERSION=	2.0.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Simple and opinionated helper for creating Rubygem projects

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-builder32>=0:devel/rubygem-builder32 \
		rubygem-bundler>=1.0:sysutils/rubygem-bundler \
		rubygem-git>=1.2.5:devel/rubygem-git \
		rubygem-github_api>=0:devel/rubygem-github_api \
		rubygem-highline>=1.6.15:devel/rubygem-highline \
		rubygem-nokogiri>=1.5.10:textproc/rubygem-nokogiri \
		rubygem-rake>=0:devel/rubygem-rake

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/jeweler

.include <bsd.port.mk>
