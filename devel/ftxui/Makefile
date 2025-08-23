PORTNAME=	ftxui
DISTVERSIONPREFIX=	v
DISTVERSION=	6.1.9
CATEGORIES=	devel science

PATCH_SITES=	https://aur.archlinux.org/cgit/aur.git/plain/
# Adds the "ALL" option back and adds the install target for docs
PATCHFILES+=	ftxui_build_docs_target_all.patch?h=ftxui:-p1
# Adds the the install target for examples
PATCHFILES+=	ftxui_make_examples_installable.patch?h=ftxui:-p1

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ Functional Terminal User Interface (TUI) library
WWW=		https://github.com/ArthurSonzogni/FTXUI

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	benchmark>0:devel/benchmark \
		googletest>0:devel/googletest

USES=		cmake:testing compiler:c++20-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	ArthurSonzogni
GH_PROJECT=	FTXUI

CMAKE_OFF=	FTXUI_BUILD_TESTS
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_TESTING_ON=	FTXUI_BUILD_TESTS

PLIST_SUB=	SOVERSION=${DISTVERSION}

OPTIONS_DEFINE=	DOCS EXAMPLES
OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen
DOCS_CMAKE_BOOL=	FTXUI_BUILD_DOCS
EXAMPLES_CMAKE_BOOL=	FTXUI_BUILD_EXAMPLES

PORTDOCS=	*

.include <bsd.port.mk>
