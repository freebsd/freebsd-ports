# Provide support for Common Lisp ports.
#
# Feature:	cl
# Usage:	USES=cl
# Valid ARGS:	none
#
# Variables, which may be set by ports:
# ASDF_MODULES   - List of ASDF modules to build when FASL_TARGET is set (defaults to PORTNAME)
# FASL_TARGET    - Build fasl variant of port (one of ccl, clisp, or sbcl)
# USE_ASDF       - Depend on devel/cl-asdf
# USE_ASDF_FASL  - Depend on devel/cl-asdf-<FASL_TARGET>
# USE_CCL        - Depend on lang/ccl; implied when FASL_TARGET=ccl
# USE_CLISP      - Depend on lang/clisp; implied when FASL_TARGET=clisp
# USE_SBCL       - Depend on lang/sbcl; implied when FASL_TARGET=SBCL
#
# Variables to be read by ports:
# ASDF_PATHNAME  - Path to CL source
# ASDF_REGISTRY  - Path to CL registry containing asd files
# CCL            - Path to the Clozure Common Lisp compiler
# CLISP          - Path to the GNU Common Lisp compiler
# CL_LIBDIR_REL  - CL library directory relative to LOCALBASE or PREFIX
# DOCSDIR        - DOCSDIR accounting for cl- PKGNAMEPREFIX
# EXAMPLESDIR    - EXAMPLESDIR accounting for cl- PKGNAMEPREFIX
# FASL_DIR_REL   - Relative path to compiled fasl files; depends on FASL_TARGET
# FASL_PATHNAME	 - Path to CL fasl
# LISP_EXTRA_ARG - Extra arguments used when building fasl
# SBCL           - Path to the Steel Bank Common Lisp compiler

.if !defined(_INCLUDE_USES_CL_MK)
_INCLUDE_USES_CL_MK=	yes

CL_ASDF_Include_MAINTAINER=	olgeni@FreeBSD.org

CCL?=		${LOCALBASE}/bin/ccl
CLISP?=		${LOCALBASE}/bin/clisp
SBCL?=		${LOCALBASE}/bin/sbcl

CL_LIBDIR_REL=	lib/common-lisp

ASDF_PATHNAME=	${PREFIX}/${CL_LIBDIR_REL}/${PORTNAME}
ASDF_REGISTRY=	${PREFIX}/${CL_LIBDIR_REL}/system-registry

# Include PKGNAMEPREFIX in DOCSDIR and EXAMPLESDIR
DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGBASE}

.  if ${PORTNAME} != "ccl"
NO_ARCH=	yes
.  endif

.  if defined(FASL_TARGET)
FASL_DIR_REL=	${FASL_TARGET}fasl
FASL_PATHNAME=	${PREFIX}/${CL_LIBDIR_REL}/${PORTNAME}/${FASL_DIR_REL}
PKGNAMESUFFIX=	-${FASL_TARGET}
.    if ${FASL_TARGET} == "ccl"
USE_CCL=	yes
.    elif ${FASL_TARGET} == "clisp"
USE_CLISP=	yes
.    elif ${FASL_TARGET} == "sbcl"
USE_SBCL=	yes
.    endif
.  endif # defined(FASL_TARGET)

.  if defined(USE_CCL)
BUILD_DEPENDS+=	ccl:lang/ccl
RUN_DEPENDS+=	ccl:lang/ccl
.  elif defined(USE_CLISP)
BUILD_DEPENDS+=	clisp:lang/clisp
RUN_DEPENDS+=	clisp:lang/clisp
.  elif defined(USE_SBCL)
BUILD_DEPENDS+=	sbcl:lang/sbcl
RUN_DEPENDS+=	sbcl:lang/sbcl
.  endif

.  if defined(USE_ASDF)
# Depend on the ASDF port, even if the Common Lisp compiler already has a bundled
# ASDF framework.
BUILD_DEPENDS+=	${LOCALBASE}/${CL_LIBDIR_REL}/asdf/asdf.asd:devel/cl-asdf
RUN_DEPENDS+=	${LOCALBASE}/${CL_LIBDIR_REL}/asdf/asdf.asd:devel/cl-asdf
.  endif # defined(USE_ASDF)

.  if defined(USE_ASDF_FASL)
.    if defined(USE_CCL)
BUILD_DEPENDS+=	${LOCALBASE}/${CL_LIBDIR_REL}/asdf/${FASL_DIR_REL}/build/asdf.fx64fsl:devel/cl-asdf-ccl
RUN_DEPENDS+=	${LOCALBASE}/${CL_LIBDIR_REL}/asdf/${FASL_DIR_REL}/build/asdf.fx64fsl:devel/cl-asdf-ccl
.    elif defined(USE_CLISP)
BUILD_DEPENDS+=	${LOCALBASE}/${CL_LIBDIR_REL}/asdf/${FASL_DIR_REL}/build/asdf.fas:devel/cl-asdf-clisp
RUN_DEPENDS+=	${LOCALBASE}/${CL_LIBDIR_REL}/asdf/${FASL_DIR_REL}/build/asdf.fas:devel/cl-asdf-clisp
.    elif defined(USE_SBCL)
BUILD_DEPENDS+=	${LOCALBASE}/${CL_LIBDIR_REL}/asdf/${FASL_DIR_REL}/build/asdf.fasl:devel/cl-asdf-sbcl
RUN_DEPENDS+=	${LOCALBASE}/${CL_LIBDIR_REL}/asdf/${FASL_DIR_REL}/build/asdf.fasl:devel/cl-asdf-sbcl
.    endif
.  endif # defined(USE_ASDF_FASL)

.  if defined(FASL_TARGET)

ASDF_MODULES?=	${PORTNAME}

.    if !target(do-build)
# See devel/cl-freebsd-asdf-init/files/cl-freebsd-asdf-init.lisp for the meaning
# of FBSD_ASDF_COMPILE_PORT.
do-build:
.      for MODULE in ${ASDF_MODULES}
.        if defined(USE_CCL)
	@FBSD_ASDF_COMPILE_PORT=t PORTNAME=${PORTNAME} WRKSRC=${WRKSRC}/ \
		${CCL} ${LISP_EXTRA_ARG} -b -n \
		-l ${LOCALBASE}/etc/cl-freebsd-asdf-init \
		-e "(asdf:oos 'asdf:compile-op :${MODULE})"
.        endif # USE_CCL

.        if defined(USE_CLISP)
	@FBSD_ASDF_COMPILE_PORT=t PORTNAME=${PORTNAME} WRKSRC=${WRKSRC}/ \
		${CLISP} ${LISP_EXTRA_ARG} -ansi -norc \
		-i ${LOCALBASE}/etc/cl-freebsd-asdf-init \
		-x "(asdf:oos 'asdf:compile-op :${MODULE})"
.        endif # USE_CLISP

.        if defined(USE_SBCL)
	@FBSD_ASDF_COMPILE_PORT=t PORTNAME=${PORTNAME} WRKSRC=${WRKSRC}/ \
		${SBCL} ${LISP_EXTRA_ARG} --noinform --userinit /dev/null --disable-debugger \
		--eval '#.(load "${LOCALBASE}/etc/cl-freebsd-asdf-init")' \
		--eval "(asdf:oos 'asdf:compile-op :${MODULE})" \
		--eval "(quit)"
.        endif # USE_SBCL
.      endfor
.    endif # !target(do-build)

.    if !target(do-install)
do-install:
	@${MKDIR} ${STAGEDIR}${FASL_PATHNAME}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${FASL_PATHNAME}

.    endif # !target(do-install)
post-install:
	@cd ${WRKSRC} && ${FIND} * -type f \
		| ${SORT} \
		| ${AWK} '{ print "${CL_LIBDIR_REL}/${PORTNAME}/${FASL_DIR_REL}/" $$1 }' \
		>> ${TMPPLIST}

.  endif # FASL_TARGET

.endif # _INCLUDE_USES_ASDF_MK
