# New ports collection makefile for:	bluej
# Date created:		27 June 2001
# Whom:			Jeremy <karlj000@unbc.ca>
#
# $FreeBSD$
#

PORTNAME=	bluej
PORTVERSION=	1.3.5
CATEGORIES=	java editors
MASTER_SITES=	http://www.bluej.org/download/files/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	kij@imada.sdu.dk
COMMENT=	BlueJ is a Java environment designed for introductory teaching

IS_INTERACTIVE=	yes
NO_BUILD=	yes

USE_JAVA=	1.3+

do-install:
	@${ECHO} Starting BlueJ graphical installer...  Please install to default path of
	@${ECHO} ${PREFIX}/bluej.  Close the installer when done.
	@cd ${PREFIX}; ${JAVA_HOME}/bin/java -jar ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}
	-@${MKDIR} ${PREFIX}/bin
	@${LN} -sf ${PREFIX}/bluej/bluej ${PREFIX}/bin/bluej

.include <bsd.port.mk>
