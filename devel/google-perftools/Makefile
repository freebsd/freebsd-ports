PORTNAME=	google-perftools
DISTVERSIONPREFIX=	gperftools-
DISTVERSION=	2.17.2
CATEGORIES=	devel
MASTER_SITES=	https://github.com/gperftools/gperftools/releases/download/gperftools-${PORTVERSION}/
DISTNAME=	gperftools-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast, multi-threaded malloc() and nifty performance analysis tools
WWW=		https://github.com/gperftools/gperftools

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_aarch64=	link fails: ld: error: undefined symbol: brk, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=278009
BROKEN_armv7=	error: use of undeclared identifier '_URC_NO_REASON', see https://github.com/gperftools/gperftools/issues/1360
BROKEN_riscv64=	error: Cannot calculate stack trace: will need to write for your environment, see https://github.com/gperftools/gperftools/issues/1359

USES=		compiler:c11 gmake libtool localbase:ldflags perl5 # tests also require c++17 compiler
USE_LDCONFIG=	yes
USE_PERL5=	test

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

TEST_TARGET=	check # 7 tests are failing, see https://github.com/gperftools/gperftools/issues/1572
TESTING_UNSAFE=	yes

LIBS+=		-lexecinfo

DOCSDIR=	${PREFIX}/share/doc/gperftools

OPTIONS_DEFINE=			DOCS PROFILER
OPTIONS_SINGLE=			PAGESIZE ALIGN
OPTIONS_SINGLE_ALIGN=		ALIGN8 ALIGN16
OPTIONS_SINGLE_PAGESIZE=	PAGE8K PAGE32K PAGE64K
OPTIONS_DEFAULT=		PAGE8K ALIGN16
OPTIONS_DEFAULT_aarch64=	# PROFILER  is disabled: WARNING: Could not find the PC. Will not try to compile libprofiler, see https://github.com/gperftools/gperftools/issues/1362
OPTIONS_DEFAULT_amd64=		PROFILER
OPTIONS_DEFAULT_armv6=		# PROFILER is disabled: WARNING: Could not find the PC. Will not try to compile libprofiler.
OPTIONS_DEFAULT_armv7=		# PROFILER is disabled: WARNING: Could not find the PC. Will not try to compile libprofiler.
OPTIONS_DEFAULT_i386=		PROFILER
OPTIONS_DEFAULT_powerpc=	PROFILER
OPTIONS_DEFAULT_powerpc64=	PROFILER
OPTIONS_DEFAULT_powerpc64le=	PROFILER
OPTIONS_DEFAULT_riscv64=	PROFILER
OPTIONS_SUB=		yes

PROFILER_DESC=		Enable CPU profiler
PROFILER_CONFIGURE_ENABLE=	cpu-profiler

ALIGN_DESC=	The tcmalloc allocation alignment
ALIGN8_DESC=	8 bytes allocation alignment
ALIGN16_DESC=	16 bytes allocation alignment
PAGESIZE_DESC=	The tcmalloc internal page size
PAGE8K_DESC=	8K page size
PAGE32K_DESC=	32K page size
PAGE64K_DESC=	64K page size

ALIGN8_CONFIGURE_ON=	--with-tcmalloc-alignment=8
ALIGN16_CONFIGURE_ON=	--with-tcmalloc-alignment=16
PAGE8K_CONFIGURE_ON=	--with-tcmalloc-pagesize=8
PAGE32K_CONFIGURE_ON=	--with-tcmalloc-pagesize=32
PAGE64K_CONFIGURE_ON=	--with-tcmalloc-pagesize=64

PORTDOCS=	*

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == "clang" && !defined(USE_GCC)
# clang cannot disable builtins individually
CXXFLAGS+=	-fno-builtin
.endif

.if ${ARCH} == "amd64"
CONFIGURE_ARGS+=--enable-frame-pointers
.endif

# keep in sync with all platforms where libunwind is available
.if ${ARCH} == aarch64 || ${ARCH} == amd64 || ${ARCH} == armv6 || ${ARCH} == armv7 || ${ARCH} == i386 || ${ARCH} == powerpc || ${ARCH} == powerpc64 || ${ARCH} == powerpc64le
LIB_DEPENDS+=	libunwind.so:devel/libunwind
LIBS+=		-lunwind
.endif

post-build:
	@${ECHO}
	@${ECHO} "Please run 'make check' (requires bash)."
	@${ECHO} "Two testcases are known to fail. Testsuite is known to be"
	@${ECHO} "unreliable and give false positives and negatives (PR#661)."
	@${ECHO}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*.so.*

# tests as of 2.17.2: PASS:  48 (all pass)

.include <bsd.port.post.mk>
