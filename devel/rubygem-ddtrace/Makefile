PORTNAME=	ddtrace
PORTVERSION=	1.17.0
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tracking client of Datadog for Ruby
WWW=		https://github.com/DataDog/dd-trace-rb

LICENSE=	APACHE20 BSD3CLAUSE
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE.Apache
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/LICENSE.BSD3

RUN_DEPENDS=	rubygem-datadog-ci>=0.4.0<0.5:devel/rubygem-datadog-ci \
		rubygem-debase-ruby_core_source>=3.2.3<3.2.3_99:devel/rubygem-debase-ruby_core_source \
		rubygem-libdatadog>=5.0.0.1.0<5.0.0.2:devel/rubygem-libdatadog \
		rubygem-libddwaf>=1.14.0.0.0<1.14.0.1:devel/rubygem-libddwaf \
		rubygem-msgpack>=0:devel/rubygem-msgpack

USES=		gem

PLIST_FILES=	bin/ddtracerb

.include <bsd.port.mk>
