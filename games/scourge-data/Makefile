# New ports collection makefile for:	scourge-data
# Date created:		2006-06-13
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	data
PORTVERSION=	0.14
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	scourge
PKGNAMEPREFIX=	scourge-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	${PKGNAMEPREFIX:S/-//}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	S.C.O.U.R.G.E data files

NO_BUILD=	yes

DATADIR=	share/${PKGNAMEPREFIX:S/-//}
WRKSRC=	${WRKDIR}/${PKGNAMEPREFIX:S/-/_/}${PORTNAME}

do-install:
	@cd ${WRKSRC} && \
		${MKDIR} ${PREFIX}/${DATADIR} && \
			${CP} -R * ${PREFIX}/${DATADIR}
	@cd ${PREFIX}/${DATADIR} && \
		${FIND} * -type f -print0 | ${XARGS} -0 ${CHMOD} ${SHAREMODE}

.include <bsd.port.mk>
