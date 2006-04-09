# New ports collection makefile for:	bos
# Date created:				14 Oct 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	bos
PORTVERSION=	1.1
CATEGORIES=	games
MASTER_SITES=	http://bos.seul.org/files/
DISTNAME=	${PORTNAME}_${PORTVERSION:S/./_/g}

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	A real-time strategy game

RUN_DEPENDS=	stratagus:${PORTSDIR}/games/stratagus

PLIST=		${WRKDIR}/pkg-plist

PLIST_FILES=	bin/bos
PLIST_DIRS=	%%DATADIR%%

do-build:
	@(${ECHO_CMD} "#!${SH}"; \
	  ${ECHO_CMD} 'exec ${LOCALBASE}/bin/stratagus -d ${DATADIR} "$$@"') \
	  > ${WRKDIR}/${PORTNAME}

pre-install:
	@${RM} -f ${PLIST}
	@cd ${WRKSRC}/data && \
	${FIND} * -type d -empty | ${SORT} | ${SED} -e \
		's|^|@exec mkdir -p %D/%%DATADIR%%/|' >> ${PLIST} && \
	${FIND} * -type f | ${SORT} | ${SED} -e \
		's|^|%%DATADIR%%/|' >> ${PLIST} && \
	${FIND} * -type d | ${SORT} -r | ${SED} -e \
		's|^|@dirrm %%DATADIR%%/|' >> ${PLIST}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	cd ${WRKSRC}/data && \
	${FIND} * -type d -exec ${MKDIR} "${DATADIR}/{}" \; && \
	${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${DATADIR}/{}" \;

.include <bsd.port.mk>
