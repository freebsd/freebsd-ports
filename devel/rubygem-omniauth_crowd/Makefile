PORTNAME=	omniauth_crowd
PORTVERSION=	2.4.0
PORTREVISION=	2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ports@michael-fausten.de
COMMENT=	OmniAuth provider for Atlassian Crowds REST API

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS?=	rubygem-activesupport60>=0:devel/rubygem-activesupport60 \
		rubygem-nokogiri>=1.4.4:textproc/rubygem-nokogiri \
		rubygem-omniauth1>=1.0<2:security/rubygem-omniauth1

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
