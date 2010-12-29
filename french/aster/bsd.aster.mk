# Date created:			  Tue Sep 14, 2010
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#
# Common variables used by ports related to Code_Aster

DISTVERSIONPREFIX=	full-src-
DISTVERSIONSUFFIX=	.noarch
MASTER_SITES=	http://www.code-aster.org/V2/UPLOAD/DOC/Telechargement/
DISTNAME=	aster-${DISTVERSIONPREFIX}${ASTER_DISTVERSION}${DISTVERSIONSUFFIX}
DISTINFO_FILE=	${.CURDIR}/../../french/aster/distinfo

ASTER_VER=	10.3.0
ASTER_DISTVERSION=	${ASTER_VER}-3
EXTRACT_WRKSRC=	${WRKDIR}/aster-${DISTVERSIONPREFIX}${ASTER_VER}/SRC

.if ${PORTNAME} == metis-edf
DVSFX=		${DISTVERSIONSUFFIX}
.elif ${PORTNAME} == homard
DVSFX=		.all
.endif

.if ${PORTNAME} != aster
post-extract:
	(cd ${WRKDIR} &&	\
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${EXTRACT_WRKSRC}/${PORTNAME}-${DISTVERSION}${DVSFX}${EXTRACT_SUFX} ${EXTRACT_AFTER_ARGS})
.endif
