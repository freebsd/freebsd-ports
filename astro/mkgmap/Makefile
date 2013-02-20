# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mkgmap
PORTVERSION=	r2487
CATEGORIES=	astro converters java
MASTER_SITES=	http://www.mkgmap.org.uk/download/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Convert OpenStreetMap data into a Garmin format

NO_BUILD=	yes

USE_JAVA=	yes
JAVA_VERSION=	1.6+

SUB_FILES=	${PORTNAME}.sh

PLIST_FILES=	bin/${PORTNAME} ${JAVAJARDIR:C,${PREFIX}/?,,}/${PORTNAME}.jar
PORTDOCS=	*

.include <bsd.port.options.mk>

do-install:
	${MKDIR} ${JAVAJARDIR}/
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.jar ${JAVAJARDIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${PREFIX}/bin/${PORTNAME}
.if ${PORT_OPTIONS:MDOCS}
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DOCSDIR}/
.endif

.include <bsd.port.mk>
