# Created by: Danny Pansters <danny@ricin.com>
# $FreeBSD$

PORTNAME=	designerplugin
PORTVERSION=	${QSCI2_VERSION}
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITES_QSCI2}
PKGNAMEPREFIX=	qscintilla2-
DISTNAME=	${QSCI2_DISTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt4 Designer plugin for QScintilla2

LIB_DEPENDS=	libqscintilla2_qt4.so:devel/qscintilla2

DISTINFO_FILE=	${.CURDIR:H}/qscintilla2/distinfo
USES=		qmake pyqt:4
USE_QT4=	qmake_build moc_build gui xml designer

WRKSRC=		${WRKDIR}/${DISTNAME}/designer-Qt4Qt5

PLIST_FILES=	%%QT_PLUGINDIR%%/designer/libqscintillaplugin.so

pre-configure:
	${REINPLACE_CMD} -e \
		's|$$$$\[QT_INSTALL_PLUGINS\]|${PREFIX}/${QT_PLUGINDIR_REL}|' \
		${WRKSRC}/designer.pro

.include <bsd.port.mk>
