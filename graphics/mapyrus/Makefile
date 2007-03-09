# New ports collection makefile for:	mapyrus
# Date created:		2006-04-25
# Whom:			Nicola Vitale	<nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	mapyrus
PORTVERSION=	0.702
CATEGORIES=	graphics print java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A software for creating plots of points, lines, etc

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

USE_JAVA=	yes
JAVA_VERSION=	1.4+
USE_ZIP=	yes

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
SUB_FILES=	${PORTNAME} pkg-message
SUB_LIST=	MAPYRUSJAR=${MAPYRUSJAR}

MAPYRUSJAR=	${PORTNAME}.jar
MAPYRUSDOCS=	${PORTNAME}.pdf

FIND_DATA=	-type f -not \( -iname "copying" -or -iname "*.tex" \)
FIND_HERE=	userdoc

.if defined(WITH_EXAMPLES)
PLIST_SUB=	PORTEXAMPLES=""
.else
PLIST_SUB=	PORTEXAMPLES="@comment "
.endif

do-install:
	${MKDIR} ${DATADIR}
	cd ${WRKDIR} && ${INSTALL_DATA} ${MAPYRUSJAR} ${DATADIR}/${MAPYRUSJAR}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKDIR} && ${INSTALL_DATA} ${MAPYRUSDOCS} ${DOCSDIR}/
.endif
.if defined(WITH_EXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKDIR} && ${FIND} ${FIND_HERE} ${FIND_DATA} -exec ${INSTALL_DATA} {} ${EXAMPLESDIR} \;
.endif

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
