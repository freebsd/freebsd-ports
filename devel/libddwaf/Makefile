PORTNAME=	libddwaf
PORTVERSION=	1.11.0
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Datadog WAF engine
WWW=		https://github.com/DataDog/libddwaf

LICENSE=	APACHE20 BSD3CLAUSE
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE.Apache
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/LICENSE.BSD3

BUILD_DEPENDS=	rapidjson>=1.1.0.524:devel/rapidjson
LIB_DEPENDS=	libac.so:devel/libac \
		libbenchmark.so:devel/benchmark \
		libgtest.so:devel/googletest \
		libinjection.so:devel/libinjection \
		libre2.so:devel/re2 \
		libutf8proc.so:textproc/utf8proc \
		libyaml-cpp.so:devel/yaml-cpp

USES=		cmake compiler:c++17-lang localbase:ldflags

CMAKE_OFF=	LIBDDWAF_KEEP_SYMBOL_FILE LIBDDWAF_TESTING
CMAEK_ON=	LIBDDWAF_BUILD_SHARED LIBDDWAF_BUILD_STATIC

USE_GITHUB=	yes
GH_ACCOUNT=	DataDog
GH_TUPLE=	DataDog:appsec-event-rules:1.7.1:DataDog_appsec_event_rules/third_party/proj_event_rules \
		Tencent:rapidjson:973dc9c:Tencent_rapidjson/third_party/rapidjson

post-patch:
# Clean up bundled libraries
	@${RM} -r ${WRKSRC}/third_party/libinjection/
	@${RM} -r ${WRKSRC}/third_party/lua-aho-corasick/

.include <bsd.port.mk>
