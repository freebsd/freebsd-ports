# New ports collection makefile for:	bluej
# Date created:		27 June 2001
# Whom:			Jeremy <karlj000@unbc.ca>
#
# $FreeBSD$
#

PORTNAME=	bluej
PORTVERSION=	1.2.2
PORTREVISION=	1
CATEGORIES=	java editors
MASTER_SITES=	ftp://ftp.bluej.org/pub/bluej/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.jar

MAINTAINER=	karlj000@unbc.ca
COMMENT=	BlueJ is an integrated Java environment designed for introductory teaching

IS_INTERACTIVE=	yes
EXTRACT_ONLY=
NO_BUILD=	yes

USE_JAVA=	1.3+

do-install:
	@${ECHO} Starting BlueJ graphical installer...  Please install to default path of
	@${ECHO} ${PREFIX}/bluej.  Close the installer when done.
	@cd ${PREFIX}; ${JAVA_HOME}/bin/java -jar ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}
	-@${MKDIR} ${PREFIX}/bin
	@${LN} -sf ${PREFIX}/bluej/bluej ${PREFIX}/bin/bluej

.include <bsd.port.mk>
