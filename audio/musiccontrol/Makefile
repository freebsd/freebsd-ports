# New ports collection makefile for:   musiccontrol
# Date created:        9 june 2003
# Whom:                Christian Laursen <xi@borderworlds.dk>
#
# $FreeBSD$
#

PORTNAME=	musiccontrol
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	audio java
MASTER_SITES=	http://borderworlds.dk/projects/mc/
DISTNAME=	MusicControl-0.1
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	xi@borderworlds.dk
COMMENT=	An advanced music player

RUN_DEPENDS=	${LOCALBASE}/bin/mpg123:${PORTSDIR}/audio/mpg123 \
		${LOCALBASE}/bin/ogg123:${PORTSDIR}/audio/vorbis-tools \
		${LOCALBASE}/bin/simplemod:${PORTSDIR}/audio/simplemod

USE_JAVA=	1.3+
NO_BUILD=	yes

do-install:
	@${MKDIR} ${PREFIX}/share/java/classes
	${INSTALL} -o 0 -g 0 -m 0644 ${DISTDIR}/MusicControl-${PORTVERSION}.jar ${PREFIX}/share/java/classes
	${SED} 's,%%PREFIX%%,${PREFIX},g' ${FILESDIR}/musiccontrol > ${WRKDIR}/musiccontrol
	${INSTALL} -o 0 -g 0 ${WRKDIR}/musiccontrol ${PREFIX}/bin

.include <bsd.port.mk>
