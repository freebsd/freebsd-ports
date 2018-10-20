# Created by: Torsten Zuehlsdorff <tz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jira-ruby
PORTVERSION=	1.6.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	API for JIRA

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport4>=4.0:devel/rubygem-activesupport4 \
		rubygem-multipart-post>=0:www/rubygem-multipart-post \
		rubygem-oauth>=0.5.0:net/rubygem-oauth

USES=		gem
USE_RUBY=	yes
NO_ARCH=	yes

.include <bsd.port.mk>
