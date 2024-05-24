PORTNAME=	jira-ruby
PORTVERSION=	2.1.5
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	21

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	API for JIRA
WWW=		https://github.com/sumoheavy/jira-ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport60>=0:devel/rubygem-activesupport60 \
		rubygem-atlassian-jwt>=0:www/rubygem-atlassian-jwt \
		rubygem-multipart-post>=0:www/rubygem-multipart-post \
		rubygem-oauth0>=0.5.0<1:net/rubygem-oauth0

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^2\.1\.

.include <bsd.port.mk>
