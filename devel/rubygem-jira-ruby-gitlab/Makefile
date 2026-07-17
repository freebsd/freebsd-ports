PORTNAME=	jira-ruby
PORTVERSION=	3.2.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	API for JIRA
WWW=		https://github.com/sumoheavy/jira-ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport-gitlab>=0:devel/rubygem-activesupport-gitlab \
		rubygem-cgi>=0:www/rubygem-cgi \
		rubygem-jwt>=2.1:www/rubygem-jwt \
		rubygem-multipart-post>=0:www/rubygem-multipart-post \
		rubygem-oauth-gitlab>=1.0<2:net/rubygem-oauth-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
