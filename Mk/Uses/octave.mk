# Support for octave based ports
#
# Feature: 		octave
# Usage:		USES=octave
# Valid ARGS:	(none), env
# 	- env : Loads only one environmental variable OCTAVE_VERSION
# MAINTAINER:	stephen@FreeBSD.org
#
# Common code to install octave-forge packages.
# It is, in effect, a wrapper using the package handling already built
# into math/octave.

.if !defined(_INCLUDE_USES_OCTAVE_MK)
_INCLUDE_USES_OCTAVE_MK=    yes

_valid_octave_ARGS=		env

# Sanity check
.  for arg in ${octave_ARGS}
.    if empty(_valid_octave_ARGS:M${arg})
IGNORE=	Incorrect 'USES+= octave:${octave_ARGS}' usage: argument [${arg}] is not recognized
.    endif
.  endfor

OCTAVE_VERSION=	9.2.0

.  if empty(octave_ARGS:Menv)
BUILD_DEPENDS+=	octave:math/octave
RUN_DEPENDS+=	octave:math/octave \
		${LOCALBASE}/libexec/octave/load-octave-pkg:math/octave-forge-base
LIB_DEPENDS+=	libpcre.so:devel/pcre

.    if ! ${USES:Mcompiler}
_USES_POST+=	compiler:c++14-lang
.    endif

.    if ! ${USES:Mfortran}
_USES_POST+=	fortran
.    endif

.    if ! ${USES:Mgmake}
_USES_POST+=	gmake
.    endif

CXXFLAGS+=	-I${LOCALBASE}/include/octave-${OCTAVE_VERSION}
CFLAGS+=	-I${LOCALBASE}/include/octave-${OCTAVE_VERSION}
CPPFLAGS+=	-I${LOCALBASE}/include/octave-${OCTAVE_VERSION}

DIST_SUBDIR?=	octave-forge
OCTAVE_PKGNAME=	${PORTNAME:S/octave-forge-//}
OCTAVE_DISTNAME=	${OCTAVE_PKGNAME}-${DISTVERSION}
OCTAVE_TARBALLS_DIR=	${LOCALBASE}/share/octave/tarballs
OCTAVE_INSTALL_TARBALLS_DIR=	${STAGEDIR}${PREFIX}/share/octave/tarballs
OCTAVE_SRC?=	${DISTNAME}
WRKSRC?=	${WRKDIR}/${OCTAVE_SRC}/src

MAKE_ENV+=	PACKAGE=${OCTAVE_DISTNAME}.tar.gz
MAKE_ARGS+=	CC="${CC}" CXX="${CXX}" LD_CXX="${CXX}" DL_LD="${CXX}" MKOCTFILE="${LOCALBASE}/bin/mkoctfile" OCTAVE_VERSION=-${OCTAVE_VERSION}

LOAD_OCTAVE_PKG_CMD=	${LOCALBASE}/libexec/octave/load-octave-pkg

.    if !target(pre-install)
pre-install: octave-pre-install
.    endif #	!target(pre-install)

.    if !target(do-install)
do-install: octave-do-install
.    endif # !target(do-install)

.    if !target(post-install)
post-install: octave-post-install
.    endif # !target(post-install)

octave-pre-install:
	${RM} ${WRKSRC}/Makefile ${WRKSRC}/configure
	cd ${WRKDIR} && ${TAR} cfz ${OCTAVE_DISTNAME}.tar.gz ${OCTAVE_SRC}

octave-do-install:
	${MKDIR} ${OCTAVE_INSTALL_TARBALLS_DIR}
	${INSTALL_DATA} ${WRKDIR}/${OCTAVE_DISTNAME}.tar.gz ${OCTAVE_INSTALL_TARBALLS_DIR}/.
	${LN} -s -f ${OCTAVE_DISTNAME}.tar.gz ${OCTAVE_INSTALL_TARBALLS_DIR}/${OCTAVE_PKGNAME}.tar.gz

octave-post-install:
	@${ECHO_CMD} "share/octave/tarballs/${OCTAVE_DISTNAME}.tar.gz" >> ${TMPPLIST}
	@${ECHO_CMD} "share/octave/tarballs/${OCTAVE_PKGNAME}.tar.gz" >> ${TMPPLIST}
	@${ECHO_CMD} "@postunexec if [ -x ${LOAD_OCTAVE_PKG_CMD} ]; then ${LOAD_OCTAVE_PKG_CMD}; fi" >> ${TMPPLIST}
	@${ECHO_CMD} "@postexec if [ -x ${LOAD_OCTAVE_PKG_CMD} ]; then ${LOAD_OCTAVE_PKG_CMD}; fi" >> ${TMPPLIST}
.  endif # empty(octave_ARGS:Menv)

.endif # !defined(_INCLUDE_USES_OCTAVE_MK)
