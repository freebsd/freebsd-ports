# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	github_api
PORTVERSION=	0.12.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Wrapper that supports all of the GitHub API v3 methods

LICENSE=	MIT

RUN_DEPENDS=	rubygem-addressable>=2.3:${PORTSDIR}/www/rubygem-addressable \
		rubygem-descendants_tracker>=0.0.4:${PORTSDIR}/devel/rubygem-descendants_tracker \
		rubygem-faraday>=0.8:${PORTSDIR}/www/rubygem-faraday \
		rubygem-hashie>=3.2:${PORTSDIR}/devel/rubygem-hashie \
		rubygem-multi_json>=1.7.5:${PORTSDIR}/devel/rubygem-multi_json \
		rubygem-nokogiri>=1.6.3:${PORTSDIR}/textproc/rubygem-nokogiri \
		rubygem-oauth2>=0:${PORTSDIR}/net/rubygem-oauth2

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
