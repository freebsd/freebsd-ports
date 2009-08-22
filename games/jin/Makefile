# New ports collection makefile for:	jin
# Date created:		2007-03-05
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jin
PORTVERSION=	2.14.1
PORTREVISION=	2
CATEGORIES=	games java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-unix

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A graphical client for chess servers

NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+

SUB_FILES=	${PORTNAME}
SUB_LIST=	JINJAR=${JINJAR}

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

JINJAR=	${PORTNAME}.jar

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

FIND_DIRS=	. -type d
FIND_DATA=	. -type f
RM_FILES=	${PORTNAME} README changelog.txt gpl.txt

post-extract:
.for f in ${RM_FILES}
	@${RM} ${WRKSRC}/${f}
.endfor

do-install:
	@${MKDIR} ${DATADIR}
	@cd ${WRKSRC} && ${FIND} ${FIND_DIRS} -exec ${MKDIR} ${DATADIR}/{} ";"
	@cd ${WRKSRC} && ${FIND} ${FIND_DATA} -exec ${INSTALL_DATA} {} ${DATADIR}/{} ";"
	@${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
