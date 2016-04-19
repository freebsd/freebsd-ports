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

USES=		desktop-file-utils qmake tar:bzip2
USE_QT4=	gui network qtestlib moc_build rcc_build uic_build

PLIST_FILES=	bin/qgo share/applications/qgo.desktop share/pixmaps/qgo.png

post-patch:
	@${REINPLACE_CMD} -e \
		'/Icon/s|=.*|=${PREFIX}/share/pixmaps/qgo.png| ; \
		 /^MimeType/s|=.*|=text/sgf|' ${WRKSRC}/src/qgo.desktop
	@${REINPLACE_CMD} -e \
		's|debug|release|' ${WRKSRC}/src/src.pro
	@${REINPLACE_CMD} -e \
		's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/src/mainwindow_settings.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/qgo ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/src/qgo.desktop ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/src/ressources/pics/qgo.png \
		${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
