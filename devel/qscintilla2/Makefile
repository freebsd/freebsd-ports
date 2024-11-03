PORTNAME=	qscintilla2
PORTVERSION=	${QSCI2_VERSION}
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITES_QSCI2}
PKGNAMESUFFIX=	-${FLAVOR}
DISTNAME=	${QSCI2_DISTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt${FLAVOR:S/qt//} port of the Scintilla C++ editor class
WWW=		https://riverbankcomputing.com/software/qscintilla/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

FLAVORS=	qt5 qt6
FLAVOR?=	qt5

USES=		compiler:c++11-lang gl qmake pyqt:5 qt:${FLAVOR:S/qt//}
_USE_GL_qt5=	gl
_USE_GL_qt6=	gl opengl
USE_GL=		${_USE_GL_${FLAVOR}}
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}
USE_PYQT=	#
_USE_QT_qt5=	buildtools:build core gui printsupport widgets
_USE_QT_qt6=	base
USE_QT=		${_USE_QT_${FLAVOR}}

DATADIR=	${PREFIX}/share/${PORTNAME}-${FLAVOR}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${FLAVOR}
EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}-${FLAVOR}

BUILD_WRKSRC=		${WRKSRC}/src
CONFIGURE_WRKSRC=	${BUILD_WRKSRC}
INSTALL_WRKSRC=		${BUILD_WRKSRC}

PLIST_SUB=	QT_MAJOR_VERSION=${FLAVOR:S/qt//}
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES NLS
OPTIONS_SUB=	yes

post-patch-NLS-off:
	cd ${BUILD_WRKSRC} && ${REINPLACE_CMD} -e \
		's|trans qsci|qsci|' qscintilla.pro

post-install:
	cd ${WRKSRC} &&\
		${MKDIR} ${STAGEDIR}${DOCSDIR}/html ${STAGEDIR}${DOCSDIR}/Scintilla &&\
		${INSTALL_DATA} NEWS ${STAGEDIR}${DOCSDIR} &&\
		${INSTALL_DATA} doc/html/* ${STAGEDIR}${DOCSDIR}/html &&\
		${INSTALL_DATA} doc/Scintilla/* ${STAGEDIR}${DOCSDIR}/Scintilla
	cd ${WRKSRC}/example &&\
		${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/images &&\
		${INSTALL_DATA} *.* ${STAGEDIR}${EXAMPLESDIR} &&\
		${INSTALL_DATA} images/* ${STAGEDIR}${EXAMPLESDIR}/images

.include <bsd.port.mk>
