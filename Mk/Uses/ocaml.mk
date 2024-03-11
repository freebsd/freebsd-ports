# Provide support to use the Dune package builder for OCaml
#
# Feature:		ocaml
# Usage:		USES=ocaml:dune
#			USE_OCAML=yes
#
# Variables that may be set by the port:
#
#  OCAML_PACKAGES	List of packages to build and install, defaults to PORTNAME
#
#  USE_OCAML_LDCONFIG	Dune may install stublibs in site-lib package directory(ies)
#  OCAML_LDLIBS		or in a single directory below DUNE_LIBDIR.
#
# Appends to: BUILD_DEPENDS, MAKE_ENV
#
# MAINTAINER: freebsd@dev.thsi.be

.if !defined(_INCLUDE_USES_OCAML_MK)
_INCLUDE_USES_OCAML_MK=	yes

.  if empty(ocaml_ARGS:Mdune)
IGNORE=	Incorrect 'USES+= ocaml:${ocaml_ARGS}' ocaml requires a single 'dune' argument (for now)
.  endif

.  if !defined(OCAML_include)
.error USES=dune only works with USE_OCAML=yes
.  endif

#
# Dune builder port
#
DUNE_PORT?=		devel/ocaml-dune
DUNE_DEPEND?=		ocaml-dune>=3.7.1_2:devel/ocaml-dune

BUILD_DEPENDS+=		${DUNE_DEPEND}

DUNE_ARGS=		--display=short --always-show-command-line \
			--no-config -j ${MAKE_JOBS_NUMBER} --profile release \
			--root=${DUNE_ROOT} --build-dir=${DUNE_BUILD_DIR} \
			--promote-install-files --ignore-promoted-rules \
			--default-target @install --require-dune-project-file \
			--only-packages=${OCAML_PACKAGES:ts,}
DUNE_BUILD_ARGS?=
DUNE_BUILD_DIR?=	_build
DUNE_CMD?=		dune
DUNE_INSTALL_ARGS?=	--prefix=${PREFIX} \
			--libdir=${PREFIX}/${OCAML_SITELIBDIR} \
			--docdir=${OCAML_DOCSDIR} --destdir=${STAGEDIR}
DUNE_INSTALL_TARGETS?=
DUNE_LIBDIR?=		${OCAML_SITELIBDIR}
OCAML_PACKAGES?=		${PORTNAME}
DUNE_ROOT?=		.

.  if USE_OCAML_LDCONFIG
.    if !empty(OCAML_LDLIBS)
.      if ${OCAML_LDLIBS:[#]} > 1
.        for _l in ${OCAML_LDLIBS}
.          if empty(OCAML_PACKAGES:M${_l:T}) || "${_l:H}" != "${DUNE_LIBDIR}"
IGNORE+= OCAML_LDLIBS member ${_l} should match a OCAML_PACKAGES
.          endif
.        endfor
DUNE_ENV+=	DUNE_FREEBSD_STUBLIBS_IN_PACKAGE=
.      else
DUNE_ENV+=	DUNE_FREEBSD_STUBLIBS_RELATIVE_TO_LIBDIR=${OCAML_LDLIBS:S/${DUNE_LIBDIR}\///}
.      endif
.    else
DUNE_ENV+=	DUNE_FREEBSD_STUBLIBS_RELATIVE_TO_LIBDIR=${OCAML_PACKAGES:[1]}
.    endif
.  endif

# left empty for default @install target
ALL_TARGET?=	
MAKE_ENV+=	${DUNE_ENV}

DO_MAKE_BUILD?=	${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${DUNE_CMD} build ${DUNE_ARGS} ${DUNE_BUILD_ARGS}

.  if !target(do-install) && !defined(NO_INSTALL)
do-install:
	@(cd ${INSTALL_WRKSRC} && ${SETENV} ${WRK_ENV} ${MAKE_ENV} ${FAKEROOT} ${DUNE_CMD} install ${DUNE_ARGS} ${DUNE_INSTALL_ARGS} ${DUNE_INSTALL_TARGETS})
.  endif

.endif
