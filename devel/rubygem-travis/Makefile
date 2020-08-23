# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	travis
PORTVERSION=	1.9.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	CLI and Ruby client library for Travis CI

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-faraday>=1.0<2:www/rubygem-faraday \
		rubygem-faraday_middleware>=1.0<2:www/rubygem-faraday_middleware \
		rubygem-gh>=0.13<1:devel/rubygem-gh \
		rubygem-highline>=2.0<3:devel/rubygem-highline \
		rubygem-json>=2.3<3:devel/rubygem-json \
		rubygem-launchy>=2.1<3:devel/rubygem-launchy \
		rubygem-pusher-client>=0.4<1:www/rubygem-pusher-client \
		rubygem-typhoeus>=0.6.8:www/rubygem-typhoeus

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/travis

.include <bsd.port.mk>
