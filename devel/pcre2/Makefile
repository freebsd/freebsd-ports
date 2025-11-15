PORTNAME=	pcre2
DISTVERSION=	10.47
CATEGORIES=	devel
MASTER_SITES=	https://github.com/PCRE2Project/${PORTNAME}/releases/download/${PORTNAME}-${DISTVERSION}/

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Perl Compatible Regular Expressions library, version 2
WWW=		https://www.pcre.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENCE.md

USES=		cmake:testing cpe pathfix pkgconfig tar:bz2
CPE_VENDOR=	pcre
USE_LDCONFIG=	yes

PORTDOCS=	*

CMAKE_TESTING_ON=	PCRE2_BUILD_TESTS

CMAKE_ON=		BUILD_SHARED_LIBS \
			PCRE2_BUILD_PCRE2_16 \
			PCRE2_BUILD_PCRE2_32
CMAKE_OFF=		PCRE2_BUILD_TESTS

OPTIONS_DEFINE=		DOCS LIBBZ2 LIBZ STATIC
OPTIONS_RADIO=		CLI
OPTIONS_RADIO_CLI=	LIBEDIT READLINE
OPTIONS_SUB=		yes

LIBBZ2_DESC=	Using pcre2grep with .bz2 files
LIBZ_DESC=	Using pcre2grep with .gz files

LIBBZ2_CMAKE_OFF=	-DCMAKE_DISABLE_FIND_PACKAGE_BZip2:BOOL=True

LIBEDIT_USES=		libedit
LIBEDIT_CMAKE_BOOL=	PCRE2_SUPPORT_LIBEDIT
LIBEDIT_CMAKE_OFF=	-DCMAKE_DISABLE_FIND_PACKAGE_Editline:BOOL=True

LIBZ_CMAKE_OFF=		-DCMAKE_DISABLE_FIND_PACKAGE_ZLIB:BOOL=True

READLINE_USES=		readline
READLINE_CMAKE_OFF=	-DCMAKE_DISABLE_FIND_PACKAGE_Readline:BOOL=True

STATIC_CMAKE_BOOL=	BUILD_STATIC_LIBS

.include <bsd.port.options.mk>

.if ${ARCH:Mmips64*} == "" && ${ARCH:Mriscv64*} == ""
CMAKE_ON+=	PCRE2_SUPPORT_JIT
.else
CMAKE_OFF+=	PCRE2_SUPPORT_JIT
.endif

# Optional knobs that accept positive integer parameters (see pcrebuild(3)):

# Allow the use of very large patterns (> 64K) with the 8- and 16-bit
# libraries, at the expense of longer load times (possible values:
# 2 (default), 3, and 4):
.if defined(WITH_LINK_SIZE)
CMAKE_ARGS+=	-DPCRE2_LINK_SIZE:STRING=${WITH_LINK_SIZE}
.endif

# Control PCRE resource use by limiting the default number of times pcre_exec()
# can call match() during a single operation (default: 10 million):
.if defined(WITH_MATCH_LIMIT)
CMAKE_ARGS+=	-DPCRE2_MATCH_LIMIT:STRING=${WITH_MATCH_LIMIT}
.endif

# This limit applies to all backtracks, whether or not they are nested. In
# some environments it is desirable to limit the nesting of backtracking (that
# is, the depth of tree that is searched) more strictly, in order to restrict
# the maximum amount of heap memory that is used (default: 10 million):
.if defined(WITH_MATCH_LIMIT_DEPTH)
CMAKE_ARGS+=	-DPCRE2_MATCH_LIMIT_DEPTH:STRING=${WITH_MATCH_LIMIT_DEPTH}
.endif

# Control PCRE resource use by limiting the nesting depth of parentheses in
# patterns compiled with pcre_compile() (default: 250):
.if defined(WITH_PARENS_NEST_LIMIT)
CMAKE_ARGS+=	-DPCRE2_PARENS_NEST_LIMIT:STRING=${WITH_PARENS_NEST_LIMIT}
.endif

.include <bsd.port.mk>
