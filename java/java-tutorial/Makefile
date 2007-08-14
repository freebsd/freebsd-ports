# New ports collection makefile for:	JDK tutorial
# Date created:		Tue Mar 23 10:18:20 EET 1999
# Whom:			Martti Kuparinen <martti.kuparinen@ericsson.com>
#
# $FreeBSD$
#

PORTNAME=	tutorial
PORTVERSION=	2007.05.14
CATEGORIES=	java devel
MASTER_SITES=	http://java.sun.com/docs/books/tutorialNB/download/
PKGNAMEPREFIX=	jdk-
DISTNAME=	tutorial.zip tut-examples.zip tut-swing.zip tut-bookstore-21.zip \
		tut-bookstore-tomcat.zip tut-bingo

MAINTAINER=	itetcu@FreeBSD.org
COMMENT=	Official Java 2 SDK tutorial

NO_WRKSUBDIR=	yes
RESTRICTED=	This software is under license and export control.
NO_BUILD=	yes
USE_ZIP=	yes
PORTDOCS=	*
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

.ifdef NOPORTDOCS
IGNORE=	this port is only documentation, please undefine NOPORTDOCS and try again
.endif

do-install:
	@${ECHO_MSG} -n ">> Creating directory ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
	@${ECHO_MSG} " [ DONE ]"

	@${ECHO_MSG} -n ">> Copying files..."
	@${CP} -R ${WRKSRC}/* ${DOCSDIR}
	@${CHOWN} -h -R ${DOCOWN}:${DOCGRP} ${DOCSDIR}
	@${ECHO_MSG} " [ DONE ]"

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
