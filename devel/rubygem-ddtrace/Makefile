PORTNAME=	ddtrace
PORTVERSION=	1.11.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tracking client of Datadog for Ruby
WWW=		https://github.com/DataDog/dd-trace-rb

LICENSE=	APACHE20 BSD3CLAUSE
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE.Apache
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/LICENSE.BSD3

RUN_DEPENDS=	rubygem-debase-ruby_core_source>=0.10.16<3.2.0_99:devel/rubygem-debase-ruby_core_source \
		rubygem-libdatadog>=2.0.0.1.0<2.0.0.2:devel/rubygem-libdatadog \
		rubygem-libddwaf>=1.8.2.0.0<1.8.2.1:devel/rubygem-libddwaf \
		rubygem-msgpack>=0:devel/rubygem-msgpack

USES=		gem

PLIST_FILES=	bin/ddtracerb

.include <bsd.port.mk>
