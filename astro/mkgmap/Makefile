# New ports collection makefile for:	mkgmap
# Date created:		17 May 2010
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mkgmap
PORTVERSION=	r1625
CATEGORIES=	astro java
MASTER_SITES=	http://www.mkgmap.org.uk/snapshots/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Convert OpenStreetMap data into a Garmin format

NO_BUILD=	yes

USE_JAVA=	yes
JAVA_VERSION=	1.6+

SUB_FILES=	${PORTNAME}.sh

PLIST_FILES=	bin/${PORTNAME} ${JAVAJARDIR:C,${PREFIX}/?,,}/${PORTNAME}.jar
PORTDOCS=	*

do-install:
	${MKDIR} ${JAVAJARDIR}/
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.jar ${JAVAJARDIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${PREFIX}/bin/${PORTNAME}
.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DOCSDIR}/
.endif

.include <bsd.port.mk>
