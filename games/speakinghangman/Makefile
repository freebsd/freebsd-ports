# $FreeBSD$

PORTNAME=	speakinghangman
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	games java
MASTER_SITES=	http://www.athenasoft.net/hangman/ \
		http://www.athenasoft.net/assets/images/hangman/:icons
DISTFILES=	${RESTRICTED_FILES} \
		icon48x48.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${RESTRICTED_FILES}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Educational game to practice and expand English and Spanish

RESTRICTED=	License does not allow redistribution
RESTRICTED_FILES=	${PORTNAME}free-${DISTVERSION}${EXTRACT_SUFX}

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}free-${PORTVERSION}

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="Speaking Hangman" \
		"Educational game to practice and expand English and Spanish" \
		"${PREFIX}/share/pixmaps/${PORTNAME}.png" \
		"${PORTNAME}" \
		"Game;Education;Languages;" \
		false

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "lib *.jar" ${DATADIR})
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/icon48x48.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

.include <bsd.port.mk>
