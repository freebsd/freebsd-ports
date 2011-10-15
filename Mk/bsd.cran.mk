# Date created:		2009-01-25
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

CRAN_Include_MAINTAINER=	wen@FreeBSD.org

.if defined(USE_R_MOD)
MASTER_CRAN_SITES+=	http://ftp.ctex.org/mirrors/CRAN/src/contrib/ \
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
.endif

MASTER_SITES?=	${MASTER_CRAN_SITES}

.if defined(USE_R_MOD)
BUILD_DEPENDS+=	${LOCALBASE}/bin/R:${PORTSDIR}/math/R
RUN_DEPENDS+=	${LOCALBASE}/bin/R:${PORTSDIR}/math/R
.endif

R_MOD_DIR?=	lib/R/library/${PORTNAME}
PLIST_SUB+=	R_MOD_DIR=${R_MOD_DIR}
WRKSRC?=	${WRKDIR}/${PORTNAME}

NO_BUILD=	yes
R_COMMAND=	${LOCALBASE}/bin/R
R_INS=		${R_COMMAND} CMD INSTALL

do-install:
.if defined(USE_R_MOD)
	@cd ${WRKDIR} && ${R_INS} ${PORTNAME}
.endif

.if defined(USE_R_MOD) && defined(R_MOD_AUTOPLIST)
.if !target(post-install-script)
post-install-script:
	@${FIND} -ds ${PREFIX}/${R_MOD_DIR} \( -type f -or -type l \) -print | \
		${SED} -E -e 's,^${PREFIX}/?,,' >> ${TMPPLIST}
	@${FIND} -ds ${PREFIX}/${R_MOD_DIR} -type d -print | ${SED} -E -e \
		's,^${PREFIX}/?,@dirrm ,' >> ${TMPPLIST}
.endif
.endif

