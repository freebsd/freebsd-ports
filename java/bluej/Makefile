# New ports collection makefile for:	bluej
# Date created:		27 June 2001
# Whom:			Jeremy <karlj000@unbc.ca>
#
# $FreeBSD$
#

PORTNAME=	bluej
PORTVERSION=	1.1.5
CATEGORIES=	java editors
MASTER_SITES=	ftp://mars.pscit.monash.edu.au/pub/mik/bluej/ \
		ftp://ftp.monash.edu.au/pub/bluej/
DISTNAME=	bluej-115
EXTRACT_SUFX=	.jar

MAINTAINER=	karlj000@unbc.ca

IS_INTERACTIVE=	yes
EXTRACT_ONLY=
NO_BUILD=	yes

# Called MY_JDK and MY_JDK_PORT so not to conflict with any other possible
# defns in the ports system.
MY_JDK=		linux-jdk1.3.1
MY_JDK_PORT=	linux-jdk13
RUN_DEPENDS=    ${LOCALBASE}/${MY_JDK}/bin/java:${PORTSDIR}/java/${MY_JDK_PORT}

do-install:
	@${LN} -s ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${PREFIX}/${DISTNAME}${EXTRACT_SUFX}
	@${ECHO} ""
	@${ECHO} Starting BlueJ graphical installer...  Please install to default path of
	@${ECHO} ${PREFIX}/bluej.  Close the installer when done.
	@cd ${PREFIX}; ${LOCALBASE}/${MY_JDK}/bin/java -jar ${DISTNAME}${EXTRACT_SUFX}
	@${RM} -f ${PREFIX}/${DISTNAME}${EXTRACT_SUFX}

.include <bsd.port.mk>
