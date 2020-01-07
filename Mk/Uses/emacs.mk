# $FreeBSD$
#
# Provide support for ports requiring Emacs.  This includes flavors with proper
# dependencies and useful variables.
#
# Feature:	emacs
# Usage:	USES=emacs or USES=emacs:args
# Valid ARGS:	build, run, noflavors
#
# build		Indicates that Emacs is required at build time.
# run		Indicates that Emacs is required at run time.
# noflavors	Prevents flavors.  This is implied when there is no run
#               dependency on Emacs.
#
# If build and run are omitted from the argument list, Emacs will be added to
# BUILD_DEPENDS and RUN_DEPENDS.  EMACS_NO_DEPENDS can be set to prevent both
# dependencies.
#
# Variables, which can be set in make.conf:
# DEFAULT_VERSIONS+=          The default flavor for Emacs ports (ports with
#                             USES=emacs, but not the Emacs ports themselves)
#                             can be added to DEFAULT_VERSIONS.  For example,
#                             DEFAULT_VERSIONS+= emacs=nox
#                             Valid flavors: full canna nox devel_full devel_nox
#                             Flavors specified on the command line take
#                             precedence.
#
# Variables, which can be set by ports:
# EMACS_FLAVORS_EXCLUDE:      Do NOT build these Emacs flavors.
#                             If EMACS_FLAVORS_EXCLUDE is not defined and
#                               - there is a run dependency on Emacs
#                               - the noflavors argument is not specified
#                             then all valid Emacs flavors are assumed.
#
# EMACS_NO_DEPENDS:           Do NOT add build or run dependencies on Emacs.
#                             This will prevent flavors.
#
# Variables, which can be read by ports:
# EMACS_CMD:                  Emacs command with full path (e.g. /usr/local/bin/emacs-26.1)
# EMACS_FLAVOR:               Used for dependencies (e.g. BUILD_DEPENDS= dash.el${EMACS_PKGNAMESUFFIX}>0:devel/dash@${EMACS_FLAVOR})
# EMACS_LIBDIR:               Emacs Library directory without ${PREFIX} (e.g. share/emacs)
# EMACS_LIBDIR_WITH_VER:      Library directory without ${PREFIX} including version (e.g. share/emacs/26.1)
# EMACS_MAJOR_VER:            Emacs major version (e.g. 26)
# EMACS_PKGNAMESUFFIX:        PKGNAMESUFFIX to distinguish Emacs flavors
# EMACS_SITE_LISPDIR:         Emacs site-lisp directory without ${PREFIX} (e.g. share/emacs/site-lisp)
# EMACS_VER:                  Emacs version (e.g. 26.1)
# EMACS_VERSION_SITE_LISPDIR: Include version (e.g. share/emacs/26.1/site-lisp)
#-------------------------------------------------------------------------------
#
# MAINTAINER:	emacs@FreeBSD.org

.if !defined(_INCLUDE_USES_EMACS_MK)
_INCLUDE_USES_EMACS_MK=	yes

# Make sure that no dependency or some other environment variable
# pollutes the build/run dependency detection
.undef _EMACS_BUILD_DEP
.undef _EMACS_RUN_DEP
.undef _EMACS_NOFLAVORS
_EMACS_ARGS=		${emacs_ARGS:S/,/ /g}
.if ${_EMACS_ARGS:Mbuild}
_EMACS_BUILD_DEP=	yes
_EMACS_ARGS:=		${_EMACS_ARGS:Nbuild}
.endif
.if ${_EMACS_ARGS:Mrun}
_EMACS_RUN_DEP=		yes
_EMACS_ARGS:=		${_EMACS_ARGS:Nrun}
.endif
.if ${_EMACS_ARGS:Mnoflavors}
_EMACS_NOFLAVORS=	yes
_EMACS_ARGS:=		${_EMACS_ARGS:Nnoflavors}
.endif

# If the port does not specify a build or run dependency, and does not define
# EMACS_NO_DEPENDS, assume both dependencies are required.
.if !defined(_EMACS_BUILD_DEP) && !defined(_EMACS_RUN_DEP) && \
	!defined(EMACS_NO_DEPENDS)
_EMACS_BUILD_DEP=	yes
_EMACS_RUN_DEP=		yes
.endif

# Only set FLAVORS when...
.if defined(_EMACS_RUN_DEP) && !defined(_EMACS_NOFLAVORS)
FLAVORS=	full canna nox devel_full devel_nox
.for flavor in ${EMACS_FLAVORS_EXCLUDE}
FLAVORS:=	${FLAVORS:N${flavor}}
.endfor
.endif

# Only set FLAVOR when...
.if defined(_EMACS_RUN_DEP) && !defined(_EMACS_NOFLAVORS) && empty(FLAVOR)
.if defined(EMACS_DEFAULT)
FLAVOR=	${EMACS_DEFAULT}
.else
FLAVOR=	${FLAVORS:[1]}
.endif # defined(EMACS_DEFAULT)
.endif # !defined(_EMACS_NOFLAVORS) && defined(_EMACS_RUN_DEP) && empty(FLAVOR)

.if !empty(FLAVOR)
EMACS_FLAVOR=	${FLAVOR}
.else
EMACS_FLAVOR=	full
.endif

.if ${FLAVOR:Mdevel*}
EMACS_VER=			28.0.50
EMACS_PORTDIR=		editors/emacs-devel
.else
EMACS_VER=		26.3
EMACS_PORTDIR=		editors/emacs
.endif

EMACS_MAJOR_VER=	${EMACS_VER:C/\..*//}
EMACS_LIBDIR=		share/emacs
EMACS_LIBDIR_WITH_VER=	share/emacs/${EMACS_VER}
EMACS_PORT_NAME=	emacs${EMACS_MAJOR_VER}

.if ${FLAVOR:M*nox}
EMACS_PKGNAMESUFFIX=		-${EMACS_PORT_NAME}_nox
.elif ${FLAVOR:Mcanna}
EMACS_PKGNAMESUFFIX=		-${EMACS_PORT_NAME}_canna
.else
EMACS_PKGNAMESUFFIX=		-${EMACS_PORT_NAME}
.endif

EMACS_CMD=	${PREFIX}/bin/emacs-${EMACS_VER}
EMACS_SITE_LISPDIR=	${EMACS_LIBDIR}/site-lisp
EMACS_VERSION_SITE_LISPDIR=	${EMACS_LIBDIR_WITH_VER}/site-lisp

.if defined(_EMACS_BUILD_DEP)
BUILD_DEPENDS+=		${EMACS_CMD}:${EMACS_PORTDIR}@${EMACS_FLAVOR:C/devel_//}
.endif
.if defined(_EMACS_RUN_DEP)
RUN_DEPENDS+=	${EMACS_CMD}:${EMACS_PORTDIR}@${EMACS_FLAVOR:C/devel_//}
.endif

MAKE_ARGS+=	EMACS=${EMACS_CMD}
SCRIPTS_ENV+=	EMACS_LIBDIR=${EMACS_LIBDIR} \
		EMACS_VER=${EMACS_VER} \
		EMACS_LIBDIR_WITH_VER=${EMACS_LIBDIR_WITH_VER} \
		EMACS_SITE_LISPDIR=${EMACS_SITE_LISPDIR} \
		EMACS_VERSION_SITE_LISPDIR=${EMACS_VERSION_SITE_LISPDIR}

PLIST_SUB+=	EMACS_LIBDIR=${EMACS_LIBDIR} \
		EMACS_VER=${EMACS_VER} \
		EMACS_LIBDIR_WITH_VER=${EMACS_LIBDIR_WITH_VER} \
		EMACS_SITE_LISPDIR=${EMACS_SITE_LISPDIR} \
		EMACS_VERSION_SITE_LISPDIR=${EMACS_VERSION_SITE_LISPDIR}

.endif # _INCLUDE_USES_EMACS_MK
