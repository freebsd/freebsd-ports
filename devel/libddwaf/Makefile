PORTNAME=	libddwaf
PORTVERSION=	1.27.0
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Datadog WAF engine
WWW=		https://github.com/DataDog/libddwaf

LICENSE=	APACHE20 BSD3CLAUSE
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE.Apache
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/LICENSE.BSD3

BUILD_DEPENDS=	rapidjson>=0:devel/rapidjson
LIB_DEPENDS=	libac.so:devel/libac \
		libinjection.so:devel/libinjection \
		libre2.so:devel/re2 \
		libutf8proc.so:textproc/utf8proc

USES=		cmake compiler:c++20-lang localbase:ldflags

CFLAGS+=	-I${LOCALBASE}/include/re2
CMAKE_OFF=	LIBDDWAF_TESTING \
		LIBDDWAF_TEST_COVERAGE
CMAKE_ON=	LIBDDWAF_BUILD_SHARED \
		LIBDDWAF_BUILD_STATIC \
		LIBDDWAF_ENABLE_LTO \
		LIBDDWAF_VECTORIZED_TRANSFORMERS

USE_GITHUB=	yes
GH_ACCOUNT=	DataDog

post-patch:
# Clean up bundled libraries
	#@${RM} -r ${WRKSRC}/src/vendor/fmt/
	@${RM} -r ${WRKSRC}/src/vendor/libinjection/
	@${RM} -r ${WRKSRC}/src/vendor/lua-aho-corasick/
	#@${RM} -r ${WRKSRC}/src/vendor/radixlib/
	@${RM} -r ${WRKSRC}/src/vendor/re2/
	@${RM} -r ${WRKSRC}/src/vendor/utf8proc/

.include <bsd.port.mk>
