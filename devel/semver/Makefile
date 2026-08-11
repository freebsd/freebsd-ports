PORTNAME=	semver
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.1
CATEGORIES=	devel

# Unbreak tests, see also
# https://github.com/Neargye/semver/pull/64
PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/commit/
PATCHFILES=	d0065661457e8cac5b78092544e83f25bfd19b1b.patch:-p1

MAINTAINER=	bsdcode@disroot.org
COMMENT=	Semantic Versioning for modern C++
WWW=		https://github.com/Neargye/semver

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing
USE_GITHUB=	yes
GH_ACCOUNT=	Neargye

CMAKE_OFF=		SEMVER_OPT_BUILD_EXAMPLES \
			SEMVER_OPT_BUILD_TESTS
CMAKE_TESTING_ON=	SEMVER_OPT_BUILD_TESTS

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	include/semver.hpp \
		lib/cmake/semver/semverConfig.cmake \
		lib/cmake/semver/semverConfigVersion.cmake
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install-DOCS-on:
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

post-install-EXAMPLES-on:
	(cd ${WRKSRC}/example && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
