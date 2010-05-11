# New ports collection makefile for:	qscintilla2
# Date created:				2007-02-08
# Whom:					Danny Pansters <danny@ricin.com>
#
# $FreeBSD$

PORTNAME=	qscintilla2
PORTVERSION=	${QSCI2_VERSION}
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITES_QSCI2}
DISTNAME=	${QSCI2_DISTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt4 port of the Scintilla C++ editor class

USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build gui xml designer
HAS_CONFIGURE=	yes
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

OPTIONS=	NLS "Build with NLS support" on

BUILD_WRKSRC=		${WRKSRC}/Qt4
INSTALL_WRKSRC=		${BUILD_WRKSRC}

QMAKE_ARGS=	-unix PREFIX=${PREFIX}

.include "../py-sip/files/bsd.pyqt.mk"
.include <bsd.port.options.mk>

.if !defined(WITHOUT_NLS)
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	cd ${BUILD_WRKSRC} && ${REINPLACE_CMD} -e \
		's|$$$$\[QT_INSTALL_HEADERS\]|${PREFIX}/${QT_INCDIR_REL}|; \
		s|$$$$\[QT_INSTALL_LIBS\]|${PREFIX}/${QT_LIBDIR_REL}|; \
		s|$$$$\[QT_INSTALL_TRANSLATIONS\]|${PREFIX}/share/qt4/translations|; \
		s|$$$$\[QT_INSTALL_DATA\]|${PREFIX}/share/qt4|' \
		qscintilla.pro

.if defined(WITHOUT_NLS)
	cd ${BUILD_WRKSRC} && ${REINPLACE_CMD} -e \
		's|trans qsci|qsci|' qscintilla.pro
.endif

do-configure:
	cd ${BUILD_WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} ${QMAKE_ARGS} qscintilla.pro

post-configure:
	${REINPLACE_CMD} -e \
		's|^CC .*|CC=${CC}|; \
		s|^CXX .*|CXX=${CXX}|; \
		s|^LINK .*|LINK=${CXX}|' \
		${BUILD_WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	cd ${WRKSRC} &&\
		${MKDIR} ${DOCSDIR}/html ${DOCSDIR}/Scintilla &&\
		${INSTALL_DATA} NEWS README ${DOCSDIR} &&\
		${INSTALL_DATA} doc/html-Qt4/* ${DOCSDIR}/html &&\
		${INSTALL_DATA} doc/Scintilla/* ${DOCSDIR}/Scintilla
.endif
.if !defined(NOPORTEXAMPLES)
	cd ${WRKSRC}/example-Qt4 &&\
		${MKDIR} ${EXAMPLESDIR}/images &&\
		${INSTALL_DATA} *.* ${EXAMPLESDIR} &&\
		${INSTALL_DATA} images/* ${EXAMPLESDIR}/images
.endif
.include <bsd.port.mk>
