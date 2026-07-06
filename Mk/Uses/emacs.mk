# Provide support for ports requiring Emacs.
#
# Feature:	emacs
# Usage:	USES=emacs or USES=emacs:args
# Valid ARGS:	build test
#
# build		Indicates that Emacs is required at build time.
# test		Indicates that Emacs is required at test time.
#
# If build is omitted from the argument list, Emacs will not be added to
# BUILD_DEPENDS.
# If test is omitted from the argument list, Emacs will not be added to
# TEST_DEPENDS.
#
# Variables, which can be set in make.conf:
# DEFAULT_VERSIONS+=emacs=    Select the Emacs port and flavor used for
#                             USES=emacs:build and USES=emacs:test.
#                             Valid values: full canna nox wayland
#                                           devel_full devel_nox
#                             Defaults to nox when not specified.
#                             Values prefixed with devel_ select
#                             editors/emacs-devel; others select
#                             editors/emacs.
#
# Variables, which can be read by ports:
# EMACS_CMD:                  Emacs command with full path (e.g. /usr/local/bin/emacs-30.2)
# EMACS_MAJOR_VER:            Emacs major version (e.g. 30)
# EMACS_LIBDIR:               Emacs Library directory without ${PREFIX} (e.g. share/emacs)
# EMACS_SITE_LISPDIR:         Emacs site-lisp directory without ${PREFIX} (e.g. share/emacs/site-lisp)
#
# Note: EMACS_CMD and EMACS_MAJOR_VER are only set if one or both of the build
# or test argument are supplied.
#
# Note: No Emacs runtime dependency is declared here.  USES=emacs ports now
# install only .el source files, avoiding the combinatorial explosion of
# flavor-specific packages.  Native compilation is handled at runtime by the
# site-wide configuration shipped with editors/emacs and editors/emacs-devel.
#-------------------------------------------------------------------------------
#
# MAINTAINER:	emacs@FreeBSD.org

.if !defined(_INCLUDE_USES_EMACS_MK)
_INCLUDE_USES_EMACS_MK=	yes

# Make sure that no dependency or some other environment variable
# pollutes the build/run dependency detection
.undef _EMACS_BUILD_DEP _EMACS_TEST_DEP
_EMACS_ARGS=		${emacs_ARGS:S/,/ /g}
.  if ${_EMACS_ARGS:Mbuild}
_EMACS_BUILD_DEP=	yes
_EMACS_ARGS:=		${_EMACS_ARGS:Nbuild}
.  endif
.  if ${_EMACS_ARGS:Mtest}
_EMACS_TEST_DEP=	yes
_EMACS_ARGS:=		${_EMACS_ARGS:Ntest}
.  endif

EMACS_LIBDIR=		share/emacs
EMACS_SITE_LISPDIR=	${EMACS_LIBDIR}/site-lisp

.  if defined(_EMACS_BUILD_DEP) || defined(_EMACS_TEST_DEP)
.    if defined(EMACS_DEFAULT) && ${EMACS_DEFAULT:Mdevel*}
_EMACS_VER=		32.0.50
_EMACS_PORTDIR=		editors/emacs-devel
_EMACS_FLAVOR=		${EMACS_DEFAULT:C/devel_//}
.    else
_EMACS_VER=		30.2
_EMACS_PORTDIR=		editors/emacs
_EMACS_FLAVOR=		${EMACS_DEFAULT:Unox}
.    endif
EMACS_CMD=		${PREFIX}/bin/emacs-${_EMACS_VER}
EMACS_MAJOR_VER=	${_EMACS_VER:C/\..*//}
.  endif

.  if defined(_EMACS_BUILD_DEP)
MAKE_ARGS+=		EMACS=${EMACS_CMD}
BUILD_DEPENDS+=		${EMACS_CMD}:${_EMACS_PORTDIR}@${_EMACS_FLAVOR}
.  endif
.  if defined(_EMACS_TEST_DEP)
TEST_DEPENDS+=		${EMACS_CMD}:${_EMACS_PORTDIR}@${_EMACS_FLAVOR}
.  endif

SCRIPTS_ENV+=	EMACS_LIBDIR=${EMACS_LIBDIR} \
		EMACS_SITE_LISPDIR=${EMACS_SITE_LISPDIR}

PLIST_SUB+=	EMACS_LIBDIR=${EMACS_LIBDIR} \
		EMACS_SITE_LISPDIR=${EMACS_SITE_LISPDIR}

.endif # _INCLUDE_USES_EMACS_MK
