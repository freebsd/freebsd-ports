# $FreeBSD$
#
# Use the Comprehensive R Archive Network 
#
# Feature:	cran
# Usage:	USES=cran or USES=cran:ARGS
# Valid ARGS:	auto-plist
#
# auto-plist	The pkg-plist can be automatically compiled
#
# MAINTAINER=	wen@FreeBSD.org

.if !defined(_INCLUDE_USES_CRAN_MK)
_INCLUDE_USES_CRAN_MK=	yes

VALID_ARGS=	auto-plist

MASTER_SITE_CRAN+=	http://ftp.ctex.org/mirrors/CRAN/src/contrib/ \
			http://cran.rakanu.com/src/contrib/ \
			http://cran.ms.unimelb.edu.au/src/contrib/ \
			http://mirror.its.dal.ca/cran/src/contrib/ \
			http://mirrors.dotsrc.org/cran/src/contrib/ \
			http://cran.univ-lyon1.fr/src/contrib/ \
			http://ftp5.gwdg.de/pub/misc/cran/src/contrib/ \
			http://cran.stat.unipd.it/src/contrib/ \
			http://cran.md.tsukuba.ac.jp/src/contrib/ \
			http://mirrors.ibiblio.org/pub/mirrors/CRAN/src/contrib/ \
			http://cran.cnr.berkeley.edu/src/contrib/
MASTER_SITE_CRAN_ARCHIVE+=	${MASTER_SITE_CRAN:S,$,Archive/${PORTNAME}/,}

MASTER_SITES?=	${MASTER_SITE_CRAN} ${MASTER_SITE_CRAN_ARCHIVE}

USES+=		fortran
BUILD_DEPENDS+=	${LOCALBASE}/bin/R:${PORTSDIR}/math/R
RUN_DEPENDS+=	${LOCALBASE}/bin/R:${PORTSDIR}/math/R

PKGNAMEPREFIX?=	R-cran-

R_LIB_DIR=	lib/R/library
R_MOD_DIR?=	${R_LIB_DIR}/${PORTNAME}
PLIST_SUB+=	R_MOD_DIR=${R_MOD_DIR}
WRKSRC?=	${WRKDIR}/${PORTNAME}

NO_BUILD=	yes
R_COMMAND=	${LOCALBASE}/bin/R

.if !target(regression-test)
R_POSTCMD_CHECK_OPTIONS?=	--timings

.if !exists(${LOCALBASE}/bin/pdflatex)
R_POSTCMD_CHECK_OPTIONS+=	--no-manual --no-rebuild-vignettes
.endif

.if defined(NO_STAGE)
check-makevars::
	@${ECHO_MSG} "Makefile error: USE_R_MOD cannot be used with NO_STAGE"
	@${FALSE}
.endif

regression-test: build
	@cd ${WRKDIR} ; ${SETENV} ${MAKE_ENV} _R_CHECK_FORCE_SUGGESTS_=FALSE \
	${R_COMMAND} ${R_PRECMD_CHECK_OPTIONS} CMD check \
	${R_POSTCMD_CHECK_OPTIONS} ${PORTNAME}
.endif

.if !target(do-install)
R_POSTCMD_INSTALL_OPTIONS+=	-l ${STAGEDIR}${PREFIX}/${R_LIB_DIR}
.if defined(NOPORTDATA)
R_POSTCMD_INSTALL_OPTIONS+=	--no-data --no-demo
.else
R_POSTCMD_INSTALL_OPTIONS+=	--install-tests
.endif

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
.if !target(post-install-script)
post-install-script:
	@${FIND} -ds ${STAGEDIR}${PREFIX}/${R_MOD_DIR} \( -type f -or -type l \) -print | \
		${SED} -E -e 's,^${STAGEDIR}${PREFIX}/?,,' >> ${TMPPLIST}
	@${FIND} -ds ${STAGEDIR}${PREFIX}/${R_MOD_DIR} -type d -print | ${SED} -E -e \
		's,^${STAGEDIR}${PREFIX}/?,@dirrm ,' >> ${TMPPLIST}
.endif
.endif

.endif #_INCLUDE_USES_CRAN_MK
