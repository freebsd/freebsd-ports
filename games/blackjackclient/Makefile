# Created by: Jason Helfman <jgh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	BlackjackClient
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	games java
MASTER_SITES=	SF/t-blackjack/
DISTNAME=	t-blackjack-beta

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Simple Blackjack game in Java

LICENSE=	GPLv2

USES=		zip
USE_JAVA=	yes
PLIST_FILES=	bin/${PORTNAME} \
		${JAVAJARDIR}/${PORTNAME}.jar
SUB_FILES=	${PORTNAME}.sh

post-extract-script:
	@${ECHO_CMD} "Main-Class: ${PORTNAME}" > ${WRKDIR}/src/MANIFEST.MF

do-build:
	(cd ${WRKDIR}/src && ${SETENV} LANG=en_US.UTF-8 LC_ALL=en_US.UTF-8 \
		${JAVAC} ${PORTNAME}.java)

post-build-script:
	@cd ${WRKDIR}/src && \
		${JAR} -cfm ${PORTNAME}.jar MANIFEST.MF au ${PORTNAME}.class

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKDIR}/src/${PORTNAME}.jar ${STAGEDIR}${JAVAJARDIR}

.include <bsd.port.mk>
