# Created by: Laurent Courty
# $FreeBSD$

PORTNAME=	gpsbabel
DISTVERSIONPREFIX=	${PORTNAME}_
DISTVERSION=	1_6_0
CATEGORIES=	astro geography

MAINTAINER=	dev2@heesakkers.info
COMMENT=	GPS file translating tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lang gmake localbase qt:5
USE_QT=		core qmake_build

CONFLICTS=	gpsbabel14-[0-9]*

USE_GITHUB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-zlib=system

OPTIONS_DEFINE=	GUI
OPTIONS_SUB=	yes

GUI_ALL_TARGET=	gui
GUI_USE=	QT=qmake_build,gui,xml,network,webkit
GUI_USE+=	QT=linguisttools_build,webengine,buildtools
GUI_VARS=	MAKE_JOBS_UNSAFE=yes
GUI_QMAKE_SOURCE_PATH=	${WRKSRC}/gui

do-build:
	(cd ${WRKSRC}; ${CONFIGURE_CMD} --with-zlib-system; ${GMAKE})
do-build-GUI-on:
	(cd ${WRKSRC}/gui; ${QMAKE} USE_GUI=qt5; ${LRELEASE} *.ts; ${GMAKE})

post-patch:
	@${REINPLACE_CMD} '/langPath_ = / \
		s|QApplication::applicationDirPath()|"${DATADIR}"|' \
			${WRKSRC}/gui/mainwindow.cc
	@${RM} -r ${WRKSRC}/zlib/contrib/minizip

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gpsbabel ${STAGEDIR}${PREFIX}/bin/

do-install-GUI-on:
	${INSTALL_PROGRAM} ${WRKSRC}/gui/objects/gpsbabelfe \
		${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/gui/gpsbabel.desktop \
		${STAGEDIR}${PREFIX}/share/applications/
	${MKDIR} ${STAGEDIR}${DATADIR}/translations
	${INSTALL_DATA} ${WRKSRC}/gui/*.qm ${STAGEDIR}${DATADIR}/translations/
	${INSTALL_DATA} ${WRKSRC}/gui/images/appicon.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/gpsbabel.png

.include <bsd.port.mk>
