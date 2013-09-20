# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	data
PORTVERSION=	20100630
CATEGORIES=	games
MASTER_SITES=	SF/vdrift/vdrift/vdrift-${DATE_VERSION}
PKGNAMEPREFIX=	vdrift-
DISTNAME=	${PKGNAMEPREFIX}${DATE_VERSION}
DIST_SUBDIR=	vdrift

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Vdrift driving simulation data files

USE_BZIP2=	yes
NO_PACKAGE=	Package will be 547MB, set FORCE_PACKAGE if you really want it
NO_BUILD=	yes
DATADIR=	${PREFIX}/share/vdrift
PLIST=		${WRKDIR}/pkg-plist
WRKSRC=		${WRKDIR}/${PKGNAMEPREFIX}${DATE_VERSION}

DATE_VERSION=	2010-06-30

NO_STAGE=	yes
post-extract:
	@cd ${WRKSRC}/data && \
		${FIND} * -name "SConscript*" -print0 | ${XARGS} -0 ${RM}
.for DIRE in music
	@${RMDIR} ${WRKSRC}/data/${DIRE}
.endfor

pre-install:
	@${RM} -f ${PLIST}
	@cd ${WRKSRC}/data && \
		${FIND} * -type f | ${SORT} | ${SED} -e 's|^|%%DATADIR%%/|' >> ${PLIST} && \
			${FIND} * -type d | ${SORT} -r | ${SED} -e 's|^|@dirrm %%DATADIR%%/|' >> ${PLIST}
	@${ECHO_CMD} "@dirrmtry %%DATADIR%%" >> ${PLIST}

do-install:
	${MKDIR} ${DATADIR}
	cd ${WRKSRC}/data && \
		${FIND} * -type d -exec ${MKDIR} "${DATADIR}/{}" \; && \
			${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${DATADIR}/{}" \;

.include <bsd.port.mk>
