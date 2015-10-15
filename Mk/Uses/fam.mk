# $FreeBSD$
#
# MAINTAINER: portmgr@FreeBSD.org
#
# Feature:	fam
# Usage:	USES=fam or USES=fam:ARG
# Valid ARG:	gamin, fam
#
# User-specified File Alteration Monitor wish:
# Usage:	WITH_FAM_SYSTEM=ARG
# Valid ARG:	gamin (default), fam
#
# Handle dependency on File Alteration Monitor

.if !defined(_INCLUDE_USES_FAM_MK)
_INCLUDE_USES_FAM_MK=	yes

_fam_DEPENDS=	libfam.so.0:${PORTSDIR}/devel/fam
_gamin_DEPENDS=	libfam.so.0:${PORTSDIR}/devel/gamin

_FAM_SYSTEMS=	fam gamin
_DEFAULT_FAM=	gamin

.if exists(${LOCALBASE}/libexec/gam_server)
_HAVE_FAM=	gamin
.elif exists(${LOCALBASE}/bin/fam)
_HAVE_FAM=	fam
.endif

# Sanity checks
.if defined(WITH_FAM_SYSTEM) && defined(_HAVE_FAM) && ${_HAVE_FAM} != ${WITH_FAM_SYSTEM}
IGNORE=	FAM mismatch: ${_HAVE_FAM} is installed, but ${WITH_FAM_SYSTEM} desired
.endif

.if !empty(fam_ARGS)
.for _fam_ARGS in ${fam_ARGS}
.  if ! ${_FAM_SYSTEMS:M${_fam_ARGS}}
IGNORE=	Incorrect 'USES+= fam:${fam_ARGS}' usage: argument [${_fam_ARGS}] is not recognized
.  endif
.endfor
.  if defined(_HAVE_FAM) && ${_HAVE_FAM} != ${fam_ARGS}
IGNORE=	FAM mismatch: port wants to use ${fam_ARGS} while you have ${_HAVE_FAM}
.  endif
.  if defined(WITH_FAM_SYSTEM) && ${WITH_FAM_SYSTEM} != ${fam_ARGS}
IGNORE=	FAM mismatch: port wants to use ${fam_ARGS} while you wish to use ${WITH_FAM_SYSTEM}
.  endif
.endif

# Proceed
.if !empty(fam_ARGS)
_USE_FAM=	${fam_ARGS}
.elif defined(_HAVE_FAM)
_USE_FAM=	${_HAVE_FAM}
.elif defined(WITH_FAM_SYSTEM)
_USE_FAM=	${WITH_FAM_SYSTEM}
.else
_USE_FAM=	${_DEFAULT_FAM}
.endif

LIB_DEPENDS+=	${_${_USE_FAM}_DEPENDS}

.endif
