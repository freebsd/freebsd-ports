# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	travis
PORTVERSION=	1.8.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	CLI and Ruby client library for Travis CI

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-backports>=0:devel/rubygem-backports \
		rubygem-faraday>=0.9:www/rubygem-faraday \
		rubygem-faraday_middleware>=0.9.1:www/rubygem-faraday_middleware \
		rubygem-gh>=0.13:devel/rubygem-gh \
		rubygem-highline>=1.6:devel/rubygem-highline \
		rubygem-launchy>=2.1:devel/rubygem-launchy \
		rubygem-pusher-client>=0.4:www/rubygem-pusher-client \
		rubygem-typhoeus>=0.6.8:www/rubygem-typhoeus

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/travis

.include <bsd.port.mk>
