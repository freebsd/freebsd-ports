# ex:ts=8
# Ports collection makefile for:	jzip.org
# Date created:			Dec 24, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

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
JAVA_VERSION=	1.5+
WRKSRC=		${WRKDIR}/${PORTNAME}.${PORTVERSION}.src

SUB_FILES=	${PORTNAME}.sh

do-build:
	@cd ${WRKSRC} && ${JAVAC} -d bin src/*.java && \
	 cd bin && ${JAR} cvfm jzip.org.jar manifest/MANIFEST.MF \
			i18n/*.properties jzipdotorg/*.class images/*.png

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${PREFIX}/bin/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/bin/${PORTNAME}.jar ${JAVAJARDIR}

.include <bsd.port.mk>
