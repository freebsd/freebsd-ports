PORTNAME=	ccache
DISTVERSION=	4.8.3
DISTVERSIONPREFIX=	v
CATEGORIES=	devel
PKGNAMESUFFIX=	4

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	Tool to minimize the compile time of C/C++ programs
WWW=		https://ccache.dev/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/GPL-3.0.txt

USES=		cmake:noninja pathfix shebangfix compiler:c++11-lang
CONFLICTS_INSTALL?=	ccache ccache-static \
		ccache-memcached ccache-memcached-static

PORTDOCS=	AUTHORS.adoc AUTHORS.html MANUAL.html MANUAL.adoc \
		NEWS.adoc NEWS.html

USE_GITHUB=	yes
SUB_FILES=	world-ccache ccache-update-links.sh ccache_clean
# Prevent infinite recursion.
NO_CCACHE_DEPEND=	yes

LIB_DEPENDS+=	libzstd.so:archivers/zstd

# /bin/bash -> /bin/sh to reduce tests dep.
SHEBANG_FILES=	test/*
SHEBANG_GLOB=	*.sh *.bash
bash_CMD=	/bin/sh

CMAKE_OFF=	WARNINGS_AS_ERRORS \
		ENABLE_IPO \
		ZSTD_FROM_INTERNET \
		ENABLE_TRACING \
		REDIS_STORAGE_BACKEND

OPTIONS_DEFINE=	DOCS CLANGLINK LLVMLINK STATIC TEST
OPTIONS_DEFAULT=CLANGLINK LLVMLINK
OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=	asciidoctor:textproc/rubygem-asciidoctor
DOCS_ALL_TARGET=	all doc
DOCS_USES=		perl5
DOCS_CMAKE_BOOL=	ENABLE_DOCUMENTATION

CLANGLINK_DESC=	Create clang compiler links if clang is installed
LLVMLINK_DESC=	Create llvm compiler links if llvm is installed

STATIC_LDFLAGS=	-static
STATIC_CMAKE_BOOL=	STATIC_LINK

TEST_CMAKE_BOOL=ENABLE_TESTING
TEST_TARGET=	check

.include <bsd.port.pre.mk>

CCLINKDIR=		libexec/ccache
PLIST_SUB+=		CCLINKDIR="${CCLINKDIR}"

.if ${ARCH}=="i386"
CCACHE_COMPILERS+=	icc icpc
.endif

GNU_COMPILERS+=		48 8 9 10 11 12 13
CCACHE_COMPILERS+=	cc c++ CC gcc g++ ${GNU_COMPILERS:S|^|gcc|} \
			${GNU_COMPILERS:S|^|g++|} \
			${GNU_COMPILERS:S|^|cpp|}

.if ${PORT_OPTIONS:MCLANGLINK}
CLANG_COMPILERS+=	10 11 12 13 14 15 16 17 -devel
CCACHE_COMPILERS+=	clang clang++ ${CLANG_COMPILERS:S|^|clang|} \
			${CLANG_COMPILERS:S|^|clang++|} \
			${CLANG_COMPILERS:S|^|cpp|}
.endif

.if ${PORT_OPTIONS:MLLVMLINK}
CCACHE_COMPILERS+=	llvm-gcc llvm-c++ llvm-g++
.endif

CCACHE_COMPILERS+=	${EXTRA_COMPILERS}
SUB_LIST+=		CCACHE_COMPILERS="${CCACHE_COMPILERS}" \
			CCLINKDIR="${CCLINKDIR}"

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${CCLINKDIR}/world
	${INSTALL_SCRIPT} ${WRKDIR}/world-ccache \
		${STAGEDIR}${PREFIX}/${CCLINKDIR}/world/ccache
	${INSTALL_SCRIPT} ${WRKDIR}/ccache-update-links.sh \
		${STAGEDIR}${PREFIX}/bin/ccache-update-links
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/daily
	${INSTALL_SCRIPT} ${WRKDIR}/ccache_clean \
		${STAGEDIR}${PREFIX}/etc/periodic/daily

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/doc/*.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.adoc ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
