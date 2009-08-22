# Ports collection makefile for:	ganttproject
# Date created:			Jul 6, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ganttproject
DISTVERSION=	2.1-m3
CATEGORIES=	deskutils java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-development/Loire%20M3
EXTRACT_SUFX=	-src.zip

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Plan projects using a Gantt chart

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}-src/${PORTNAME}-builder

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+
USE_ANT=	yes

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
CPIOARGS=	--quiet -pdum -R

SUB_FILES=	${PORTNAME}.sh

.include <bsd.port.pre.mk>

do-install:
	@${MKDIR} -m 0755 -p ${DATADIR}
	(cd ${WRKSRC}/dist-bin && \
	    ${CP} ${WRKSRC}/ganttproject-eclipsito-config.xml ${WRKSRC}/dist-bin && \
	    ${FIND} . | ${GREP} -v './.*\.\(sh\|bat\|command\)' | \
	    ${CPIO} ${CPIOARGS} ${LIBOWN}:${LIBGRP} ${DATADIR})
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.post.mk>
