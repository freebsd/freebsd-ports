# New ports collection makefile for:	JDK tutorial
# Date created:		Tue Mar 23 10:18:20 EET 1999
# Whom:			Martti Kuparinen <martti.kuparinen@ericsson.com>
#
# $FreeBSD$
#

PORTNAME=	jdk-tutorial
PORTVERSION=	2002.03.04
CATEGORIES=	java
MASTER_SITES=	ftp://ftp.javasoft.com/docs/ \
		http://java.sun.com/docs/books/tutorial/download/
DISTNAME=	tutorial

MAINTAINER=	znerd@FreeBSD.org

NO_WRKSUBDIR=	yes
RESTRICTED=	"This software is under license and export control."
NO_BUILD=	yes
TARGET_DIR=	${PREFIX}/share/doc/java-tutorial/
PLIST_SUB+=	T=${TARGET_DIR:S/^${PREFIX}\///}

.include <bsd.port.pre.mk>

do-install:
	@${ECHO} -n ">> Creating directory ${TARGET_DIR}..."
	@${MKDIR} ${TARGET_DIR}
	@${ECHO} " [ DONE ]"

	@${ECHO} -n ">> Copying files..."
	@${CP} -R ${WRKSRC}/* ${TARGET_DIR}
	@${ECHO} " [ DONE ]"

.include <bsd.port.post.mk>
