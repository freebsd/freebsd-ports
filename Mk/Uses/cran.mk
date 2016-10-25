# $FreeBSD$
#
# Use the Comprehensive R Archive Network 
#
# Feature:	cran
# Usage:	USES=cran or USES=cran:ARGS
# Valid ARGS:	auto-plist, compiles
#
# auto-plist	The pkg-plist is to be automatically generated
# compiles	The port has code that needs to be compiled
#
# MAINTAINER=	dbn@FreeBSD.org

.if !defined(_INCLUDE_USES_CRAN_MK)
_INCLUDE_USES_CRAN_MK=	yes

MASTER_SITES?=	CRAN/src/contrib CRAN_ARCHIVE/src/contrib

BUILD_DEPENDS+=	${LOCALBASE}/bin/R:math/R
RUN_DEPENDS+=	${LOCALBASE}/bin/R:math/R

PKGNAMEPREFIX?=	R-cran-

R_LIB_DIR=	lib/R/library
R_MOD_DIR?=	${R_LIB_DIR}/${PORTNAME}
PLIST_SUB+=	R_MOD_DIR=${R_MOD_DIR}
WRKSRC?=	${WRKDIR}/${PORTNAME}

NO_BUILD=	yes
R_COMMAND=	${LOCALBASE}/bin/R

.if !target(do-test)
R_POSTCMD_CHECK_OPTIONS?=	--timings

.if !exists(${LOCALBASE}/bin/pdflatex)
R_POSTCMD_CHECK_OPTIONS+=	--no-manual --no-build-vignettes
.endif

do-test:
	@${FIND} ${WRKSRC} \( -name '*.o' -o -name '*.so' \) -delete
	@cd ${WRKDIR} ; ${SETENV} ${MAKE_ENV} _R_CHECK_FORCE_SUGGESTS_=FALSE \
	${R_COMMAND} ${R_PRECMD_CHECK_OPTIONS} CMD check \
	${R_POSTCMD_CHECK_OPTIONS} ${PORTNAME}
.endif

.if !target(do-install)
R_POSTCMD_INSTALL_OPTIONS+=	-l ${STAGEDIR}${PREFIX}/${R_LIB_DIR}
R_POSTCMD_INSTALL_OPTIONS+=	--install-tests

.if defined(NOPORTDOCS)
R_POSTCMD_INSTALL_OPTIONS+=	--no-docs --no-html
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${R_LIB_DIR}
	@cd ${WRKDIR} ; ${SETENV} ${MAKE_ENV} ${R_COMMAND} \
	${R_PRECMD_INSTALL_OPTIONS} CMD INSTALL \
	${R_POSTCMD_INSTALL_OPTIONS} ${PORTNAME}
.endif

.if ${cran_ARGS:Mauto-plist}
_USES_install+=	750:cran-auto-plist
cran-auto-plist:
	@${FIND} -ds ${STAGEDIR}${PREFIX}/${R_MOD_DIR} \( -type f -or -type l \) -print | \
		${SED} -E -e 's,^${STAGEDIR}${PREFIX}/?,,' >> ${TMPPLIST}
.endif

.if ${cran_ARGS:Mcompiles}
_USES_install+= 755:cran-strip
cran-strip:
	${FIND} ${STAGEDIR}${PREFIX}/${R_MOD_DIR} -name '*.so' -exec ${STRIP_CMD} {} +
.include "${PORTSDIR}/math/R/compiler.mk"
.include "${USESDIR}/fortran.mk"
.endif

.endif #_INCLUDE_USES_CRAN_MK
