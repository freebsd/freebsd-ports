# ex:ts=4
#
# $MBSDlabs: portmk/bsd.ocaml.mk,v 1.18 2006/08/06 18:47:23 stas Exp $
# $FreeBSD$
#
# bsd.ocaml.mk - Support for the Objective Caml language packages
#
# Author: Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# Feel free to send any comments and suggestions to maintainer.
#
# Currently recognised variables are:
#
# USE_OCAML		-	Set if your port uses OCaml to build/install.
# NO_OCAML_BUILDDEPENDS	-	Don't add ocamlc to BUILD|EXTRACT|PATCH_DEPENDS.
# NO_OCAML_RUNDEPENDS	-	Don't add ocamlc to RUN_DEPENDS.
# USE_OCAML_FINDLIB	-	Set if your port uses ocamlfind to install
#				packages. Package direcories will be
#				automatically deleted.
# USE_OCAML_CAMLP4	-	Set if your port uses camlp4 to build.
# USE_OCAML_TK		-	Set if you port needs ocaml-labltk.
# NO_OCAMLTK_BUILDDEPENDS -	Don't add labltk to BUILD|EXTRACT|PATCH_DEPENDS.
# NO_OCAMLTK_RUNDEPENDS	-	Don't add labltk to RUN_DEPENDS.
# USE_OCAML_LDCONFIG	-	Set if your port installs shared libraries
#				into ocaml site-lib dir. OCaml ld.conf file
#				will be automatically processed.
# USE_OCAMLFIND_PLIST	-	Add contents of findlib target directories
#				automatically.
# USE_OCAML_WASH	-	Set if your port wants to automatically
#				purge shared Ocaml dirs on uninstall. It's
#				useful when installing to non-standard PREFIX
# OCAML_PKGDIRS		-	Directories under site-lib to be processed
#				if USE_OCAML_FINDLIB specified.
#				Default: ${PORTNAME}
# OCAML_LDLIBS		-	Directories under PREFIX to be automatically
#				added/removed from ld.conf
#				Default: ${OCAML_SITELIBDIR}/${PORTNAME}

.if !defined(OCAML_include)

OCAML_MAINTAINER=	ports@FreeBSD.org
OCAML_include=		bsd.ocaml.mk

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
.if defined(USE_OCAML_LDCONFIG)
. if !target(ocaml-ldconfig)
OCAMLFIND_LDCONF?=	/dev/null
. endif
.endif

OCAMLFIND_DESTDIR?=	${PREFIX}/${OCAML_SITELIBDIR}
OCAMLFIND_LDCONF?=	${PREFIX}/${OCAML_LDCONF}

.if defined(USE_OCAML)
. if !defined(NO_OCAML_BUILDDEPENDS)
EXTRACT_DEPENDS+=	${OCAMLC_DEPEND}
PATCH_DEPENDS+=		${OCAMLC_DEPEND}
BUILD_DEPENDS+=		${OCAMLC_DEPEND}
. endif
. if !defined(NO_OCAML_RUNDEPENDS)
RUN_DEPENDS+=		${OCAMLC_DEPEND}
. endif
PLIST_SUB+=	OCAML_SITELIBDIR="${OCAML_SITELIBDIR}"
.endif

.if defined(USE_OCAML_FINDLIB)
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
_USES_install+=	735:ocaml-findlib
. if !target(ocaml-findlib)
ocaml-findlib:
.  for DIR in ${OCAML_PKGDIRS}
.   if defined(USE_OCAMLFIND_PLIST)
	@${FIND} ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${DIR}/ -type f -print | ${SED} -e \
		's,^${STAGEDIR}${PREFIX}/,,' >> ${TMPPLIST}
.   endif
	@${ECHO_CMD} "@unexec ${OCAMLFIND} remove ${DIR} 2>/dev/null" \
		>> ${TMPPLIST}
.  endfor
. endif
.endif

.if defined(USE_OCAML_CAMLP4)
BUILD_DEPENDS+=		${CAMLP4_DEPEND}
.endif

.if defined(USE_OCAML_TK)
. if !defined(NO_OCAMLTK_BUILDDEPENDS)
EXTRACT_DEPENDS+=	${OCAMLTK_DEPENDS}
PATCH_DEPENDS+=		${OCAMLTK_DEPENDS}
BUILD_DEPENDS+=		${OCAMLTK_DEPENDS}
. endif
. if !defined(NO_OCAMLTK_RUNDEPENDS)
RUN_DEPENDS+=		${OCAMLTK_DEPENDS}
. endif
.endif

.if defined(USE_OCAML_LDCONFIG)
#
# Directories under PREFIX for appending to ld.conf
#
OCAML_LDLIBS?=	${OCAML_SITELIBDIR}/${PORTNAME}
_USES_install+=	740:ocaml-ldconfig
. if !target(ocaml-ldconfig)
ocaml-ldconfig:
.  for LIB in ${OCAML_LDLIBS}
	@${ECHO_CMD} "@postexec ${ECHO_CMD} "%D/${LIB}" >> %D/${OCAML_LDCONF}" \
		>> ${TMPPLIST}
	@${ECHO_CMD} "@postunexec ${SED} -i \"\" -e '/${LIB:S#/#\/#g}/d' %D/${OCAML_LDCONF}"  >> ${TMPPLIST}
.  endfor
. endif
.endif

.if defined(USE_OCAML_WASH)
. if !target(ocaml-wash)
_USES_install+=	745:ocaml-wash
ocaml-wash:
#	If ld.conf is empty
	@${ECHO_CMD} "@postunexec if [ ! -s %D/${OCAML_LDCONF} ]; then ${RM} -f %D/${OCAML_LDCONF}; fi || true" >> ${TMPPLIST}
. endif
.endif

.endif #!defined(OCAML_include)

.if defined(_POSTMKINCLUDED)

.if defined(USE_OCAML_FINDLIB)

pre-install: ${STAGEDIR}${OCAMLFIND_DESTDIR}
${STAGEDIR}${OCAMLFIND_DESTDIR}:
	@${MKDIR} ${.TARGET}

.endif

.endif # _POSTMKINCLUDED
