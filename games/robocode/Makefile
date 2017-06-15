# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	robocode
PORTVERSION=	1.9.2.6
CATEGORIES=	games java
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${DISTVERSION}-setup.jar
EXTRACT_SUFX=	# empty
DIST_SUBDIR=	java

MAINTAINER=	dbaio@bsd.com.br
COMMENT=	Game for learning Java[tm] programming language

LICENSE=	EPL
LICENSE_FILE=	${WRKSRC}/license/epl-v10.html

USES=		dos2unix zip:infozip
DOS2UNIX_GLOB=	*.css *.team *.properties package-list MANIFEST.MF
USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_EXTRACT=	yes
JAVA_RUN=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
NO_ARCH=	yes

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

PLIST_SUB=	PORTVERSION=${PORTVERSION}

SUB_FILES=	${PORTNAME}-MeleeRumble ${PORTNAME}-RoboRumble \
		${PORTNAME}-Robocode ${PORTNAME}-TeamRumble \
		${PORTNAME}-TwinDuel pkg-deinstall pkg-message

do-install:
	cd ${WRKDIR} && ${INSTALL_SCRIPT} ${SUB_FILES:Mrobocode-*} \
		${STAGEDIR}${PREFIX}/bin/

.for d in battles compilers javadoc libs license roborumble robots \
	templates theme
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR})
.endfor

.for f in *.ico *.sh ReadMe.* versions.md
	@(${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DATADIR})
.endfor

	${INSTALL_DATA} ${WRKSRC}/desktop/*.desktop ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/desktop/*.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DATADIR}/config

.include <bsd.port.mk>
