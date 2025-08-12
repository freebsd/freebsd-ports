PORTNAME=	datadog
PORTVERSION=	2.19.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Datadog's client library for Ruby
WWW=		https://github.com/DataDog/dd-trace-rb

LICENSE=	APACHE20 BSD3CLAUSE
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE.Apache
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/LICENSE.BSD3

RUN_DEPENDS=	rubygem-datadog-ruby_core_source>=3.4.1<4:devel/rubygem-datadog-ruby_core_source \
		rubygem-libdatadog>=18.1.0.1.0<18.1.0.2:devel/rubygem-libdatadog \
		rubygem-libddwaf>=1.24.1.0.3<1.24.1.1:devel/rubygem-libddwaf \
		rubygem-logger>=0:devel/rubygem-logger \
		rubygem-msgpack>=0:devel/rubygem-msgpack

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/ddprofrb

.include <bsd.port.mk>
