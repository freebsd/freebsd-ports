# New ports collection makefile for:   musiccontrol
# Date created:        9 june 2003
# Whom:                Christian Laursen <xi@borderworlds.dk>
#
# $FreeBSD$
#

PORTNAME=	musiccontrol
PORTVERSION=	0.2
CATEGORIES=	audio java
MASTER_SITES=	http://borderworlds.dk/projects/mc/
DISTNAME=	MusicControl-0.2
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	xi@borderworlds.dk
COMMENT=	An advanced music player

RUN_DEPENDS=	${LOCALBASE}/bin/mpg123:${PORTSDIR}/audio/mpg123 \
		${LOCALBASE}/bin/ogg123:${PORTSDIR}/audio/vorbis-tools \
		${LOCALBASE}/bin/simplemod:${PORTSDIR}/audio/simplemod \
		java:${PORTSDIR}/java/javavmwrapper

USE_JAVA=	yes
JAVA_VERSION=	1.3+
NO_BUILD=	yes

do-install:
	@${MKDIR} ${JAVAJARDIR}
	${INSTALL_DATA} ${DISTDIR}/MusicControl-${PORTVERSION}.jar ${JAVAJARDIR}/
	${SED} 's,%%LOCALBASE%%,${LOCALBASE},g ; s,%%JAVAJARDIR%%,${JAVAJARDIR},g' \
		${FILESDIR}/musiccontrol > ${WRKDIR}/musiccontrol
	${INSTALL_SCRIPT} ${WRKDIR}/musiccontrol ${PREFIX}/bin

.include <bsd.port.mk>
