# New ports collection makefile for:	JDK tutorial
# Date created:		Tue Mar 23 10:18:20 EET 1999
# Whom:			Martti Kuparinen <martti.kuparinen@ericsson.com>
#
# $FreeBSD$
#

PORTNAME=	jdk-tutorial
PORTVERSION=	2005.04.15
CATEGORIES=	java devel
MASTER_SITES=	http://java.sun.com/docs/books/tutorialNB/download/
.if defined(WITH_EXTRAS)
DISTNAME=	tutorial.zip tut-examples.zip tut-swing.zip tut-bookstore-21.zip \
		tut-bookstore-tomcat.zip tut-bingo
.else
DISTNAME=	tutorial
.endif

MAINTAINER=	ringworm01@gmail.com
COMMENT=	Official Java 2 SDK tutorial

NO_WRKSUBDIR=	yes
RESTRICTED=	"This software is under license and export control."
NO_BUILD=	yes
USE_ZIP=	yes
PORTDOCS=	*
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

pre-extract:
.if !defined(WITH_EXTRAS)
	@${ECHO_MSG}	"*"
	@${ECHO_MSG}	"* make install WITH_EXTRAS=yes will add to the installation:"
	@${ECHO_MSG}	"*"
	@${ECHO_MSG}	"* 1) source files for all the tutorial examples"
	@${ECHO_MSG}	"*"
	@${ECHO_MSG}	"* 2) Some examples such as the BINGO and Servlets Bookstore examples"
	@${ECHO_MSG}	"* include many source files in a rather complex directory structure,"
	@${ECHO_MSG}	"* so these examples are separate files."
	@${ECHO_MSG}	"*"
	@${ECHO_MSG}	"* 3) The JFC/Swing trail"
	@${ECHO_MSG}	"*"
.endif

.include <bsd.port.pre.mk>

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

.include <bsd.port.post.mk>
