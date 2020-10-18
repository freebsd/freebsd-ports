# Created by: Douglas Thrift
# $FreeBSD$

PORTNAME=	jeweler
PORTVERSION=	2.3.9
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Simple and opinionated helper for creating Rubygem projects

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-builder>=0:devel/rubygem-builder \
		rubygem-bundler>=0:sysutils/rubygem-bundler \
		rubygem-git>=1.2.5:devel/rubygem-git \
		rubygem-github_api>=0.16.0<1:devel/rubygem-github_api \
		rubygem-highline>=1.6.15:devel/rubygem-highline \
		rubygem-nokogiri>=1.5.10:textproc/rubygem-nokogiri \
		rubygem-psych>=0:textproc/rubygem-psych \
		rubygem-rake>=0:devel/rubygem-rake \
		rubygem-rdoc>=0:devel/rubygem-rdoc \
		rubygem-semver2>=0:devel/rubygem-semver2

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/jeweler

.include <bsd.port.mk>
