PORTNAME=	lief
PORTVERSION=	0.17.3
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library to Instrument Executable Formats (C++)
WWW=		https://lief.re/ \
		https://github.com/lief-project/LIEF

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/tcb/span.hpp:devel/span \
		frozen>=0:devel/frozen \
		nanobind>=0:devel/nanobind \
		nlohmann-json>=0:devel/nlohmann-json \
		tl-expected>=0:devel/tl-expected \
		utf8cpp>=0:devel/utf8cpp
LIB_DEPENDS=	libmbedtls.so:security/mbedtls3 \
		libspdlog.so:devel/spdlog

USES=		cmake:testing localbase:ldflags pkgconfig

CMAKE_OFF=	LIEF_ASAN \
		LIEF_ASM \
		LIEF_DEBUG_INFO \
		LIEF_DISABLE_FROZEN \
		LIEF_DOC \
		LIEF_DYLD_SHARED_CACHE \
		LIEF_EXTRA_WARNINGS \
		LIEF_FORCE32 \
		LIEF_FORCE_API_EXPORTS \
		LIEF_FUZZING \
		LIEF_LSAN \
		LIEF_OBJC \
		LIEF_PYTHON_API \
		LIEF_RUST_API \
		LIEF_TESTS \
		LIEF_TSAN \
		LIEF_USAN \
		LIEF_USE_MELKOR
CMAKE_ON=	BUILD_SHARED_LIBS \
		LIEF_ART \
		LIEF_COFF \
		LIEF_C_API \
		LIEF_DEX \
		LIEF_DISABLE_EXCEPTIONS \
		LIEF_ELF \
		LIEF_ENABLE_JSON \
		LIEF_EXAMPLES \
		LIEF_EXTERNAL_EXPECTED \
		LIEF_EXTERNAL_SPDLOG \
		LIEF_INSTALL \
		LIEF_INSTALL_COMPILED_EXAMPLES \
		LIEF_LOGGING \
		LIEF_LOGGING_DEBUG \
		LIEF_MACHO \
		LIEF_OAT \
		LIEF_OPT_EXTERNAL_EXPECTED \
		LIEF_OPT_EXTERNAL_SPAN \
		LIEF_OPT_FROZEN_EXTERNAL \
		LIEF_OPT_MBEDTLS_EXTERNAL \
		LIEF_OPT_NANOBIND_EXTERNAL \
		LIEF_OPT_NLOHMANN_JSON_EXTERNAL \
		LIEF_OPT_UTFCPP_EXTERNAL \
		LIEF_PE \
		LIEF_PROFILING \
		LIEF_SO_VERSION \
		LIEF_USE_CCACHE \
		LIEF_VDEX
CMAKE_TESTING_ON=	\
		LIEF_TESTS

USE_GITHUB=	yes
GH_ACCOUNT=	lief-project
GH_PROJECT=	LIEF

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/CMakeLists.txt
# Clean up bundled libraries
	@${RM} -r ${WRKSRC}/third-party/

.include <bsd.port.mk>
