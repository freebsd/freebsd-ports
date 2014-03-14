# $FreeBSD$
#
# handle zip archives
#
# MAINTAINER: portmgr@FreeBSD.org
#
# Feature:	zip
# Usage:	USES=zip[:infozip]
#
.if !defined(_INCLUDE_USES_ZIP_Mk)
_INCLUDE_USES_ZIP_MK=	yes

zip_ARGS?=	none

EXTRACT_SUFX?=	.zip

.if ${zip_ARGS} == infozip
EXTRACT_DEPENDS+=	${UNZIP_CMD}:${PORTSDIR}/archivers/unzip

EXTRACT_CMD?=		${UNZIP_CMD}
EXTRACT_BEFORE_ARGS?=	-qo
EXTRACT_AFTER_ARGS?=	-d ${WRKDIR}
.elif ${zip_ARGS} != none
IGNORE=	Incorrect 'USES+=zip:${zip_ARGS}' expecting 'USES+=zip[:infozip]'
.endif
.endif
