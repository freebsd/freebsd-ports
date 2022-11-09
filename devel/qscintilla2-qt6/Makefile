PORTNAME=	qscintilla2-qt6
PORTVERSION=	${QSCI2_VERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITES_QSCI2}
DISTNAME=	${QSCI2_DISTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 6 port of the Scintilla C++ editor class
WWW=		http://www.riverbankcomputing.co.uk/software/qscintilla/

USES=		compiler:c++11-lang gl qmake pyqt:6 qt:6
USE_GL=		gl
USE_PYQT=	#
USE_QT=		base
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

BUILD_WRKSRC=		${WRKSRC}/src
CONFIGURE_WRKSRC=	${BUILD_WRKSRC}
INSTALL_WRKSRC=		${BUILD_WRKSRC}

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES NLS
OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

post-patch:
.if empty(PORT_OPTIONS:MNLS)
	cd ${BUILD_WRKSRC} && ${REINPLACE_CMD} -e \
		's|trans qsci|qsci|' qscintilla.pro
.endif

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
