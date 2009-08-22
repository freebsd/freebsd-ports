# New ports collection makefile for:	ufoai-data
# Date created:		2006-09-03
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	data
PORTVERSION=	2.2.1
CATEGORIES=	games
MASTER_SITES=	SF/ufoai/UFO_AI%202.x/${PORTVERSION}
PKGNAMEPREFIX=	ufoai-
DISTNAME=	${PKGNAMEPREFIX}${PORTVERSION}-${PORTNAME}
EXTRACT_SUFX=	.tar
DIST_SUBDIR=	${PKGNAMEPREFIX:S/-//}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	UFO alien invasion data files

EXTRACT_DEPENDS=unzip:${PORTSDIR}/archivers/unzip

NO_PACKAGE=	Package will be 400MB, set FORCE_PACKAGE if you really want it
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

DATADIR=	share/${PKGNAMEPREFIX:S/-//}
PLIST=		${WRKDIR}/pkg-plist

post-extract:
	@cd ${WRKDIR}/base && \
		${FIND} * -type f -exec ${UNZIP_CMD} "{}" -d ${WRKDIR}/base \;
	@${RM} ${WRKDIR}/base/*.pk3

pre-install:
	@${RM} -f ${PLIST}
	@cd ${WRKDIR}/base && \
		${FIND} * -type f | ${SORT} | ${SED} -e 's|^|%%DATADIR%%/|' >> ${PLIST} && \
			${FIND} * -type d | ${SORT} -r | ${SED} -e 's|^|@dirrm %%DATADIR%%/|' >> ${PLIST}
	@${ECHO_CMD} "@dirrm %%DATADIR%%" >> ${PLIST}

do-install:
	${MKDIR} ${PREFIX}/${DATADIR}
	cd ${WRKDIR}/base && \
		${FIND} * -type d -exec ${MKDIR} "${PREFIX}/${DATADIR}/{}" \; && \
			${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${PREFIX}/${DATADIR}/{}" \;

.include <bsd.port.mk>
