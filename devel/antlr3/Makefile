# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	antlr3
PORTVERSION=	3.5.2
CATEGORIES=	devel java
MASTER_SITES=	http://www.antlr3.org/download/
DISTNAME=	antlr-${PORTVERSION}-complete
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	takumiiinn@gmail.com
COMMENT=	ANother Tool for Language Recognition

LICENSE=	BSD3CLAUSE

NO_BUILD=	yes
NO_ARCH=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.7+
INSTALL_JAR=	${DISTFILES}
SUB_LIST=	INSTALL_JAR=${INSTALL_JAR}
SUB_FILES=	antlr.sh
PLIST_FILES=	bin/${PORTNAME} \
		${JAVAJARDIR}/${INSTALL_JAR}

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTFILES} ${STAGEDIR}${JAVAJARDIR}/${INSTALL_JAR}
	${INSTALL_SCRIPT} ${WRKDIR}/antlr.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
