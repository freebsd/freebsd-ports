# Provide support for OCaml
# Feature:	ocaml
# Usage:	USES=ocaml or USES=ocaml:args
#
# Valid ARGS:	build, camlp4, dune, findlib, findplist, ldconfig, tk, tkbuild, tkrun, wash
#		If empty, defaults to build and run
#
# build		-	Add ocamlc to BUILD|EXTRACT|PATCH_DEPENDS
#
# camlp4	-	Use camlp4 to build
#
# dune		-	Use dune as a build system
#
# findlib	-	Set if port uses ocamlfind to install packages.
# 			Package direcories will be automatically deleted
#
# findplist	-	Add contents of findlib target directories automatically
#
# ldconfig	-	Set if your port installs shared libraries into ocaml
# 			site-lib dir. OCaml ld.conf file will be automatically
# 			processed. When dune is used Dune may install stublibs in
# 			site-lib package directory(ies) or in a single directory
# 			below DUNE_LIBDIR.
#
# run		-	Add ocamlc to RUN_DEPENDS
#
# tk		-	Set if port needs ocaml-labltk which implies tkbuild and
#			tkrun
#
# tkbuild	-	Add labltk to BUILD|EXTRACT|PATCH_DEPENDS
#
# tkrun		-	Add labltk to RUN_DEPENDS
#
# wash		- 	Set if your port wants to automatically
#			purge shared Ocaml dirs on uninstall. It's
#			useful when installing to non-standard PREFIX
#
# Variables that may be set by the port:
#
# OCAML_PKGDIRS		-	Directories under site-lib to be processed
#				if USES=ocaml:findlib specified.
#				Default: ${PORTNAME}
#
# OCAML_LDLIBS		-	Directories under PREFIX to be automatically
#				added/removed from ld.conf
#				Default: ${OCAML_SITELIBDIR}/${PORTNAME}
#
# OCAML_PACKAGES	- 	List of packages to build and install, defaults to ${PORTNAME}
#
# MAINTAINER: freebsd@dev.thsi.be

.if !defined(_INCLUDE_USES_OCAML_MK)
_INCLUDE_USES_OCAML_MK=	yes

_OCAML_VALID_ARGS=	build camlp4 dune findlib findplist ldconfig tk tkbuild tkrun wash
_OCAML_UNKNOWN_ARGS=
.  for arg in ${ocaml_ARGS}
.    if empty(_OCAML_VALID_ARGS:M${arg})
_OCAML_UNKNOWN_ARGS+=	${arg}
.    endif
.  endfor
.  if !empty(_OCAML_UNKNOWN_ARGS)
IGNORE=	has unknown USES=ocaml arguments: ${_OCAML_UNKNOWN_ARGS}
.  endif
.  if ${ocaml_ARGS:Mfindplist} && ${ocaml_ARGS:Mfindlib}
DEV_WARNING+=   "USES=ocaml:findlib is included in USES=ocaml:findplist, so it is not needed"
.  endif
.  if empty(ocaml_ARGS)
ocaml_ARGS=	build,run
.  endif

.  if !empty(ocaml_ARGS)
.undef _USE_OCAML_BUILD
.undef _USE_OCAML_CAMLP4
.undef _USE_OCAML_DUNE
.undef _USE_OCAML_FINDLIB
.undef _USE_OCAML_FINDPLIST
.undef _USE_OCAML_LDCONFIG
.undef _USE_OCAML_RUN
.undef _USE_OCAML_TKBUILD
.undef _USE_OCAML_TKRUN
.undef _USE_OCAML_WASH
_OCAML_ARGS=		${ocaml_ARGS:S/,/ /g}
.    if ${_OCAML_ARGS:Mcamlp4}
_USE_OCAML_CAMLP4=	yes
_OCAML_ARGS:=	${_OCAML_ARGS:Ncamlp4}
.    endif
.    if ${_OCAML_ARGS:Mdune}
_USE_OCAML_DUNE=	yes
_OCAML_ARGS:=	${_OCAML_ARGS:Ndune}
.    endif
.    if ${_OCAML_ARGS:Mfindplist}
_USE_OCAML_FINDPLIST=	yes
_OCAML_ARGS:=	${_OCAML_ARGS:Nfindplist}
_OCAML_ARGS+=		findlib
.    endif
.    if ${_OCAML_ARGS:Mfindlib}
_USE_OCAML_FINDLIB=	yes
_OCAML_ARGS:=	${_OCAML_ARGS:Nfindlib}
.    endif
.    if ${_OCAML_ARGS:Mldconfig}
_USE_OCAML_LDCONFIG=	yes
_OCAML_ARGS:=	${_OCAML_ARGS:Nldconfig}
.    endif
.    if ${_OCAML_ARGS:Mtk}
_OCAML_ARGS+=		tkbuild
_OCAML_ARGS+=		tkrun
.    endif
.    if ${_OCAML_ARGS:Mtkbuild}
.      if defined(NO_BUILD)
IGNORE=		Makefile error: NO_BUILD and USES=ocaml:tkbuild cannot be set at the same time
.      else
_USE_OCAML_TKBUILD=	yes
_OCAML_ARGS:=	${_OCAML_ARGS:Ntkbuild}
.      endif
.    endif
.    if ${_OCAML_ARGS:Mtkrun}
_USE_OCAML_TKRUN=	yes
_OCAML_ARGS:=	${_OCAML_ARGS:Ntkrun}
.    endif
.    if ${_OCAML_ARGS:Mwash}
_USE_OCAML_WASH=	yes
_OCAML_ARGS:=	${_OCAML_ARGS:Nwash}
.    endif
.    if empty(_OCAML_ARGS)
_OCAML_ARGS+=		build
_OCAML_ARGS+=		run
.    endif
.    if ${_OCAML_ARGS:Mbuild}
.      if defined(NO_BUILD)
IGNORE=		Makefile error: NO_BUILD and USES=ocaml:build cannot be set at the same time
.      else
_USE_OCAML_BUILD=	yes
.      endif
.    endif
.    if ${_OCAML_ARGS:Mrun}
_USE_OCAML_RUN=	yes
.    endif
.  endif # !empty(ocaml_ARGS)

#
# OCaml programs location
#
OCAMLC?=		${LOCALBASE}/bin/ocamlc
OCAMLC_OPT?=		${LOCALBASE}/bin/ocamlc.opt
OCAMLCP?=		${LOCALBASE}/bin/ocamlcp
OCAMLFIND?=		${LOCALBASE}/bin/ocamlfind
CAMLP4?=		${LOCALBASE}/bin/camlp4
OCAMLTK?=		${LOCALBASE}/bin/labltk

#
# OCaml library directory
#
OCAML_LIBDIR?=		lib/ocaml

#
# Where to install site libraries
#
OCAML_SITELIBDIR?=	${OCAML_LIBDIR}/site-lib

#
# OCaml compiler port dependency
#
OCAMLC_PORT?=		lang/ocaml
OCAMLC_DEPEND?=		${OCAMLC}:${OCAMLC_PORT}

#
# OCaml package manager port dependency
#
OCAMLFIND_PORT?=	devel/ocaml-findlib
OCAMLFIND_DEPEND?=	${OCAMLFIND}:${OCAMLFIND_PORT}

#
# OCaml camlp4 port dependency
#
CAMLP4_PORT?=		devel/ocaml-camlp4
CAMLP4_DEPEND?=		${CAMLP4}:${CAMLP4_PORT}

#
# Dune builder port
#
.  if defined(_USE_OCAML_DUNE)
BUILD_DEPENDS+=		ocaml-dune>=3.7.1_2:devel/ocaml-dune

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
# Left empty for default @install target
ALL_TARGET?=
.  endif

#
# OCaml TK bindings dependency
#
OCAMLTK_PORT?=		x11-toolkits/ocaml-labltk
OCAMLTK_DEPENDS?=	${OCAMLTK}:${OCAMLTK_PORT}

#
# Common OCaml examples and documents location
#
OCAML_DOCSDIR=		${PREFIX}/share/doc/ocaml
OCAML_EXAMPLESDIR=	${PREFIX}/share/examples/ocaml

#
# Location of OCaml ld.conf file
#
OCAML_LDCONF?=		${OCAML_LIBDIR}/ld.conf

# ocaml-findlib-1.4.1_1 wants to edit our ld.conf file, which does not
# work well with staging.
.  if defined(_USE_OCAML_LDCONFIG)
.    if !target(ocaml-ldconfig)
OCAMLFIND_LDCONF?=	/dev/null
.    endif
.  endif

OCAMLFIND_DESTDIR?=	${PREFIX}/${OCAML_SITELIBDIR}
OCAMLFIND_LDCONF?=	${PREFIX}/${OCAML_LDCONF}

.  if defined(_USE_OCAML_BUILD)
EXTRACT_DEPENDS+=	${OCAMLC_DEPEND}
PATCH_DEPENDS+=		${OCAMLC_DEPEND}
BUILD_DEPENDS+=		${OCAMLC_DEPEND}
.  endif
.  if defined(_USE_OCAML_RUN)
RUN_DEPENDS+=		${OCAMLC_DEPEND}
.  endif
PLIST_SUB+=	OCAML_SITELIBDIR="${OCAML_SITELIBDIR}"

.  if defined(_USE_OCAML_FINDLIB)
#
# We'll additionally add ocamlfind to RUN_DEPENDS, since
# if the port requires ocamlfind to install - it requires
# some ocaml libraries and these libraries RUN_DEPENDS on
# ocamlfind
#
BUILD_DEPENDS+=		${OCAMLFIND_DEPEND}
RUN_DEPENDS+=		${OCAMLFIND_DEPEND}
MAKE_ENV+=	OCAMLFIND_DESTDIR="${STAGEDIR}${OCAMLFIND_DESTDIR}" \
		OCAMLFIND_LDCONF="${OCAMLFIND_LDCONF}"

#
# Directories under site-lib to process automatically
#
OCAML_PKGDIRS?=	${PORTNAME}
_USES_install+=	250:ocaml-pre-install 735:ocaml-findlib
.    if !target(ocaml-pre-install)
ocaml-pre-install:
	${MKDIR} ${STAGEDIR}${OCAMLFIND_DESTDIR}
.    endif
.    if !target(ocaml-findlib)
ocaml-findlib:
.      for DIR in ${OCAML_PKGDIRS}
.        if defined(_USE_OCAML_FINDPLIST)
	@${FIND} ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${DIR}/ -type f -print | ${SED} -e \
		's,^${STAGEDIR}${PREFIX}/,,' >> ${TMPPLIST}
.        endif
	@${ECHO_CMD} "@postunexec ${OCAMLFIND} remove ${DIR} 2>/dev/null" \
		>> ${TMPPLIST}
.      endfor
.    endif
.  endif

.  if defined(_USE_OCAML_CAMLP4)
BUILD_DEPENDS+=		${CAMLP4_DEPEND}
.  endif

.    if defined(_USE_OCAML_TKBUILD)
EXTRACT_DEPENDS+=	${OCAMLTK_DEPENDS}
PATCH_DEPENDS+=		${OCAMLTK_DEPENDS}
BUILD_DEPENDS+=		${OCAMLTK_DEPENDS}
.    endif
.    if defined(_USE_OCAML_TKRUN)
RUN_DEPENDS+=		${OCAMLTK_DEPENDS}
.    endif

.  if defined(_USE_OCAML_LDCONFIG)
#
# Directories under PREFIX for appending to ld.conf
#
OCAML_LDLIBS?=	${OCAML_SITELIBDIR}/${PORTNAME}
_USES_install+=	740:ocaml-ldconfig
.    if !target(ocaml-ldconfig)
ocaml-ldconfig:
.      for LIB in ${OCAML_LDLIBS}
	@${ECHO_CMD} "@postexec ${ECHO_CMD} "%D/${LIB}" >> %D/${OCAML_LDCONF}" \
		>> ${TMPPLIST}
	@${ECHO_CMD} "@postunexec ${SED} -i \"\" -e '/${LIB:S#/#\/#g}/d' %D/${OCAML_LDCONF}"  >> ${TMPPLIST}
.      endfor
.    endif
.  endif

.  if defined(_USE_OCAML_WASH)
PLIST_FILES+=	"@rmempty ${OCAML_LDCONF}"
.  endif

.  if defined(_USE_OCAML_LDCONFIG) && defined(_USE_OCAML_DUNE)
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

.  if defined(_USE_OCAML_DUNE)
MAKE_ENV+=	${DUNE_ENV}

DO_MAKE_BUILD?=	${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${DUNE_CMD} build ${DUNE_ARGS} ${DUNE_BUILD_ARGS}
.  endif

.  if !target(do-install) && !defined(NO_INSTALL) && defined(_USE_OCAML_DUNE)
do-install:
	@(cd ${INSTALL_WRKSRC} && ${SETENV} ${WRK_ENV} ${MAKE_ENV} ${FAKEROOT} ${DUNE_CMD} install ${DUNE_ARGS} ${DUNE_INSTALL_ARGS} ${DUNE_INSTALL_TARGETS})
.  endif

.endif
