# Created by: Danny Pansters <danny@ricin.com>
# $FreeBSD$

PORTNAME=	qscintilla2
PORTVERSION=	${QSCI2_VERSION}
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITES_QSCI2}
DISTNAME=	${QSCI2_DISTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 4 port of the Scintilla C++ editor class

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

USES=		compiler:c++11-lib qmake pyqt:4 qt:4
USE_PYQT=	#
USE_QT=		moc_build corelib gui xml designer
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

BUILD_WRKSRC=		${WRKSRC}/Qt4Qt5
CONFIGURE_WRKSRC=	${BUILD_WRKSRC}
INSTALL_WRKSRC=		${BUILD_WRKSRC}

QMAKE_ARGS=	DEFINES=QT_NO_ACCESSIBILITY

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES NLS
OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

post-patch:
	cd ${BUILD_WRKSRC} && ${REINPLACE_CMD} -e \
		's|$$$$\[QT_INSTALL_HEADERS\]|${PREFIX}/${QT_INCDIR_REL}|; \
		s|$$$$\[QT_INSTALL_LIBS\]|${PREFIX}/${QT_LIBDIR_REL}|; \
		s|$$$$\[QT_INSTALL_TRANSLATIONS\]|${PREFIX}/share/qt4/translations|; \
		s|$$$$\[QT_INSTALL_DATA\]|${PREFIX}/share/qt4|' \
		qscintilla.pro

.if empty(PORT_OPTIONS:MNLS)
	cd ${BUILD_WRKSRC} && ${REINPLACE_CMD} -e \
		's|trans qsci|qsci|' qscintilla.pro
.endif

post-install:
	cd ${WRKSRC} &&\
		${MKDIR} ${STAGEDIR}${DOCSDIR}/html ${STAGEDIR}${DOCSDIR}/Scintilla &&\
		${INSTALL_DATA} NEWS README ${STAGEDIR}${DOCSDIR} &&\
		${INSTALL_DATA} doc/html-Qt4Qt5/* ${STAGEDIR}${DOCSDIR}/html &&\
		${INSTALL_DATA} doc/Scintilla/* ${STAGEDIR}${DOCSDIR}/Scintilla
	cd ${WRKSRC}/example-Qt4Qt5 &&\
		${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/images &&\
		${INSTALL_DATA} *.* ${STAGEDIR}${EXAMPLESDIR} &&\
		${INSTALL_DATA} images/* ${STAGEDIR}${EXAMPLESDIR}/images

.include <bsd.port.mk>
