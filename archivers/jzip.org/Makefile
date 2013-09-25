# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jzip.org
PORTVERSION=	0.2.0
PORTREVISION=	2
CATEGORIES=	archivers java
MASTER_SITES=	SF/jzipdotorg/jzipdotorg/${PORTVERSION}
DISTNAME=	${PORTNAME}${PORTVERSION}.src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	WinZip like program written in Java

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

PLIST_FILES=	%%JAVAJARDIR%%/jzip.org.jar bin/${PORTNAME}
USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+
WRKSRC=		${WRKDIR}/${PORTNAME}.${PORTVERSION}.src

SUB_FILES=	${PORTNAME}.sh

do-build:
	@cd ${WRKSRC} && ${JAVAC} -d bin src/*.java && \
	 cd bin && ${JAR} cvfm jzip.org.jar manifest/MANIFEST.MF \
			i18n/*.properties jzipdotorg/*.class images/*.png

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}/${PREFIX}/bin/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/bin/${PORTNAME}.jar ${STAGEDIR}/${JAVAJARDIR}

.include <bsd.port.mk>
