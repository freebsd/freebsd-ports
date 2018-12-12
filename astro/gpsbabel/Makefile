# Created by: Laurent Courty
# $FreeBSD$

PORTNAME=	gpsbabel
DISTVERSIONPREFIX=	${PORTNAME}_
DISTVERSION=	1_5_4
PORTREVISION=	1
CATEGORIES=	astro geography

MAINTAINER=	dev2@heesakkers.info
COMMENT=	GPS file translating tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

# Unbundle libminizip
LIB_DEPENDS=	libminizip.so:archivers/minizip

USE_GITHUB=	yes

CONFLICTS=	gpsbabel14-[0-9]*

USES=		compiler:c++11-lang localbase qt:5 qt:5
USE_QT=		core qmake_build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-zlib=system

OPTIONS_DEFINE=	GUI
OPTIONS_SUB=	yes

GUI_ALL_TARGET=	gui
GUI_USES=	qt:5 qt:5
GUI_USE=	QT=gui,xml,network,webkit
GUI_USE+=	QT=linguisttools_build,moc_build,rcc_build,uic_build
GUI_VARS=	MAKE_JOBS_UNSAFE=yes

post-patch:
	@${REINPLACE_CMD} '/langPath_ = / \
		s|QApplication::applicationDirPath()|"${DATADIR}"|' \
			${WRKSRC}/gui/mainwindow.cc
	@${RM} -r ${WRKSRC}/zlib/contrib/minizip

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gpsbabel ${STAGEDIR}${PREFIX}/bin/

do-install-GUI-on:
	${INSTALL_PROGRAM} ${WRKSRC}/gui/objects/gpsbabelfe-bin \
		${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/gui/gpsbabel.desktop \
		${STAGEDIR}${PREFIX}/share/applications/
	${MKDIR} ${STAGEDIR}${DATADIR}/translations
	${INSTALL_DATA} ${WRKSRC}/gui/*.qm ${STAGEDIR}${DATADIR}/translations/
	${INSTALL_DATA} ${WRKSRC}/gui/images/appicon.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/gpsbabel.png

.include <bsd.port.mk>
