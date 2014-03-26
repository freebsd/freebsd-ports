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
OCAMLC_PORT?=		${PORTSDIR}/lang/ocaml
OCAMLC_DEPEND?=		${OCAMLC}:${OCAMLC_PORT}

#
# OCaml package manager port dependency
#
OCAMLFIND_PORT?=	${PORTSDIR}/devel/ocaml-findlib
OCAMLFIND_DEPEND?=	${OCAMLFIND}:${OCAMLFIND_PORT}

#
# Common OCaml examples and documents location
#
OCAML_DOCSDIR=		${PREFIX}/share/doc/ocaml
OCAML_EXAMPLESDIR=	${PREFIX}/share/examples/ocaml

#
# Location of OCaml ld.conf file
#
OCAML_LDCONF?=		${OCAML_LIBDIR}/ld.conf

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

.if defined(USE_OCAML_FINDLIB) || defined(USE_OCAML_LDCONFIG)
. if !target(post-install-script)
post-install-script: ocaml-findlib ocaml-ldconfig ocaml-wash
. endif
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
. if !target(ocaml-findlib)
ocaml-findlib:
.  for DIR in ${OCAML_PKGDIRS}
.   if defined(USE_OCAMLFIND_PLIST)
	@${FIND} ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${DIR}/ -type f -print | ${SED} -e \
		's,^${STAGEDIR}${PREFIX}/,,' >> ${TMPPLIST}
.   endif
	@${ECHO_CMD} "@unexec rmdir %D/${OCAML_SITELIBDIR}/${DIR} 2>/dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${OCAMLFIND} remove ${DIR} 2>/dev/null" \
		>> ${TMPPLIST}
.  endfor
. endif
.endif

.if defined(USE_OCAML_LDCONFIG)
#
# Directories under PREFIX for appending to ld.conf
#
OCAML_LDLIBS?=	${OCAML_SITELIBDIR}/${PORTNAME}
. if !target(ocaml-ldconfig)
ocaml-ldconfig:
.  for LIB in ${OCAML_LDLIBS}
.   if defined(NO_STAGE)
	@${ECHO_CMD} "${PREFIX}/${LIB}" >> "${PREFIX}/${OCAML_LDCONF}"
.   endif
	@${ECHO_CMD} "@exec ${ECHO_CMD} "%D/${LIB}" >> %D/${OCAML_LDCONF}" \
		>> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${SED} -i \"\" -e '/${LIB:S#/#\/#g}/d' %D/${OCAML_LDCONF}"  >> ${TMPPLIST}
.  endfor
. endif
.endif

.if defined(USE_OCAML_WASH)
. if !target(ocaml-wash)
ocaml-wash:
	@${ECHO_CMD} "@unexec rmdir %D/${OCAML_SITELIBDIR} 2>/dev/null || true"\
		>> ${TMPPLIST}
#	If ld.conf is empty
	@${ECHO_CMD} "@unexec if [ ! -s %D/${OCAML_LDCONF} ]; then ${RM} -f %D/${OCAML_LDCONF}; fi || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rmdir %D/${OCAML_LIBDIR} 2>/dev/null || true" \
		>> ${TMPPLIST}
. endif
.endif

.if !target(ocaml-findlib)
ocaml-findlib:
	@${DO_NADA}
.endif

.if !target(ocaml-ldconfig)
ocaml-ldconfig:
	@${DO_NADA}
.endif

.if !target(ocaml-wash)
ocaml-wash:
	@${DO_NADA}
.endif

#
# XXX: temporary workaround for non-standard PREFIX
#
.if !target(add-plist-post)
add-plist-post:
. if (${PREFIX} != ${LOCALBASE} && \
	${PREFIX} != ${LINUXBASE} && ${PREFIX} != "/usr")
	@${ECHO_CMD} "@unexec rmdir %D 2> /dev/null || true" >> ${TMPPLIST}
. else
	@${DO_NADA}
. endif

# If we are using PORTDOCS macro port cannot delete OCAML_DOCSDIR, so
# we shoud try to accomodate it
. if defined(PORTDOCS)
	@${ECHO_CMD} "@unexec rmdir ${OCAML_DOCSDIR} 2>/dev/null || true" \
		>> ${TMPPLIST}
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
