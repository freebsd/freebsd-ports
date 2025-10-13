PORTNAME=	jira-ruby
PORTVERSION=	3.0.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	API for JIRA
WWW=		https://github.com/sumoheavy/jira-ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport60>=0:devel/rubygem-activesupport60 \
		rubygem-atlassian-jwt>=0:www/rubygem-atlassian-jwt \
		rubygem-multipart-post>=0:www/rubygem-multipart-post \
		rubygem-oauth>=1.0<2:net/rubygem-oauth

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
