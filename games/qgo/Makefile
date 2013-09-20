# Created by: ijliao
# $FreeBSD$

PORTNAME=	qgo
PORTVERSION=	2.s764
CATEGORIES=	games
MASTER_SITES=	DEBIAN
DISTNAME=	${PORTNAME}_2~svn764.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Go board and SGF editor written with the Qt library

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_BZIP2=	yes
USES=		desktop-file-utils
USE_QT4=	gui network qtestlib moc_build qmake_build rcc_build uic_build

PLIST_FILES=	bin/qgo share/applications/qgo.desktop share/pixmaps/qgo.png
PLIST_DIRSTRY=	share/applications

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e \
		'/Icon/s|=.*|=${PREFIX}/share/pixmaps/qgo.png| ; \
		 /^MimeType/s|=.*|=text/sgf|' ${WRKSRC}/src/qgo.desktop
	@${REINPLACE_CMD} -e \
		's|debug|release|' ${WRKSRC}/src/src.pro
	@${REINPLACE_CMD} -e \
		's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/src/mainwindow_settings.cpp

do-configure:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} ${QMAKEFLAGS})

do-install:
	(cd ${WRKSRC}/bin && ${INSTALL_PROGRAM} qgo ${PREFIX}/bin)
	@${MKDIR} ${DESKTOPDIR}
	(cd ${WRKSRC}/src && ${INSTALL_DATA} qgo.desktop ${DESKTOPDIR})
	(cd ${WRKSRC}/src/ressources/pics && ${INSTALL_DATA} qgo.png \
		${PREFIX}/share/pixmaps)

.include <bsd.port.mk>
