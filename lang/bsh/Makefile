# Created by: Kimura Fuyuki <fuyuki@mj.0038.net>
# $FreeBSD$

PORTNAME=	bsh
DISTVERSION=	2.0b6
CATEGORIES=	lang java

MAINTAINER=	pfg@FreeBSD.org
COMMENT=	Beanshell java scripting language

LICENSE=	APACHE20

USE_GITHUB=	yes
GH_ACCOUNT=	beanshell
GH_PROJECT=	beanshell

USE_JAVA=	yes
JAVA_VERSION=	1.6+

USE_ANT=	yes
ALL_TARGET=	jarall

SUB_FILES=	${PORTNAME}.sh
SUB_LIST=	JARNAME=${PORTNAME}.jar

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar \
		bin/${PORTNAME}

do-install:
	${INSTALL_DATA} ${WRKSRC}/dist/${PORTNAME}-${DISTVERSION}.jar \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
