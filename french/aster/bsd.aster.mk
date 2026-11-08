# Created by: Thierry Thomas (<thierry@pompo.net>)
#
# Common variables used by ports related to Code_Aster

DISTINFO_FILE=	${.CURDIR}/../../french/aster/distinfo

ASTER_VER=	17.5.4
PRE_REQ_VER=	20251026
PRE_REQ_TAG=	274083360	# See https://gitlab.com/codeaster-opensource-documentation/opensource-installation-development/-/blob/main/devel/changelog.md
MASTER_SITES=	https://gitlab.com/codeaster/src/-/archive/${ASTER_VER}/:aster	\
		https://gitlab.com/codeaster-opensource-documentation/opensource-installation-development/-/package_files/${PRE_REQ_TAG}/download?dummy=/:prereq
USES+=		tar:bz2
ASTERTAR=	src-${ASTER_VER}${EXTRACT_SUFX}

PREREQ=		codeaster-prerequisites-${PRE_REQ_VER}-oss
PREREQTAR=	${PREREQ}.tar.gz
DISTFILES=	${ASTERTAR}:aster	\
		${PREREQTAR}:prereq
DIST_SUBDIR=	Code_Aster

inst_dir=	${PREFIX}/aster	# ASTER_ROOT

.if ${PORTNAME} == aster
EXTRACT_ONLY=	${ASTERTAR}
.else
EXTRACT_ONLY=	${PREREQTAR}
EXTRACT_WRKSRC=	${WRKDIR}/${PREREQ}/archives
.endif

.if ${PORTNAME} == metis-edf
TARNAME=	${PORTNAME:C|-edf||}
.else
TARNAME=	${PORTNAME}
.endif

.if ${PORTNAME} != aster
post-extract:
.  if (${PORTNAME} != medcoupling) && (${PORTNAME} != codeaster-frontend)
	(cd ${WRKDIR}/ &&	\
	${TAR} ${EXTRACT_BEFORE_ARGS} ${EXTRACT_WRKSRC}/${TARNAME}${DVPFX}-${DISTVERSION}${DVSFX}.tar.gz ${EXTRACT_AFTER_ARGS})
.  else
	(cd ${WRKDIR}/ &&	\
	${TAR} ${EXTRACT_BEFORE_ARGS} ${EXTRACT_WRKSRC}/${PORTNAME}-${SHTAGNAME}${DVPFX}.tar.gz ${EXTRACT_AFTER_ARGS})
.  endif
.endif
