# New ports collection makefile for:   bouncycastle
# Date created:        27 December 2001
# Whom:                rasputin
#
# $FreeBSD$
#

PORTNAME=	bouncycastle
PORTVERSION=	1.11
CATEGORIES=	java security
MASTER_SITES=	http://www.bouncycastle.org/download/
DISTNAME=	jce-jdk13-${PORTVERSION:S/.//}

MAINTAINER=	rara.rasputin@virgin.net

BUILD_DEPENDS=	${JAVADIR}/bin/java:${PORTSDIR}/java/jdk13

JAVADIR?=	${LOCALBASE}/jdk1.3.1
JAVALIBDIR=	${PREFIX}/share/java/classes
API_DOCDIR=	${PREFIX}/share/doc/java/${PORTNAME}/api
JAR_CMD?=	${JAVADIR}/bin/jar

JAR_NAME=	bouncycastle.jar

NO_BUILD=	yes

do-install:
	@${ECHO} "Installing ${JAR_NAME}..."
	@${MKDIR} ${JAVALIBDIR}
	@${JAR_CMD} cf ${JAVALIBDIR}/${JAR_NAME} -C ${WRKSRC}/classes .
	@${ECHO} "Installing docs in ${API_DOCDIR}..."
	@${MKDIR} ${API_DOCDIR}
	@${CP} -R ${WRKSRC}/docs/* ${API_DOCDIR}

.include <bsd.port.mk>
