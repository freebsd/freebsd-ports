# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	github_api
PORTVERSION=	0.13.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Wrapper that supports all of the GitHub API v3 methods

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-addressable>=2.4.0:${PORTSDIR}/www/rubygem-addressable \
		rubygem-descendants_tracker>=0.0.4:${PORTSDIR}/devel/rubygem-descendants_tracker \
		rubygem-faraday>=0.8:${PORTSDIR}/www/rubygem-faraday \
		rubygem-hashie>=3.4:${PORTSDIR}/devel/rubygem-hashie \
		rubygem-multi_json>=1.7.5:${PORTSDIR}/devel/rubygem-multi_json \
		rubygem-oauth2>=0:${PORTSDIR}/net/rubygem-oauth2

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
