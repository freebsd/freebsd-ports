# $FreeBSD$
#
# bsd.cl-asdf.mk - Common Lisp related macros
#
# SBCL		- Path to the Steel Bank Common Lisp compiler
# CLISP		- Path to the GNU Common Lisp compiler
# CL_LIBDIR_REL	- Common Lisp library directory, relative to LOCALBASE or PREFIX
# ASDF_PATHNAME	- Where to install compiled FASL files (depends on FASL_DIR_REL)
# ASDF_REGISTRY	- Path to ASDF registry
# DOCSDIR	- DOCSDIR using UNIQUENAME (to account for optional cl- PKGNAMEPREFIX)
# EXAMPLESDIR	- Same as above, for EXAMPLESDIR
# FASL_DIR_REL	- Relative path to compiled FASL files; depends on FASL_TARGET
# FASL_TARGET	- Platform for building FASL files (currently "sbcl" or "clisp")
# USE_SBCL	- If set, depend on lang/sbcl
# USE_CLISP	- If set, depend on lang/clisp
# USE_ASDF	- If set, depend on devel/cl-asdf
# USE_ASDF_FASL - If set, set dependency on compiled ASDF files (only if
#                 required by the chosen FASL_TARGET)
# FASL_BUILD	- If set, compile FASL files using the ASDF framework
# ASDF_MODULES	- If FASL_BUILD is set: list of ASDF modules to compile

CL_ASDF_Include_MAINTAINER=	olgeni@FreeBSD.org

SBCL?=		${LOCALBASE}/bin/sbcl
CLISP?=		${LOCALBASE}/bin/clisp

CL_LIBDIR_REL=	lib/common-lisp

ASDF_PATHNAME=	${PREFIX}/${CL_LIBDIR_REL}/${PORTNAME}
FASL_PATHNAME=	${PREFIX}/${CL_LIBDIR_REL}/${PORTNAME}/${FASL_DIR_REL}
ASDF_REGISTRY=	${PREFIX}/${CL_LIBDIR_REL}/system-registry

# Include PKGNAMEPREFIX in DOCSDIR and EXAMPLESDIR
DOCSDIR=	${PREFIX}/share/doc/${UNIQUENAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${UNIQUENAME}

.if defined(FASL_TARGET)
FASL_DIR_REL=	${FASL_TARGET}fasl
PKGNAMESUFFIX=	-${FASL_TARGET}
.if ${FASL_TARGET} == "sbcl"
USE_SBCL=	yes
.elif ${FASL_TARGET} == "clisp"
USE_CLISP=	yes
.endif
.endif # defined(FASL_TARGET)

.if defined(USE_SBCL)
BUILD_DEPENDS+=	sbcl:${PORTSDIR}/lang/sbcl
RUN_DEPENDS+=	sbcl:${PORTSDIR}/lang/sbcl
.elif defined(USE_CLISP)
BUILD_DEPENDS+=	clisp:${PORTSDIR}/lang/clisp
RUN_DEPENDS+=	clisp:${PORTSDIR}/lang/clisp
.endif # defined(USE_CLISP)

.if defined(USE_ASDF)
# Even if the Common Lisp compiler already has a bundled ASDF framework,
# we still need the asdf-init file.

BUILD_DEPENDS+=	${LOCALBASE}/${CL_LIBDIR_REL}/asdf/asdf.asd:${PORTSDIR}/devel/cl-asdf \
		${LOCALBASE}/${CL_LIBDIR_REL}/asdf-binary-locations/asdf-binary-locations.asd:${PORTSDIR}/devel/cl-asdf-binary-locations
RUN_DEPENDS+=	${LOCALBASE}/${CL_LIBDIR_REL}/asdf/asdf.asd:${PORTSDIR}/devel/cl-asdf \
		${LOCALBASE}/${CL_LIBDIR_REL}/asdf-binary-locations/asdf-binary-locations.asd:${PORTSDIR}/devel/cl-asdf-binary-locations

.endif # defined(USE_ASDF)

.if defined(USE_ASDF_FASL)
.if defined(USE_SBCL)
# SBCL already has a bundled ASDF framework
.elif defined(USE_CLISP)
BUILD_DEPENDS+=	${LOCALBASE}/${CL_LIBDIR_REL}/asdf/${FASL_DIR_REL}/asdf.fasl:${PORTSDIR}/devel/cl-asdf-clisp
RUN_DEPENDS+=	${LOCALBASE}/${CL_LIBDIR_REL}/asdf/${FASL_DIR_REL}/asdf.fasl:${PORTSDIR}/devel/cl-asdf-clisp
.endif # defined(USE_CLISP)
.endif # defined(USE_ASDF_FASL)

.if defined(FASL_BUILD)

ASDF_MODULES?=	${PORTNAME}

.if !target(do-build)

# See devel/cl-asdf/files/asdf-init.lisp for the meaning of FBSD_ASDF_COMPILE_PORT.

do-build:

.for MODULE in ${ASDF_MODULES}

.if defined(USE_SBCL)
	@FBSD_ASDF_COMPILE_PORT=t PORTNAME=${PORTNAME} WRKSRC=${WRKSRC}/ \
		${SBCL}	--noinform --userinit /dev/null --disable-debugger \
		--eval '#.(load "${LOCALBASE}/etc/asdf-init")' \
		--eval "(asdf:oos 'asdf:compile-op :${MODULE})" \
		--eval "(quit)"
.endif # USE_SBCL

.if defined(USE_CLISP)
	@FBSD_ASDF_COMPILE_PORT=t PORTNAME=${PORTNAME} WRKSRC=${WRKSRC}/ \
		${CLISP} -ansi -norc \
		-i ${LOCALBASE}/etc/asdf-init \
		-x "(asdf:oos 'asdf:compile-op :${MODULE})"
	@${FIND} ${WRKSRC} -name "*.lib" | ${XARGS} ${RM}
.endif # USE_CLISP

.endfor

.endif # !target(do-build)

.if !target(do-install)

do-install:
	@${MKDIR} ${FASL_PATHNAME}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${FASL_PATHNAME}

.endif # !target(do-install)

post-install:
	@cd ${WRKSRC} && ${FIND} * -type f \
		| ${SORT} \
		| ${AWK} '{ print "${CL_LIBDIR_REL}/${PORTNAME}/${FASL_DIR_REL}/" $$1 }' \
		>> ${TMPPLIST}
	@cd ${WRKSRC} && ${FIND} * -type d \
		| ${SORT} -r \
		| ${AWK} '{ print "@dirrm ${CL_LIBDIR_REL}/${PORTNAME}/${FASL_DIR_REL}/" $$1 }' \
		>> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm ${CL_LIBDIR_REL}/${PORTNAME}/${FASL_DIR_REL}" >> ${TMPPLIST}

.endif # FASL_BUILD
