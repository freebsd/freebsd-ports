PORTNAME=	datadog
PORTVERSION=	2.2.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Datadog's client library for Ruby
WWW=		https://github.com/DataDog/dd-trace-rb

LICENSE=	APACHE20 BSD3CLAUSE
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE.Apache
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/LICENSE.BSD3

RUN_DEPENDS=	rubygem-debase-ruby_core_source>=3.3.1<3.3.1_99:devel/rubygem-debase-ruby_core_source \
		rubygem-libdatadog>=10.0.0.1.0<10.0.0.2:devel/rubygem-libdatadog \
		rubygem-libddwaf>=1.14.0.0.0<1.14.0.1:devel/rubygem-libddwaf \
		rubygem-msgpack>=0:devel/rubygem-msgpack

USES=		gem

PLIST_FILES=	bin/ddprofrb

.include <bsd.port.mk>
