PORTNAME=	redsea
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.0
CATEGORIES=	comms

MAINTAINER=	morrand276@gmail.com
COMMENT=	Lightweight command-line FM-RDS decoder
WWW=		https://github.com/windytan/redsea/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/nlohmann/json.hpp:devel/nlohmann-json
LIB_DEPENDS=	libsndfile.so:audio/libsndfile \
		libliquid.so:comms/liquid-dsp

USES=		compiler:c++14-lang iconv localbase:ldflags meson ninja pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	windytan

PLIST_FILES=	bin/redsea
PORTDOCS=	CHANGES.md CONTRIBUTING.md README.md

OPTIONS_DEFINE=		DOCS TEST
TEST_DESC=		Build redsea_test in working directory
TEST_BUILD_DEPENDS=	${LOCALBASE}/include/catch2/catch_test_macros.hpp:devel/catch2
TEST_MESON_TRUE=	build_tests

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
