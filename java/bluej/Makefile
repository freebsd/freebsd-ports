# Created by: Jeremy <karlj000@unbc.ca>
# $FreeBSD$

PORTNAME=	bluej
PORTVERSION=	3.0.9
CATEGORIES=	java editors
MASTER_SITES=	http://www.bluej.org/download/files/ \
		ftp://ftp.bluej.org/pub/bluej/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Integrated Java environment designed for introductory teaching

IS_INTERACTIVE=	yes
NO_BUILD=	yes

USE_JAVA=	yes
JAVA_VERSION=	1.6+

do-install:
	@${ECHO} Starting BlueJ graphical installer...  
	@${ECHO} Please install to default path of
	@${ECHO} ${STAGEDIR}${PREFIX}/bluej.
	@${ECHO} Close the installer when done.
	@cd ${STAGEDIR}${PREFIX}; ${JAVA_HOME}/bin/java \
		-jar ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}
	-@${MKDIR} ${STAGEDIR}${PREFIX}/bin
	@${LN} -sf ${STAGEDIR}${PREFIX}/bluej/bluej \
		${STAGEDIR}${PREFIX}/bin/bluej

.include <bsd.port.mk>
