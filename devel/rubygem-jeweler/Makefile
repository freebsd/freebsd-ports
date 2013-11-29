# Created by: Douglas Thrift
# $FreeBSD$

PORTNAME=	jeweler
PORTVERSION=	1.8.8
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Simple and opinionated helper for creating Rubygem projects

LICENSE=	MIT

RUN_DEPENDS=	rubygem-builder>=0:${PORTSDIR}/devel/rubygem-builder \
		rubygem-bundler>=1.0:${PORTSDIR}/sysutils/rubygem-bundler \
		rubygem-git>=1.2.5:${PORTSDIR}/devel/rubygem-git \
		rubygem-highline>=1.6.15:${PORTSDIR}/devel/rubygem-highline \
		rubygem-github_api>=0.10.1:${PORTSDIR}/devel/rubygem-github_api \
		rubygem-nokogiri>=1.6.0:${PORTSDIR}/textproc/rubygem-nokogiri \
		rubygem-rake>=0:${PORTSDIR}/devel/rubygem-rake \
		rubygem-rdoc>=0:${PORTSDIR}/devel/rubygem-rdoc

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/jeweler

.include <bsd.port.mk>
