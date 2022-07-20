PORTNAME=	webfinger
PORTVERSION=	1.1.0
PORTREVISION=	2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	WebFinger client library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-activesupport61>=3.0:devel/rubygem-activesupport61 \
		rubygem-httpclient>=2.4:www/rubygem-httpclient

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
