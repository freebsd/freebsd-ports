PORTNAME=	jira-ruby
PORTVERSION=	2.2.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	API for JIRA

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport60>=0:devel/rubygem-activesupport60 \
		rubygem-atlassian-jwt>=0:www/rubygem-atlassian-jwt \
		rubygem-multipart-post>=0:www/rubygem-multipart-post \
		rubygem-oauth>=0.5.0<1:net/rubygem-oauth

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
