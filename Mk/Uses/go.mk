# $FreeBSD$
#
# This file contains logic to ease porting of Go binaries using the
# `go` command.
#
# Feature:	go
# Usage:	USES=go
# Valid ARGS:	(none), modules
#
# (none)	Setup GOPATH and build in GOPATH mode.
# modules	If the upstream uses Go modules, this can be set to build
#		in modules-aware mode.
#
# You can set the following variables to control the process.
#
# GO_PKGNAME
#	The name of the package. When building in GOPATH mode, this is
#	the directory that will be created in GOPATH/src and seen by the
#	`go` command. When building in modules-aware mode, no directories
#	will be created and GO_PKGNAME value will be only used as a default
#	for GO_TARGET. If not set explicitly and GH_SUBDIR is present,
#	GO_PKGNAME will be inferred from GH_SUBDIR.
#
# GO_TARGET
#	The names of the package(s) to build. If not set explicitly,
#	defaults to GO_PKGNAME.
#
# CGO_CFLAGS
#	Addional CFLAGS variables to be passed to the C compiler by the `go`
#	command
#
# CGO_LDFLAGS
#	Addional LDFLAGS variables to be passed to the C compiler by the `go`
#	command
#
# GO_BUILDFLAGS
#	Additional build arguments to be passed to the `go install` command
#
# MAINTAINER: jlaffaye@FreeBSD.org

.if !defined(_INCLUDE_USES_GO_MK)
_INCLUDE_USES_GO_MK=	yes

.if !empty(go_ARGS) && ${go_ARGS:Nmodules}
IGNORE=	USES=go only accepts no arguments or 'modules'
.endif

# Settable variables
.if empty(GO_PKGNAME)
.  if !empty(GH_SUBDIR)
GO_PKGNAME=	${GH_SUBDIR:S|^src/||}
.  else
GO_PKGNAME=	${PORTNAME}
.  endif
.endif
GO_TARGET?=	${GO_PKGNAME}
GO_BUILDFLAGS+=	-v -buildmode=exe
CGO_CFLAGS+=	-I${LOCALBASE}/include
CGO_LDFLAGS+=	-L${LOCALBASE}/lib

# Read-only variables
GO_CMD=		${LOCALBASE}/bin/go
GO_WRKDIR_BIN=	${WRKDIR}/bin

GO_ENV+=	CGO_CFLAGS="${CGO_CFLAGS}" \
		CGO_LDFLAGS="${CGO_LDFLAGS}"

.if ${go_ARGS:Mmodules}
GO_BUILDFLAGS+=	-mod=vendor
GO_WRKSRC=	${WRKSRC}
GO_ENV+=	GOPATH="" \
		GOBIN="${GO_WRKDIR_BIN}"
.else
GO_WRKDIR_SRC=	${WRKDIR}/src
GO_WRKSRC=	${GO_WRKDIR_SRC}/${GO_PKGNAME}
GO_ENV+=	GOPATH="${WRKDIR}" \
		GOBIN=""
.endif

BUILD_DEPENDS+=	${GO_CMD}:lang/go
PLIST_SUB+=	GO_PKGNAME=${GO_PKGNAME}

_USES_POST+=	go
.endif # !defined(_INCLUDE_USES_GO_MK)

.if defined(_POSTMKINCLUDED) && !defined(_INCLUDE_USES_GO_POST_MK)
_INCLUDE_USES_GO_POST_MK=	yes

.if !target(post-extract) && empty(go_ARGS)
post-extract:
	@${MKDIR} ${GO_WRKSRC:H}
	@${LN} -sf ${WRKSRC} ${GO_WRKSRC}
.endif

.if !target(do-build)
do-build:
	(cd ${GO_WRKSRC}; \
		${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} install ${GO_BUILDFLAGS} ${GO_TARGET})
.endif

.if !target(do-install)
do-install:
.for _TARGET in ${GO_TARGET}
	${INSTALL_PROGRAM} ${GO_WRKDIR_BIN}/${_TARGET:T} ${STAGEDIR}${PREFIX}/bin
.endfor
.endif

.endif # defined(_POSTMKINCLUDED) && !defined(_INCLUDE_USES_GO_POST_MK)
