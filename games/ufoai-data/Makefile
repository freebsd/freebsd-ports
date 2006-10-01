# New ports collection makefile for:	ufoai-data
# Date created:		2006-09-03
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	data
DISTVERSION=	2.0rc5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PKGNAMEPREFIX:S/-//}
PKGNAMEPREFIX=	ufoai-
DISTNAME=	${PKGNAMEPREFIX}${DISTVERSION:S/r/-r/}-linux
EXTRACT_SUFX=	.run
DIST_SUBDIR=	${PKGNAMEPREFIX:S/-//}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	UFO alien invasion data files

NO_PACKAGE=	Package will be 160MB, set FORCE_PACKAGE if you really want it
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST=		${WRKDIR}/pkg-plist
DATADIR=	share/${PKGNAMEPREFIX:S/-//}

do-extract:
	@${MKDIR} ${WRKSRC}
	@cd ${WRKSRC} && \
		${TAIL} -c +9390 ${_DISTDIR}/${DISTFILES} | ${TAR} xf -
	@cd ${WRKSRC} && \
		${TAR} -xjf ${PORTNAME}.tar.bz2

post-patch:
	@cd ${WRKSRC}/base && \
		${RM} -rf i18n game.so

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
