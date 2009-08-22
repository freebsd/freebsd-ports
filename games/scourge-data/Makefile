# New ports collection makefile for:	scourge-data
# Date created:		2006-06-13
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	data
PORTVERSION=	0.21.1
CATEGORIES=	games
MASTER_SITES=	SF/scourge/scourge/${PORTVERSION}
PKGNAMEPREFIX=	scourge-
DISTNAME=	${PKGNAMEPREFIX}${PORTVERSION}${PORTNAME:S/^/./}
DIST_SUBDIR=	${PKGNAMEPREFIX:S/-//}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	S.C.O.U.R.G.E data files

NO_BUILD=	yes

DATADIR=	share/${PKGNAMEPREFIX:S/-//}
PLIST=		${WRKDIR}/pkg-plist
WRKSRC=		${WRKDIR}/${PKGNAMEPREFIX:S/-/_/}${PORTNAME}

pre-install:
	@${RM} -f ${PLIST}
	@cd ${WRKSRC} && \
		${FIND} * -type f | ${SORT} | ${SED} -e 's|^|%%DATADIR%%/|' >> ${PLIST} && \
			${FIND} * -type d | ${SORT} -r | ${SED} -e 's|^|@dirrm %%DATADIR%%/|' >> ${PLIST}
	@${ECHO_CMD} "@dirrm %%DATADIR%%" >> ${PLIST}

do-install:
	@cd ${WRKSRC} && \
		${MKDIR} ${PREFIX}/${DATADIR} && \
			${CP} -R * ${PREFIX}/${DATADIR}
	@cd ${PREFIX}/${DATADIR} && \
		${FIND} * -type f -print0 | ${XARGS} -0 ${CHMOD} ${SHAREMODE}

.include <bsd.port.mk>
