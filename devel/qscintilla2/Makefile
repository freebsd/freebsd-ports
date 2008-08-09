# New ports collection makefile for:	qscintilla2
# Date created:				2007-02-08
# Whom:					Danny Pansters <danny@ricin.com>
#
# $FreeBSD$

PORTNAME=	qscintilla2
PORTVERSION=	${QSCI2_VERSION}
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	devel

MASTER_SITES=	${MASTER_SITES_QSCI2}
DISTNAME=	${QSCI2_DISTNAME}

MAINTAINER=	${PYQT_MAINTAINER}
COMMENT=	Qt4 port of the Scintilla C++ editor class

USE_QT_VER=	4
QT_COMPONENTS=	qmake moc gui xml designer
HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes

OPTIONS=	HEADERS		"Install Qsci headers" on \
		TRANSLATIONS	"Install translations (de, fr, pt_br, ru)" off

PLIST_SUB+=	QT_LIBDIR_REL=${QT_LIBDIR_REL}

.include "../py-sip/files/bsd.pyqt.mk"
.include <bsd.port.pre.mk>

.if defined(WITHOUT_HEADERS)
PLIST_SUB+=	HEADERS="@comment "
.else
PLIST_SUB+=	HEADERS=""
PLIST_SUB+=	QT_INCDIR_REL=${QT_INCDIR_REL}
.endif
.if defined(WITH_TRANSLATIONS)
PLIST_SUB+=	TRANSLATIONS=""
.else
PLIST_SUB+=	TRANSLATIONS="@comment "
.endif

post-patch:
	cd ${WRKSRC}/Qt4 && ${REINPLACE_CMD} -e \
		's|$$$$\[QT_INSTALL_LIBS\]|${WRKSRC}/lib|' qscintilla.pro
.if defined(WITHOUT_HEADERS)
	cd ${WRKSRC}/Qt4 && ${REINPLACE_CMD} -e \
		's|header trans qsci|trans qsci|' qscintilla.pro
.endif
.if !defined(WITH_TRANSLATIONS)
	cd ${WRKSRC}/Qt4 && ${REINPLACE_CMD} -e \
		's|trans qsci|qsci|' qscintilla.pro
.endif

do-configure:
	cd ${WRKSRC}/Qt4 && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} -unix PREFIX=${PREFIX} qscintilla.pro

do-build:
	cd ${WRKSRC}/Qt4 && ${MAKE}

do-install:
	cd ${WRKSRC}/Qt4 && ${MAKE} install
	cd ${WRKSRC}/lib &&\
		${MV} libqscintilla2.so.3.0.0 libqscintilla2.so.3 &&\
		${INSTALL_DATA} libqscintilla2.so.3 ${PREFIX}/${QT_LIBDIR_REL} &&\
		cd ${PREFIX}/${QT_LIBDIR_REL} &&\
		${LN} -sf libqscintilla2.so.3 libqscintilla2.so &&\
		${RM} ${PREFIX}/share/qt4/qsci/api/python/Python-2.4.api

.if !defined(NOPORTDOCS)
	cd ${WRKSRC} &&\
		${MKDIR} ${DOCSDIR}/html ${DOCSDIR}/Scintilla &&\
		${INSTALL_DATA} ChangeLog NEWS README ${DOCSDIR} &&\
		${INSTALL_DATA} doc/html-Qt4/* ${DOCSDIR}/html &&\
		${INSTALL_DATA} doc/Scintilla/* ${DOCSDIR}/Scintilla
.endif
.if !defined(NOPORTEXAMPLES)
	cd ${WRKSRC}/example-Qt4 &&\
		${MKDIR} ${EXAMPLESDIR}/images &&\
		${INSTALL_DATA} *.* ${EXAMPLESDIR} &&\
		${INSTALL_DATA} images/* ${EXAMPLESDIR}/images
.endif
.include <bsd.port.post.mk>
