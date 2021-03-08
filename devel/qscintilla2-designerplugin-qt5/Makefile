# $FreeBSD$

PORTNAME=	designerplugin-qt5
PORTVERSION=	${QSCI2_VERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITES_QSCI2}
PKGNAMEPREFIX=	qscintilla2-
DISTNAME=	${QSCI2_DISTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt5 Designer plugin for QScintilla2

LIB_DEPENDS=	libqscintilla2_qt5.so:devel/qscintilla2-qt5

DISTINFO_FILE=	${.CURDIR:H}/qscintilla2-qt5/distinfo
USES=		compiler:c++11-lang qmake pyqt:5 qt:5 gl
USE_GL=		gl
USE_QT=		core designer printsupport gui widgets xml \
		buildtools_build qmake_build

WRKSRC=		${WRKDIR}/${DISTNAME}/designer

PLIST_FILES=	%%QT_PLUGINDIR%%/designer/libqscintillaplugin.so

.include <bsd.port.mk>
