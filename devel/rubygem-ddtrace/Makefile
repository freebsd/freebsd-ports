# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	ddtrace
PORTVERSION=	0.46.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tracking client of Datadog for Ruby

LICENSE=	APACHE20 BSD3CLAUSE
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE.Apache
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/LICENSE.BSD3

RUN_DEPENDS=	rubygem-msgpack>=0:devel/rubygem-msgpack

USES=		gem shebangfix
USE_RUBY=	yes

NO_ARCH=	yes

SHEBANG_FILES=	integration/apps/rack/script/build-images \
		integration/apps/rack/script/ci \
		integration/apps/rails-five/script/build-images \
		integration/apps/rails-five/script/ci \
		integration/apps/ruby/script/build-images \
		integration/apps/ruby/script/ci \
		integration/images/include/http-health-check \
		integration/images/wrk/scripts/entrypoint.sh \
		integration/script/build-images

.include <bsd.port.mk>
