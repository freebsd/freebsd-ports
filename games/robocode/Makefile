# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	robocode
PORTVERSION=	1.9.2.2
CATEGORIES=	games java
MASTER_SITES=	SF
DISTFILES=	${PORTNAME}-${DISTVERSION}-setup.jar
DIST_SUBDIR=	java

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Game for learning Java[tm] programming language

LICENSE=	EPL

USES=		dos2unix zip
DOS2UNIX_GLOB=	*.css *.team *.properties package-list MANIFEST.MF
USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_EXTRACT=	yes
JAVA_RUN=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

PLIST_SUB=	PORTVERSION=${PORTVERSION}

SUB_FILES=	${PORTNAME}-MeleeRumble ${PORTNAME}-RoboRumble \
		${PORTNAME}-Robocode ${PORTNAME}-TeamRumble \
		${PORTNAME}-TwinDuel pkg-deinstall pkg-message

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}-* \
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
	@(cd ${STAGEDIR}${DATADIR} && ${CHMOD} -R 775 config roborumble robots)
	@${CHMOD} +x ${STAGEDIR}${DATADIR}/*.sh

.include <bsd.port.mk>
