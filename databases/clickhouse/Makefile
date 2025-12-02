PORTNAME=	clickhouse
DISTVERSIONPREFIX=	v
DISTVERSION=	25.11.1.558
DISTVERSIONSUFFIX=-stable
CATEGORIES=	databases
DIST_SUBDIR=	${PORTNAME}

# implicit-approval+: bofh
MAINTAINER=	pi@FreeBSD.org
COMMENT=	Fast open-source OLAP database management system
WWW=		https://clickhouse.com/

LICENSE=	APACHE20

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	only supported on aarch64 and amd64

BUILD_DEPENDS=	bash:shells/bash \
	nasm:devel/nasm
RUN_DEPENDS=	bash:shells/bash
.if defined(MAINTAINER_MODE)
RUN_DEPENDS+=	jq:textproc/jq
.endif

USES=		cmake cpe localbase ninja perl5 python shebangfix
CPE_VENDOR=	${PORTNAME}
USE_GITHUB=	yes
GH_ACCOUNT=	ClickHouse
GH_PROJECT=	ClickHouse
GH_TUPLE=
.include "${.CURDIR}/Makefile.submodules"
USE_PERL5=	build
USE_RC_SUBR=	${PORTNAME}

SHEBANG_FILES=	tests/clickhouse-test \
		tests/queries/0_stateless/02010_lc_native.python \
		tests/queries/0_stateless/02203_shebang
SHEBANG_GLOB=	*.expect *.py *.python *.sh
SHEBANG_LANG=	clickhouse-local expect
clickhouse-local_OLD_CMD=	/usr/bin/clickhouse-local
clickhouse-local_CMD=	${LOCALBASE}/bin/clickhouse-local
expect_OLD_CMD=	/usr/bin/expect
expect_CMD=	${LOCALBASE}/bin/expect

CMAKE_ARGS=	-DCMAKE_CXX_STANDARD=20 \
		-DNO_WERROR=1 \
		-DCOMPILER_CACHE=disabled \
		-DPARALLEL_COMPILE_JOBS=${MAKE_JOBS_NUMBER} \
		-DPARALLEL_LINK_JOBS=${MAKE_JOBS_NUMBER}
CMAKE_OFF=	ENABLE_PARQUET ENABLE_THINLTO ENABLE_UTILS

.if defined(WITH_DEBUG)
CMAKE_BUILD_TYPE=Debug
.else
CMAKE_BUILD_TYPE=Release
.endif

USERS=		clickhouse
GROUPS=		clickhouse

# The version stamp of libclickhouse.so doesn't always match ${PORTVERSION}
PLIST_SUB=	SOVERSION=${SOVERSION}

OPTIONS_DEFINE=		LLVM RUST TEST
OPTIONS_SUB=		yes

LLVM_DESC=		Build with support for JIT-compiling expressions
RUST_DESC=		Build with Rust language support

LLVM_BROKEN=		In tree LLVM is broken
LLVM_CMAKE_BOOL=	ENABLE_DWARF_PARSER ENABLE_EMBEDDED_COMPILER
RUST_BUILD_DEPENDS=	rustc:lang/rust
RUST_CMAKE_BOOL=	ENABLE_RUST
TEST_RUN_DEPENDS=	expect>0:lang/expect
TEST_CMAKE_BOOL=	ENABLE_TESTS

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
USES+=	llvm:min=21
CFLAGS+=-Wno-error=int-conversion
.endif

.if ${OPSYS} == FreeBSD
SUB_LIST+=	LEGACY_LIMITS="@comment " \
		MODERN_LIMITS=""
.else
SUB_LIST+=	LEGACY_LIMITS="" \
		MODERN_LIMITS="@comment "
.endif

SOVERSION=	${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|/var/lib/clickhouse|/var/db/clickhouse|;s|/var/log/clickhouse-server|/var/log/clickhouse|;s|/etc/clickhouse-server|${PREFIX}/etc/clickhouse-server|' ${WRKSRC}/programs/server/config.xml
	cd ${WRKSRC}/contrib/openldap-cmake && ${LN} -s freebsd_x86_64 freebsd_aarch64

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/bin/config-processor
	@${RM} -r ${STAGEDIR}${PREFIX}/include/gtest
	@${RM} ${STAGEDIR}${PREFIX}/lib/libgtest*
	@${RM} ${STAGEDIR}${PREFIX}/lib/libcxx.a
	@${RM} ${STAGEDIR}${PREFIX}/lib/libcxxabi.a
	@${RM} ${STAGEDIR}${PREFIX}/lib/libunwind.a
	@${RM} -r ${STAGEDIR}${PREFIX}/lib/debug
	${MV} ${STAGEDIR}${PREFIX}/etc/clickhouse-client/config.xml \
		${STAGEDIR}${PREFIX}/etc/clickhouse-client/config.xml.sample
	${MV} ${STAGEDIR}${PREFIX}/etc/clickhouse-server/config.xml \
		${STAGEDIR}${PREFIX}/etc/clickhouse-server/config.xml.sample
	${MV} ${STAGEDIR}${PREFIX}/etc/clickhouse-server/users.xml \
		${STAGEDIR}${PREFIX}/etc/clickhouse-server/users.xml.sample
	@${MKDIR} ${STAGEDIR}/var/db/clickhouse
	@${MKDIR} ${STAGEDIR}/var/log/clickhouse
	@${MKDIR} ${STAGEDIR}/var/run/clickhouse

do-test-TEST-on:
	cd ${WRKSRC} && ctest -j4 -V

.if defined(MAINTAINER_MODE)
_make-touples:
	@set -eu; \
	_REPO=${GH_ACCOUNT}/${GH_PROJECT}; \
	_API="https://api.github.com/repos/$${_REPO}"; \
	_TAG=${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}; \
	_TMPDIR=$$(mktemp -d -t clickhouse-submods); \
	trap 'rm -rf "$${_TMPDIR}"' EXIT INT TERM; \
	_OUTFILE="$$(pwd)/Makefile.submodules"; \
	${ECHO_CMD} "===> Resolving tag $${_TAG}"; \
	_COMMIT=$$(${FETCH_CMD} -qo - "$${_API}/git/refs/tags/$${_TAG}" \
	  | jq -r 'if type=="array" then .[0].object.sha else .object.sha end'); \
	${ECHO_CMD} "===> Commit: $${_COMMIT}"; \
	${ECHO_CMD} "===> Fetching contrib tree"; \
	${FETCH_CMD} -qo - "$${_API}/git/trees/$${_COMMIT}?recursive=1" \
	  | jq -r '.tree[] | select(.path|startswith("contrib/")) | select(.type=="commit") | "\(.path) \(.sha)"' \
	  > "$${_TMPDIR}/tree.txt"; \
	${ECHO_CMD} "===> Fetching .gitmodules"; \
	${FETCH_CMD} -qo "$${_TMPDIR}/.gitmodules" \
	  "https://raw.githubusercontent.com/$${_REPO}/$${_TAG}/.gitmodules" 2>/dev/null || true; \
	${SED} -e 's/\r$$//' "$${_TMPDIR}/.gitmodules" > "$${_TMPDIR}/.gitmodules.lf"; \
	${AWK} '/^[[:space:]]*path[[:space:]]*=/ { \
			gsub(/^[[:space:]]*path[[:space:]]*=[[:space:]]*/, "", $$0); \
			path=$$0; next } \
		/^[[:space:]]*url[[:space:]]*=/ { \
			gsub(/^[[:space:]]*url[[:space:]]*=[[:space:]]*/, "", $$0); \
			url=$$0; if (path != "" && url != "") print path, url; \
			path=""; url="" }' \
		"$${_TMPDIR}/.gitmodules.lf" > "$${_TMPDIR}/modules.txt"; \
	${ECHO_CMD} "===> Generating Makefile.gh-touples"; \
	${AWK} 'NR==FNR { urls[$$1]=$$2; next } \
		{ path=$$1; sha=$$2; url=urls[path]; if (url == "") next; \
		  n=split(url, parts, "/"); org=parts[n-1]; repo=parts[n]; sub(/\.git$$/, "", repo); \
		  org_repl=org; repo_repl=repo; gsub(/[-.]/, "_", org_repl); gsub(/[-.]/, "_", repo_repl); \
		  printf("GH_TUPLE+=\t%s:%s:%s:%s_%s/%s\n", \
		         org, repo, substr(sha,1,8), org_repl, repo_repl, path); }' \
		"$${_TMPDIR}/modules.txt" "$${_TMPDIR}/tree.txt" > "$${_OUTFILE}"; \
	${ECHO_CMD} "===> Writing $${_OUTFILE} completed"
	${REINPLACE_CMD} -e 's|unum-cloud:usearch|unum-cloud:USearch|' \
		${.CURDIR}/Makefile.submodules
	${RM} ${.CURDIR}/Makefile.submodules.bak
.endif

.include <bsd.port.mk>
