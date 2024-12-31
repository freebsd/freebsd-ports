PORTNAME=	sabre
PORTVERSION=	20100501
PORTREVISION=	1
CATEGORIES=	devel multimedia java
MASTER_SITES=	SF/sabre-library
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Simple API for Binary REpresentations and an UDF Library
WWW=		https://sabre-library.sourceforge.net/

LICENSE=	LGPL21

USES=		dos2unix java:ant,run zip

WRKSRC=		${WRKDIR}/Simple\ API\ for\ Binary\ REpresentations\ \(SABRE\)
DOS2UNIX_GLOB=	*.xml *.java
ALL_TARGET=	dist

PLIST_FILES=	${JAVAJARDIR}/${PORTNAME}.jar ${JAVAJARDIR}/udflib.jar

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/dist/${PORTNAME}.jar \
		${WRKSRC}/dist/udflib.jar ${STAGEDIR}${JAVAJARDIR}/

.include <bsd.port.mk>
