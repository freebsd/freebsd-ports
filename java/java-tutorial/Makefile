# New ports collection makefile for:	JDK tutorial
# Date created:		Tue Mar 23 10:18:20 EET 1999
# Whom:			Martti Kuparinen <martti.kuparinen@ericsson.com>
#
# $FreeBSD$
#

PORTNAME=	jdk-tutorial
PORTVERSION=	2005.02.17
CATEGORIES=	java
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
	@${ECHO}	"***********************************************************************"
	@${ECHO}	"*                                                                     *"
.if !defined(WITH_EXTRAS)
	@${ECHO}	"* make install WITH_EXTRAS=1 will add to the installation:            *"
	@${ECHO}	"*                                                                     *"
	@${ECHO}	"* 1) source files for all the tutorial examples                       *"
	@${ECHO}	"*                                                                     *"
	@${ECHO}	"* 2) Some examples such as the BINGO and Servlets Bookstore examples  *"
	@${ECHO}	"* include many source files in a rather complex directory structure,  *"
	@${ECHO}	"* so these examples are separate files.                               *"
	@${ECHO}	"*                                                                     *"
	@${ECHO}	"* 3) The JFC/Swing trail                                              *"
	@${ECHO}	"*                                                                     *"
.endif
	@${ECHO}	"* Set your browser to ${DOCSDIR}/index.html and enjoy!                *"
	@${ECHO}	"*                                                                     *"
	@${ECHO}	"* Michael C. Shultz (port maintainer)                                 *"
	@${ECHO}	"* ringworm01@gmail.com                                                *"
	@${ECHO}	"*                                                                     *"
	@${ECHO}	"***********************************************************************"

.include <bsd.port.post.mk>
