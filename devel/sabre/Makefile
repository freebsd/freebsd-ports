# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sabre
PORTVERSION=	20100501
CATEGORIES=	devel multimedia java
MASTER_SITES=	SF/sabre-library
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Simple API for Binary REpresentations and an UDF Library

LICENSE=	LGPL21

WRKSRC=		${WRKDIR}/Simple\ API\ for\ Binary\ REpresentations\ \(SABRE\)
USES=		dos2unix zip
DOS2UNIX_GLOB=	*.xml *.java
USE_JAVA=	yes
USE_ANT=	yes
ALL_TARGET=	dist

PLIST_FILES=	${JAVAJARDIR}/${PORTNAME}.jar ${JAVAJARDIR}/udflib.jar

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/dist/${PORTNAME}.jar \
		${WRKSRC}/dist/udflib.jar ${STAGEDIR}${JAVAJARDIR}/

.include <bsd.port.mk>
