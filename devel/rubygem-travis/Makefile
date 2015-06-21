# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	travis
PORTVERSION=	1.7.7
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	CLI and Ruby client library for Travis CI

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-addressable>=2.3:${PORTSDIR}/www/rubygem-addressable \
		rubygem-backports>=0:${PORTSDIR}/devel/rubygem-backports \
		rubygem-faraday>=0.9:${PORTSDIR}/www/rubygem-faraday \
		rubygem-faraday_middleware>=0.9.1:${PORTSDIR}/www/rubygem-faraday_middleware \
		rubygem-gh>=0.13:${PORTSDIR}/devel/rubygem-gh \
		rubygem-highline>=1.6:${PORTSDIR}/devel/rubygem-highline \
		rubygem-launchy>=2.1:${PORTSDIR}/devel/rubygem-launchy \
		rubygem-pry>=0.9:${PORTSDIR}/devel/rubygem-pry \
		rubygem-pusher-client>=0.4:${PORTSDIR}/www/rubygem-pusher-client \
		rubygem-typhoeus>=0.6.8:${PORTSDIR}/www/rubygem-typhoeus

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/travis

.include <bsd.port.mk>
