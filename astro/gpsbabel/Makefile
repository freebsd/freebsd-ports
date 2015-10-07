# Created by: Laurent Courty
# $FreeBSD$

PORTNAME=	gpsbabel
PORTVERSION=	1.5.2
PORTREVISION=	1
CATEGORIES=	astro geography
MASTER_SITES=	https://secure.ohos.nl/downloads/ \
		LOCAL/glebius

MAINTAINER=	dev2@heesakkers.info
COMMENT=	GPS file translating tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	gpsbabel14-[0-9]*

USE_QT4=	corelib qmake_build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-zlib=system

OPTIONS_DEFINE=	GUI
OPTIONS_SUB=	GUI

GUI_ALL_TARGET=	gui
GUI_USE=	QT4=gui,xml,network,webkit
GUI_USE+=	QT4=linguisttools_build,moc_build,rcc_build,uic_build

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGUI}
MAKE_JOBS_UNSAFE=	yes
.endif

post-patch:
	@${REINPLACE_CMD} '/langPath_ = / \
		s|QApplication::applicationDirPath()|"${DATADIR}"|' \
			${WRKSRC}/gui/mainwindow.cc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gpsbabel ${STAGEDIR}${PREFIX}/bin/
.if ${PORT_OPTIONS:MGUI}
	${INSTALL_PROGRAM} ${WRKSRC}/gui/objects/gpsbabelfe-bin \
		${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/gui/gpsbabel.desktop \
		${STAGEDIR}${PREFIX}/share/applications/
	${MKDIR} ${STAGEDIR}${DATADIR}/translations
	${INSTALL_DATA} ${WRKSRC}/gui/*.qm ${STAGEDIR}${DATADIR}/translations/
	${INSTALL_DATA} ${WRKSRC}/gui/images/appicon.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/gpsbabel.png
.endif

.include <bsd.port.mk>
