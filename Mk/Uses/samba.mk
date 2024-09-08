# Handle dependency on samba
#
# Feature:	samba
# Usage:	USES=samba or USES=samba:ARGS
# Valid ARGS:	build, env, lib, run
#		default is build,run (implicit)
#
# MAINTAINER: samba@FreeBSD.org

.if !defined(_INCLUDE_USES_SAMBA_MK)
_INCLUDE_USES_SAMBA_MK=   yes

.  if !${samba_ARGS}
samba_ARGS=	build run
.  endif

.  if ${samba_ARGS:Nbuild:Nenv:Nlib:Nrun}
IGNORE=		USES=samba has invalid arguments: ${samba_ARGS:Nbuild:Nenv:Nlib:Nrun}
.  endif

.  if ${SAMBA_DEFAULT} != 4.16 && ${SAMBA_DEFAULT} != 4.19
IGNORE=		Invalid version of samba: ${SAMBA_DEFAULT}
.  endif

SAMBA_SUFFIX=	${SAMBA_DEFAULT:S/.//}

SAMBA_PORT_416=		net/samba416
SAMBA_LDB_PORT_416=	databases/ldb25
SAMBA_PORT_419=		net/samba419
SAMBA_LDB_PORT_419=	databases/ldb28

SAMBA_PORT=		${SAMBA_PORT_${SAMBA_SUFFIX}}
SAMBA_INCLUDEDIR=	${LOCALBASE}/include/samba4
SAMBA_LIBDIR=		${LOCALBASE}/lib/samba4
SAMBA_LDB_PORT=		${SAMBA_LDB_PORT_${SAMBA_SUFFIX}}

.  if ${samba_ARGS:Mbuild}
BUILD_DEPENDS+=	smbd:${SAMBA_PORT}
.  endif
.  if ${samba_ARGS:Mlib}
LIB_DEPENDS+=	libsmbclient.so:${SAMBA_PORT}
.  endif
.  if ${samba_ARGS:Mrun}
RUN_DEPENDS+=	smbd:${SAMBA_PORT}
.  endif

# Legacy variables. Removing those requires a tree-wide update
# and a note in the CHANGES file
SAMBAPORT=		${SAMBA_PORT}
SAMBAINCLUDES=		${SAMBA_INCLUDEDIR}
SAMBALIBS=		${SAMBA_LIBDIR}
.endif
