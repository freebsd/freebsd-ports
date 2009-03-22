# Date created:		2009-01-25
# Whom:			Wen Heping <wenheping@gmail.com>

.if defined(R_MOD)
MASTER_CRAN_SITES+=	http://mirrors.geoexpat.com/cran/src/contrib/ \
			http://cran.rakanu.com/src/contrib/ \
			http://cran.cnr.berkeley.edu/src/contrib/
.endif

MASTER_SITES?=	${MASTER_CRAN_SITES}

.if defined(R_MOD)
BUILD_DEPENDS+=	${LOCALBASE}/bin/R:${PORTSDIR}/math/R
RUN_DEPENDS+=	${LOCALBASE}/bin/R:${PORTSDIR}/math/R
.endif

R_MOD_DIR?=	lib/R/library/${PORTNAME}
PLIST_SUB+=	R_MOD_DIR=${R_MOD_DIR}

NO_BUILD=	yes
R_COMMAND=	${LOCALBASE}/bin/R
R_INS=		${R_COMMAND} CMD INSTALL

do-install:
.if defined(R_MOD)
	@cd ${WRKDIR} && ${R_INS} ${PORTNAME}
.endif

