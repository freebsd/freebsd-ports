# New ports collection makefile for:	JDOM
# Date created:		June 1, 2001
# Whom:			Ernst de Haan <znerd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jdom
PORTVERSION=	1.0b9
CATEGORIES=	java
MASTER_SITES=	http://www.jdom.org/dist/source/
DISTNAME=	${PORTNAME}-${PORTVERSION:C/[0-9]*\.[0-9]*//}

MAINTAINER=	znerd@FreeBSD.org
COMMENT=	Java library for accessing and manipulating XML documents

BUILD_DEPENDS=	${ANT}:${PORTSDIR}/devel/apache-ant

USE_JAVA=	1.2+

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/[0-9]*\.[0-9]*//}
PLIST_SUB+=	T=${TARGET_DIR:S/^${PREFIX}\///}
TARGET_DIR?=	${PREFIX}/share/java/${PORTNAME}-${PORTVERSION}
ANT?=		${LOCALBASE}/bin/ant
ANT_TARGET=	package javadoc

do-build:
	@cd ${WRKSRC} && ${ANT} ${ANT_TARGET}

do-install:
	@${ECHO} -n ">> Creating directory ${TARGET_DIR}..."
	@${MKDIR} ${TARGET_DIR}
	@${ECHO} " [ DONE ]"

	@${ECHO} -n ">> Copying files..."
	@${CP} -r ${WRKSRC}/* ${TARGET_DIR}
	@${ECHO} " [ DONE ]"

	@${ECHO} -n ">> Installing JAR..."
	@${CP} ${WRKSRC}/build/jdom.jar ${PREFIX}/share/java/classes/
	@${ECHO} " [ DONE ]"

.include <bsd.port.mk>
