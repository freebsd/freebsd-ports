# Created by: Thierry Thomas (<thierry@pompo.net>)
# $FreeBSD$
#
# Common variables used by ports related to Code_Aster

DISTVERSIONPREFIX=	full-src-
DISTVERSIONSUFFIX=	.noarch
MASTER_SITES=	http://www.code-aster.org/FICHIERS/
DISTNAME=	aster-${DISTVERSIONPREFIX}${ASTER_DISTVERSION}${DISTVERSIONSUFFIX}
DISTINFO_FILE=	${.CURDIR}/../../french/aster/distinfo

ASTER_VER=	11.5.0
ASTER_DISTVERSION=	${ASTER_VER}-4
EXTRACT_WRKSRC=	${WRKDIR}/aster-${DISTVERSIONPREFIX}${ASTER_VER}/SRC

.if ${PORTNAME} == metis-edf
TARNAME=	${PORTNAME:C|-edf||}
.else
TARNAME=	${PORTNAME}
.endif

.if ${PORTNAME} == homard
DVSFX=		.all
.endif

.if ${PORTNAME} != aster
post-extract:
	(cd ${WRKDIR} &&	\
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${EXTRACT_WRKSRC}/${TARNAME}${DVPFX}-${DISTVERSION}${DVSFX}${EXTRACT_SUFX} ${EXTRACT_AFTER_ARGS})
.endif
