# New ports collection makefile for:	bluej
# Date created:		27 June 2001
# Whom:			Jeremy <karlj000@unbc.ca>
#
# $FreeBSD$
#

PORTNAME=	bluej
PORTVERSION=	1.2.0
CATEGORIES=	java editors
MASTER_SITES=	ftp://ftp.bluej.org/pub/bluej/ \
		http://www.metaverse.nl/~ernst/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	znerd
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.jar

MAINTAINER=	karlj000@unbc.ca

IS_INTERACTIVE=	yes
EXTRACT_ONLY=
NO_BUILD=	yes

# Called MY_JDK and MY_JDK_PORT so not to conflict with any other possible
# definitions in the ports system.
MY_JDK=		linux-sun-jdk1.4.0
MY_JDK_PORT=	linux-sun-jdk14
RUN_DEPENDS=    ${LOCALBASE}/${MY_JDK}/bin/java:${PORTSDIR}/java/${MY_JDK_PORT}

do-install:
	@${LN} -s ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${PREFIX}/${DISTNAME}${EXTRACT_SUFX}
	@${ECHO} Starting BlueJ graphical installer...  Please install to default path of
	@${ECHO} ${PREFIX}/bluej.  Close the installer when done.
	@cd ${PREFIX}; ${LOCALBASE}/${MY_JDK}/bin/java -jar ${DISTNAME}${EXTRACT_SUFX}
	@${RM} -f ${PREFIX}/${DISTNAME}${EXTRACT_SUFX}

.include <bsd.port.mk>
