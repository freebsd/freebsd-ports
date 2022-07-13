# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	ddtrace
PORTVERSION=	1.2.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tracking client of Datadog for Ruby

LICENSE=	APACHE20 BSD3CLAUSE
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE.Apache
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/LICENSE.BSD3

RUN_DEPENDS=	rubygem-debase-ruby_core_source>=0.10.16<0.10.17:devel/rubygem-debase-ruby_core_source \
		rubygem-libddprof>=0.6.0.1.0<0.6.0.2:devel/rubygem-libddprof \
		rubygem-libddwaf>=1.3.0.2.0<1.3.0.3:devel/rubygem-libddwaf \
		rubygem-msgpack>=0:devel/rubygem-msgpack

USES=		gem
USE_RUBY=	yes

PLIST_FILES=	bin/ddtracerb

.include <bsd.port.mk>
