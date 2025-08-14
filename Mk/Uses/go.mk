# This file contains logic to ease porting of Go binaries using the
# `go` command.
#
# Feature:	go
# Usage:	USES=go
# Valid ARGS:	(none), N.NN, N.NN-devel, modules, no_targets, run
#
# (none)	Setup GOPATH and build in GOPATH mode using default Go version.
# N.NN[-devel]	Specify Go version
# modules	If the upstream uses Go modules, this can be set to build
#		in modules-aware mode.
# no_targets	Indicates that Go is needed at build time as a part of
#		make/CMake build.  This will setup build environment like
#		GO_ENV, GO_BUILDFLAGS but will not create post-extract and
#		do-{build,install,test} targets.
# run		Indicates that Go is needed at run time and adds it to
#		RUN_DEPENDS.
#
# You can set the following variables to control the process.
#
# GO_MODULE
#	The name of the module as specified by "module" directive in go.mod.
#	In most cases, this is the only required variable for ports that
#	use Go modules.
#
# GO_MOD_DIST
#       The location to download the go.mod file if GO_MODULE is used.
#       The default is empty, so it is loaded from GO_PROXY.
#       Set it to "gitlab" and make sure GL_PROJECT is defined to download
#       the "go.mod" from gitlab.
#       Set it to "github" and make sure GH_PROJECT is defined to download
#       the "go.mod" from github.
#       You can also set it completely manually a URI without go.mod in it,
#       is attached automatically to the URI.
#
# GO_PKGNAME
#	The name of the package when building in GOPATH mode.  This
#	is the directory that will be created in ${GOPATH}/src.  If not set
#	explicitly and GH_SUBDIR or GL_SUBDIR is present, GO_PKGNAME will
#	be inferred from it.
#	It is not needed when building in modules-aware mode.
#
# GO_TARGET
#	The packages to build.  The default value is ${GO_PKGNAME}.
#	GO_TARGET can also be a tuple in the form package:path where path can be
#	either a simple filename or a full path starting with ${PREFIX}.
#
# GO_TESTTARGET
#	The packages to test. The default value is `./...` (the current package
#	and all subpackages).
#
# CGO_CFLAGS
#	Additional CFLAGS variables to be passed to the C compiler by the `go`
#	command
#
# CGO_LDFLAGS
#	Additional LDFLAGS variables to be passed to the C compiler by the `go`
#	command
#
# GO_BUILDFLAGS
#	Additional build arguments to be passed to the `go build` command
#
# GO_TESTFLAGS
#	Additional build arguments to be passed to the `go test` command
#
# MAINTAINER: go@FreeBSD.org

.if !defined(_INCLUDE_USES_GO_MK)
_INCLUDE_USES_GO_MK=	yes

# When adding a version, please keep the comment in
# Mk/bsd.default-versions.mk in sync.
GO_VALID_VERSIONS=	1.20 1.21 1.22 1.23 1.24 1.25 1.26-devel

# Check arguments sanity
.  if !empty(go_ARGS:N[1-9].[0-9][0-9]:N*-devel:Nmodules:Nno_targets:Nrun)
IGNORE=	USES=go has invalid arguments: ${go_ARGS:N[1-9].[0-9][0-9]:N*-devel:Nmodules:Nno_targets:Nrun}
.  endif

# Parse Go version
GO_VERSION=	${go_ARGS:Nmodules:Nno_targets:Nrun:C/^$/${GO_DEFAULT}/}
.  if empty(GO_VALID_VERSIONS:M${GO_VERSION})
IGNORE?= USES=go has invalid version number: ${GO_VERSION}
.  endif
GO_SUFFIX=	${GO_VERSION:S/.//:C/.*-devel/-devel/}
GO_PORT=	lang/go${GO_SUFFIX}

# Settable variables

.  if empty(GO_PKGNAME)
.    if !empty(GH_SUBDIR)
GO_PKGNAME=	${GH_SUBDIR:S|^src/||}
.    elif !empty(GL_SUBDIR)
GO_PKGNAME=	${GL_SUBDIR:S|^src/||}
.    else
GO_PKGNAME=	${PORTNAME}
.    endif
.  endif

GO_TARGET?=	${GO_PKGNAME}
GO_TESTTARGET?=	./...

.  if !defined(PIE_UNSAFE) && defined(WITH_PIE) && ${ARCH} == amd64
GO_BUILDFLAGS+= -buildmode=pie
.  else
GO_BUILDFLAGS+= -buildmode=exe
.  endif
GO_BUILDFLAGS+= -v -trimpath
.  if !defined(WITH_DEBUG) && empty(GO_BUILDFLAGS:M-ldflags*)
GO_BUILDFLAGS+=	-ldflags=-s
.  endif
GO_BUILDFLAGS+=	-buildvcs=false
GO_TESTFLAGS+=	-v -buildvcs=false

CGO_ENABLED?=	1
CGO_CFLAGS+=	-I${LOCALBASE}/include
CGO_LDFLAGS+=	-L${LOCALBASE}/lib

.  if ${ARCH} == armv6 || ${ARCH} == armv7
GOARM?=		${ARCH:C/armv//}
.  endif

GO_GOPROXY?=	https://proxy.golang.org
GO_GOSUMDB?=	sum.golang.org

# Read-only variables

GO_CMD=		${LOCALBASE}/bin/go${GO_SUFFIX}
GO_WRKDIR_BIN=	${WRKDIR}/bin
GO_ENV+=	CGO_ENABLED=${CGO_ENABLED} \
		CGO_CFLAGS="${CGO_CFLAGS}" \
		CGO_LDFLAGS="${CGO_LDFLAGS}" \
		GOAMD64=${GOAMD64} \
		GOARM=${GOARM} \
		GOTMPDIR="${WRKDIR}"

.  if ${go_ARGS:Mmodules}
GO_BUILDFLAGS+=	-mod=vendor
GO_TESTFLAGS+=	-mod=vendor
GO_GOPATH=	${DISTDIR}/go/${PKGORIGIN:S,/,_,g}
GO_MODCACHE=	file://${GO_GOPATH}/pkg/mod/cache/download
GO_WRKSRC=	${WRKSRC}
GO_ENV+=	GOPATH="${GO_GOPATH}" \
		GOBIN="${GO_WRKDIR_BIN}" \
		GO111MODULE=on \
		GOFLAGS=-modcacherw \
		GOSUMDB=${GO_GOSUMDB}
.    if defined(GO_MODULE)
GO_MODNAME=	${GO_MODULE:C/^([^@]*)(@([^@]*)?)/\1/}
.      if empty(DISTFILES:Mgo.mod\:*) && empty(DISTFILES:Mgo.mod)
# Unless already setup for download by other means,
# arrange to pull go.mod and distribution archive from GOPROXY.
GO_MODVERSION=	${GO_MODULE:C/^([^@]*)(@([^@]*)?)/\2/:M@*:S/^@//:S/^$/${DISTVERSIONFULL}/}
GO_MODFILE=	${GO_MODVERSION}.mod
GO_DISTFILE=	${GO_MODVERSION}.zip
# If GO_MOD_DIST is gitlab, download the go.mod from gitlab by the defined GL_ACCOUNT and GL_PROJECT/PORTNAME
.        if defined(GO_MOD_DIST) && "${GO_MOD_DIST}" == "gitlab"
MASTER_SITES+=	https://gitlab.com/${GL_ACCOUNT}/${GL_PROJECT}/-/raw/${GO_MODVERSION}/${WRKSRC_SUBDIR:?${WRKSRC_SUBDIR}/:}
DISTFILES+=	go.mod
# If GO_MOD_DIST is github, download the go.mod from github by the defined GH_ACCOUNT and GH_PROJECT/PORTNAME
.        elif defined(GO_MOD_DIST) && "${GO_MOD_DIST}" == "github"
MASTER_SITES+=	https://raw.githubusercontent.com/${GH_ACCOUNT}/${GH_PROJECT}/${GO_MODVERSION}/${WRKSRC_SUBDIR:?${WRKSRC_SUBDIR}/:}
DISTFILES+=	go.mod
# Manually defined GO_MOD_DIST
.        elifdef(GO_MOD_DIST)
MASTER_SITES+=	${GO_MOD_DIST}
DISTFILES+=	go.mod
# Fallback to default GO_PROXY
.        else

# `GOPROXY` presents sources via the proxy service and in the downloaded
# `WRKSRC` differently as of v2.x versions of projects. Support this different
# directory/REST API scheme: https://go.dev/ref/mod#major-version-suffixes .
# GO_MODVERSION_MAJOR=	${GO_MODVERSION:C/^v//g:C/\..+//g}
# .if ${GO_MODVERSION_MAJOR} > 1
# WRKSRC=		${WRKDIR}/${GO_MODNAME}/v${GO_MODVERSION_MAJOR}@${GO_MODVERSION}
# MASTER_SITES+=	${GO_GOPROXY}/${GO_MODNAME:C/([A-Z])/!\1/g:tl}/v${GO_MODVERSION_MAJOR}/@v/
# .else
# WRKSRC=		${WRKDIR}/${GO_MODNAME}@${GO_MODVERSION}
MASTER_SITES+=	${GO_GOPROXY}/${GO_MODNAME:C/([A-Z])/!\1/g:tl}/@v/
# .endif
DISTFILES+=	${GO_MODFILE} ${GO_DISTFILE}
WRKSRC=		${WRKDIR}/${GO_MODNAME}@${GO_MODVERSION}
.        endif

.      endif
EXTRACT_ONLY?=	${DISTFILES:N*.mod\:*:N*.mod:C/:.*//}
DIST_SUBDIR=	go/${PKGORIGIN:S,/,_,g}/${DISTNAME}
FETCH_DEPENDS+=	${GO_CMD}:${GO_PORT}
USES+=		zip
.    else
GO_ENV+=	GO_NO_VENDOR_CHECKS=1
.    endif
.  else
GO_GOPATH=	${WRKDIR}
GO_WRKSRC=	${WRKDIR}/src/${GO_PKGNAME}
GO_ENV+=	GOPATH="${GO_GOPATH}" \
		GOBIN="" \
		GO111MODULE=off
.  endif

BUILD_DEPENDS+=	${GO_CMD}:${GO_PORT}
BINARY_ALIAS+=	go=go${GO_SUFFIX} gofmt=gofmt${GO_SUFFIX}
.  if ${go_ARGS:Mrun}
RUN_DEPENDS+=	${GO_CMD}:${GO_PORT}
.  endif

_USES_POST+=	go
.endif # !defined(_INCLUDE_USES_GO_MK)

.if defined(_POSTMKINCLUDED) && !defined(_INCLUDE_USES_GO_POST_MK)
_INCLUDE_USES_GO_POST_MK=	yes

.  if ${go_ARGS:Mmodules} && defined(GO_MODULE)
_USES_fetch+=	200:go-pre-fetch 800:go-post-fetch
# Check that pkg can be installed or is already available,
# otherwise it will be impossible to install go and fetch dependencies.
go-pre-fetch:
.    if defined(CLEAN_FETCH_ENV) && !exists(${PKG_BIN})
	@${ECHO_MSG} "===> CLEAN_FETCH_ENV is defined, cannot download Go modules (pkg and go are required)"; \
	exit 1
.    endif
# Download all required build dependencies to GOMODCACHE.
go-post-fetch:
	@${ECHO_MSG} "===> Fetching ${GO_MODNAME} dependencies";
	@(cd ${DISTDIR}/${DIST_SUBDIR}; \
		[ -e go.mod ] || ${RLN} ${GO_MODFILE} go.mod; \
		${SETENVI} ${WRK_ENV} \
		${HTTP_PROXY:DHTTP_PROXY=${HTTP_PROXY:Q}} \
		${http_proxy:Dhttp_proxy=${http_proxy:Q}} \
		${HTTPS_PROXY:DHTTPS_PROXY=${HTTPS_PROXY:Q}} \
		${https_proxy:Dhttps_proxy=${https_proxy:Q}} \
		${NO_PROXY:DNO_PROXY=${NO_PROXY:Q}} \
		${no_proxy:Dno_proxy=${no_proxy:Q}} \
		${GO_ENV} GOPROXY=${GO_GOPROXY} ${GO_CMD} mod download -x all)
.  endif

_USES_extract+=	800:go-post-extract
.  if ${go_ARGS:Mmodules} && defined(GO_MODULE)
# Module-aware build mode. Although not strictly necessary (all build dependencies should be
# already in MODCACHE), vendor them so we can patch them if needed.
go-post-extract:
	@${ECHO_MSG} "===> Tidying ${GO_MODNAME} dependencies";
	@(cd ${GO_WRKSRC}; ${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${GO_ENV} GOPROXY=${GO_MODCACHE} ${GO_CMD} mod tidy -e)
	@${ECHO_MSG} "===> Vendoring ${GO_MODNAME} dependencies";
	@(cd ${GO_WRKSRC}; ${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${GO_ENV} GOPROXY=${GO_MODCACHE} ${GO_CMD} mod vendor -e)
.  else
# Legacy (GOPATH) build mode, setup directory structure expected by Go for the main module.
go-post-extract:
	@${MKDIR} ${GO_WRKSRC:H}
	@${LN} -sf ${WRKSRC} ${GO_WRKSRC}
.  endif

.  if !target(do-build) && empty(go_ARGS:Mno_targets)
do-build:
	(cd ${GO_WRKSRC}; \
	for t in ${GO_TARGET}; do \
		out=$$(${BASENAME} $$(${ECHO_CMD} $${t} | \
			${SED} -Ee 's/^[^:]*:([^:]+).*$$/\1/' -e 's/^\.$$/${PORTNAME}/')); \
		pkg=$$(${ECHO_CMD} $${t} | \
			${SED} -Ee 's/^([^:]*).*$$/\1/' -e 's/^${PORTNAME}$$/./'); \
		${ECHO_MSG} "===>  Building $${out} from $${pkg}"; \
		${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${GO_ENV} GOMAXPROCS=${MAKE_JOBS_NUMBER} GOPROXY=off ${GO_CMD} build ${GO_BUILDFLAGS} \
			-o ${GO_WRKDIR_BIN}/$${out} \
			$${pkg}; \
	done)
.  endif

.  if !target(do-install) && empty(go_ARGS:Mno_targets)
do-install:
	for t in ${GO_TARGET}; do \
		dst=$$(${ECHO_CMD} $${t} | \
			${SED} -Ee 's/^[^:]*:([^:]+).*$$/\1/' -e 's/^\.$$/${PORTNAME}/'); \
		src=$$(${BASENAME} $${dst}); \
		case $${dst} in \
			/*) dst=${STAGEDIR}$${dst}; ${MKDIR} $$(${DIRNAME} $${dst}) ;; \
			 *) dst=${STAGEDIR}${PREFIX}/bin/$${src} ;; \
		esac; \
		${ECHO_MSG} "===>  Installing $${src} as $${dst}"; \
		${INSTALL_PROGRAM} ${GO_WRKDIR_BIN}/$${src} $${dst}; \
	done
.  endif

.  if !target(do-test) && empty(go_ARGS:Mno_targets)
do-test:
	(cd ${GO_WRKSRC}; \
	for t in ${GO_TESTTARGET}; do \
		${ECHO_MSG} "===>  Testing $${t}"; \
		${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${GO_ENV} GOPROXY=off ${GO_CMD} test ${GO_TESTFLAGS} $${t}; \
	done)
.  endif

.  if ${go_ARGS:Mmodules} && defined(GO_MODULE)
gomod-clean:
.    if exists(${GO_CMD})
	@${ECHO_MSG} "===>  Cleaning Go module cache"
	@${SETENVI} ${WRK_ENV} ${GO_ENV} ${GO_CMD} clean -modcache
.    else
	@${ECHO_MSG} "===>    Skipping since ${GO_CMD} is not installed"
.    endif

# Hook up to distclean
.    if !target(post-clean) && !make(clean)
post-clean: gomod-clean
	@${RM} -r ${GO_GOPATH}
.    endif
.  endif

# Helper targets for port maintainers

.  if ${go_ARGS:Mmodules} && !defined(GO_MODULE)
_MODULES2TUPLE_CMD=	modules2tuple
gomod-vendor-deps:
	@if ! type ${GO_CMD} > /dev/null 2>&1; then \
		${ECHO_MSG} "===> Please install \"${GO_PORT}\""; exit 1; \
	fi; \
	if ! type ${_MODULES2TUPLE_CMD} > /dev/null 2>&1; then \
		${ECHO_MSG} "===> Please install \"ports-mgmt/modules2tuple\""; exit 1; \
	fi

gomod-vendor: gomod-vendor-deps patch
	@cd ${WRKSRC}; ${SETENVI} ${WRK_ENV} ${GO_ENV} ${GO_CMD} mod vendor; \
	[ -r vendor/modules.txt ] && ${_MODULES2TUPLE_CMD} vendor/modules.txt

gomod-vendor-diff: gomod-vendor-deps patch
	@cd ${WRKSRC}; ${SETENVI} ${WRK_ENV} ${GO_ENV} ${GO_CMD} mod vendor; \
	[ -r vendor/modules.txt ] && ${_MODULES2TUPLE_CMD} vendor/modules.txt | ${SED} 's|GH_TUPLE=|	|; s| \\$$||' | ${GREP} -v '		\\' > ${WRKDIR}/GH_TUPLE-new.txt && \
	echo ${GH_TUPLE} | ${TR} -s " " "\n" | ${SED} "s|^|		|" > ${WRKDIR}/GH_TUPLE-old.txt && \
	${DIFF} ${WRKDIR}/GH_TUPLE-old.txt ${WRKDIR}/GH_TUPLE-new.txt || exit 0
.  endif

.endif # defined(_POSTMKINCLUDED) && !defined(_INCLUDE_USES_GO_POST_MK)
