# Handle dependency on samba
#
# Feature:	samba
# Usage:	USES=samba or USES=samba:ARGS
# Valid ARGS:	build, env, lib, self, run
#		default is build,run (implicit)
#
# MAINTAINER: samba@FreeBSD.org

.if !defined(_INCLUDE_USES_SAMBA_MK)
_INCLUDE_USES_SAMBA_MK=   yes

.  if !${samba_ARGS}
samba_ARGS=	build run
.  endif

.  if ${samba_ARGS:Nbuild:Nenv:Nlib:Nself:Nrun}
IGNORE=		USES=samba has invalid arguments: ${samba_ARGS:Nbuild:Nenv:Nlib:Nself:Nrun}
.  endif

.  if ${SAMBA_DEFAULT} != 4.16 && ${SAMBA_DEFAULT} != 4.19 && ${SAMBA_DEFAULT} != 4.20 && ${SAMBA_DEFAULT} != 4.22
IGNORE=		Invalid version of samba: ${SAMBA_DEFAULT}
.  endif

# E.g., "422".
SAMBA_SUFFIX=	${SAMBA_DEFAULT:S/.//}
# _SAMBA_BASE is the directory where Samba is installed. For Samba
# consumers that is LOCALBASE, while it is PREFIX for Samba itself.
_SAMBA_BASE=	${LOCALBASE}
.  if ${samba_ARGS:Mself}
_SAMBA_BASE=	${PREFIX}
.  endif

### Directories
SAMBA_INCLUDEDIR=	${_SAMBA_BASE}/include/samba4
SAMBA_LIBDIR=		${_SAMBA_BASE}/lib/samba4
SAMBA_MODULESDIR=	${SAMBA_LIBDIR}/modules
SAMBA_IDMAP_MODULESDIR=	${SAMBA_MODULESDIR}/idmap
SAMBA_LDB_MODULESDIR=	${_SAMBA_BASE}/lib/shared-modules/ldb

### Port names
SAMBA_PORT_416=		net/samba416
SAMBA_LDB_PORT_416=	databases/ldb25
SAMBA_TALLOC_PORT_416=	devel/talloc
SAMBA_TDB_PORT_416=	databases/tdb
SAMBA_TEVENT_PORT_416=	devel/tevent
SAMBA_PORT_419=		net/samba419
SAMBA_LDB_PORT_419=	databases/ldb28
SAMBA_TALLOC_PORT_419=	devel/talloc
SAMBA_TDB_PORT_419=	databases/tdb
SAMBA_TEVENT_PORT_419=	devel/tevent
SAMBA_PORT_420=		net/samba420
SAMBA_LDB_PORT_420=	databases/ldb29
SAMBA_TALLOC_PORT_420=	devel/talloc242
SAMBA_TDB_PORT_420=	databases/tdb1410
SAMBA_TEVENT_PORT_420=	devel/tevent016
SAMBA_PORT_422=		net/samba422
SAMBA_TALLOC_PORT_422=	devel/talloc243
SAMBA_TDB_PORT_422=	databases/tdb1413
SAMBA_TEVENT_PORT_422=	devel/tevent017

SAMBA_PORT=		${SAMBA_PORT_${SAMBA_SUFFIX}}
# Only define SAMBA_LDB_PORT if SAMBA_LDB_PORT_${SAMBA_SUFFIX} is set. Samba
# requires ldb to be bundled since version 4.22, so it makes no sense to set
# SAMBA_LDB_PORT in that case. By not setting SAMBA_LDB_PORT, we allow ports to
# detect the lack of a separate ldb port more easily.
.  if !empty(SAMBA_LDB_PORT_${SAMBA_SUFFIX})
SAMBA_LDB_PORT=		${SAMBA_LDB_PORT_${SAMBA_SUFFIX}}
.  endif
SAMBA_TALLOC_PORT=	${SAMBA_TALLOC_PORT_${SAMBA_SUFFIX}}
SAMBA_TDB_PORT=		${SAMBA_TDB_PORT_${SAMBA_SUFFIX}}
SAMBA_TEVENT_PORT=	${SAMBA_TEVENT_PORT_${SAMBA_SUFFIX}}

### Dependencies
.  if ${samba_ARGS:Mbuild}
BUILD_DEPENDS+=	smbd:${SAMBA_PORT}
.  endif
.  if ${samba_ARGS:Mlib}
LIB_DEPENDS+=	libsmbclient.so:${SAMBA_PORT}
.  endif
.  if ${samba_ARGS:Mrun}
RUN_DEPENDS+=	smbd:${SAMBA_PORT}
.  endif
.endif
