# New ports collection makefile for:	qscintilla2
# Date created:				2007-02-08
# Whom:					Danny Pansters <danny@ricin.com>
#
# $FreeBSD$

PORTNAME=	qscintilla2
PORTVERSION=	2.1
PORTEPOCH=	1
PORTREVISION=	# zero
CATEGORIES=	devel

MASTER_SITES=	http://www.riverbankcomputing.com/Downloads/QScintilla2/ \
		http://freebsd.ricin.com/ports/distfiles/
DISTNAME=	QScintilla-1.73-gpl-${PORTVERSION}

MAINTAINER=	danny@ricin.com
COMMENT=	Qt4 port of the Scintilla C++ editor class

USE_QT_VER=	4
QT_COMPONENTS=	qmake moc gui xml designer
HAS_CONFIGURE=	yes

OPTIONS=	HEADERS		"Install Qsci headers" on \
		TRANSLATIONS	"Install translations (de, fr, pt_br, ru)" off

.include <bsd.port.pre.mk>

.if defined(WITHOUT_HEADERS)
PLIST_SUB+=	HEADERS="@comment "
.else
PLIST_SUB+=	HEADERS=""
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
		${MV} libqscintilla2.so.2.0.0 libqscintilla2.so.2 &&\
		${INSTALL_DATA} libqscintilla2.so.2 ${PREFIX}/lib &&\
		cd ${PREFIX}/lib &&\
		${LN} -sf libqscintilla2.so.2 libqscintilla2.so &&\
		cd ../share/qt4/qsci/api/python/ && ${RM} Python-2.4.api
.if !defined(NOPORTDOCS)
	cd ${WRKSRC} &&\
		${MKDIR} -m 0755 ${DOCSDIR}/html ${DOCSDIR}/Scintilla &&\
		${INSTALL_DATA} ChangeLog NEWS README ${DOCSDIR} &&\
		${INSTALL_DATA} doc/html-Qt4/* ${DOCSDIR}/html &&\
		${INSTALL_DATA} doc/Scintilla/* ${DOCSDIR}/Scintilla
.endif
.if !defined(NOPORTEXAMPLES)
	cd ${WRKSRC}/example-Qt4 &&\
		${MKDIR} -m 0755 ${EXAMPLESDIR}/images &&\
		${INSTALL_DATA} *.* ${EXAMPLESDIR} &&\
		${INSTALL_DATA} images/* ${EXAMPLESDIR}/images
.endif
.include <bsd.port.post.mk>
