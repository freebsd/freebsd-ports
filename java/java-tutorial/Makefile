# New ports collection makefile for:	JDK tutorial
# Date created:		Tue Mar 23 10:18:20 EET 1999
# Whom:			Martti Kuparinen <martti.kuparinen@ericsson.com>
#
# $FreeBSD$
#

#  Install size for version 2004.03.11 is ~22827 kB.

PORTNAME=	jdk-tutorial
PORTVERSION=	2004.03.11
PORTREVISION=	1
CATEGORIES=	java
MASTER_SITES=	http://java.sun.com/docs/books/tutorial/download/
DISTNAME=	tutorial

MAINTAINER=	ringworm01@gmail.com
COMMENT=	Official Java 2 SDK tutorial

NO_WRKSUBDIR=	yes
RESTRICTED=	"This software is under license and export control."
NO_BUILD=	yes
USE_ZIP=	yes
PORTDOCS=	*

.include <bsd.port.pre.mk>

do-install:
	@${ECHO_MSG} -n ">> Creating directory ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
	@${ECHO_MSG} " [ DONE ]"

	@${ECHO_MSG} -n ">> Copying files..."
	@${CP} -R ${WRKSRC}/* ${DOCSDIR}
	@${CHOWN} -h -R ${DOCOWN}:${DOCGRP} ${DOCSDIR}
	@${ECHO_MSG} " [ DONE ]"

.include <bsd.port.post.mk>
