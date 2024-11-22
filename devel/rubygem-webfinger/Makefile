PORTNAME=	webfinger
PORTVERSION=	2.1.3
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	WebFinger client library
WWW=		https://github.com/nov/webfinger

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-activesupport70>=3.0:devel/rubygem-activesupport70 \
		rubygem-faraday-gitlab>=2.0<3:www/rubygem-faraday-gitlab \
		rubygem-faraday-follow_redirects-gitlab>=0:www/rubygem-faraday-follow_redirects-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
