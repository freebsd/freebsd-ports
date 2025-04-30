PORTNAME=	junit
DISTVERSION=	4.13.2
CATEGORIES=	java devel
MASTER_SITES=	https://repo1.maven.org/maven2/${PORTNAME}/${PORTNAME}/${DISTVERSION}/
DISTFILES=	${DISTNAME}.jar ${DISTNAME}-sources.jar
EXTRACT_ONLY=

MAINTAINER=	atanubiswas484@gmail.com
COMMENT=	Regression testing utility for use with the Java(TM) Language
WWW=		https://www.junit.org/

LICENSE=	EPL

RUN_DEPENDS=	${JAVALIBDIR}/hamcrest.jar:java/hamcrest

USES=		cpe java
CPE_VENDOR=	junit
CPE_PRODUCT=	junit4

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${JAVAJARDIR}/junit.jar \
		${JAVAJARDIR}/junit4.jar \
		${DATADIR}/src.jar

do-install:
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}.jar \
		${STAGEDIR}${JAVAJARDIR}/junit.jar
	${LN} -sf junit.jar ${STAGEDIR}${JAVAJARDIR}/junit4.jar
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}-sources.jar \
		${STAGEDIR}${DATADIR}/src.jar

.include <bsd.port.mk>
