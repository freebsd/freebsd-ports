PORTNAME=	omniauth_crowd
PORTVERSION=	2.4.0
PORTREVISION=	3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	OmniAuth provider for Atlassian Crowds REST API
WWW=		https://github.com/robdimarco/omniauth_crowd

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS?=	rubygem-activesupport61>=0:devel/rubygem-activesupport61 \
		rubygem-nokogiri>=1.4.4:textproc/rubygem-nokogiri \
		rubygem-omniauth1>=1.0<2:security/rubygem-omniauth1

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
