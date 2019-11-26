# Created by: Christian Laursen <xi@borderworlds.dk>
# $FreeBSD$

PORTNAME=	musiccontrol
PORTVERSION=	0.3
PORTREVISION=	2
CATEGORIES=	audio java
MASTER_SITES=	http://borderworlds.dk/projects/mc/
DISTNAME=	MusicControl-0.3
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	xi@borderworlds.dk
COMMENT=	Advanced music player

RUN_DEPENDS=	${LOCALBASE}/bin/mpg123:audio/mpg123 \
		${LOCALBASE}/bin/ogg123:audio/vorbis-tools \
		${LOCALBASE}/bin/simplemod:audio/simplemod

USE_JAVA=	yes
NO_BUILD=	yes
PLIST_FILES=	share/java/classes/MusicControl-${PORTVERSION}.jar bin/musiccontrol

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${DISTDIR}/MusicControl-${PORTVERSION}.jar ${STAGEDIR}${JAVAJARDIR}/
	${SED} 's,%%LOCALBASE%%,${LOCALBASE},g ; s,%%JAVAJARDIR%%,${JAVAJARDIR},g' \
		${FILESDIR}/musiccontrol > ${WRKDIR}/musiccontrol
	${INSTALL_SCRIPT} ${WRKDIR}/musiccontrol ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
