PORTNAME=	designerplugin
PORTVERSION=	${QSCI2_VERSION}
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITES_QSCI2}
PKGNAMEPREFIX=	qscintilla2-
PKGNAMESUFFIX=	-${FLAVOR}
DISTNAME=	${QSCI2_DISTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt${FLAVOR:S/qt//} Designer plugin for QScintilla2
WWW=		https://riverbankcomputing.com/software/qscintilla/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC:H}/LICENSE

LIB_DEPENDS=	libqscintilla2_${FLAVOR}.so:devel/qscintilla2@${FLAVOR}

FLAVORS=	qt5 qt6
FLAVOR?=	qt5

USES=		compiler:c++11-lang gl pyqt:5 qmake qt:${FLAVOR:S/qt//}
_USE_GL_qt5=	gl
_USE_GL_qt6=	gl opengl
USE_GL=		${_USE_GL_${FLAVOR}}
_USE_QT_qt5=	core designer printsupport gui widgets xml \
		buildtools:build qmake:build
_USE_QT_qt6=	base tools
USE_QT=		${_USE_QT_${FLAVOR}}

WRKSRC=		${WRKDIR}/${DISTNAME}/designer

DISTINFO_FILE=	${.CURDIR:H}/qscintilla2/distinfo
PLIST_FILES=	%%QT_PLUGINDIR%%/designer/libqscintillaplugin.so

.include <bsd.port.mk>
