# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	github_api
PORTVERSION=	0.10.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Wrapper that supports all of the GitHub API v3 methods

RUN_DEPENDS=	rubygem-addressable>=0:${PORTSDIR}/www/rubygem-addressable \
		rubygem-faraday>=0.8.7:${PORTSDIR}/www/rubygem-faraday \
		rubygem-hashie>=1.2:${PORTSDIR}/devel/rubygem-hashie \
		rubygem-multi_json>=1.4:${PORTSDIR}/devel/rubygem-multi_json \
		rubygem-nokogiri>=1.6.0:${PORTSDIR}/textproc/rubygem-nokogiri \
		rubygem-oauth2>=0:${PORTSDIR}/net/rubygem-oauth2

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
