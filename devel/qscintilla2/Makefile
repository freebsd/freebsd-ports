# New ports collection makefile for:	qscintilla2
# Date created:				2007-02-08
# Whom:					Danny Pansters <danny@ricin.com>
#
# $FreeBSD$

PORTNAME=	qscintilla2
PORTVERSION=	20070318
CATEGORIES=	devel
MASTER_SITES=	http://www.riverbankcomputing.com/Downloads/Snapshots/QScintilla2/ \
		http://freebsd.ricin.com/ports/distfiles/
DISTNAME=	QScintilla-1.72-gpl-2-snapshot-${PORTVERSION}

MAINTAINER=	danny@ricin.com
COMMENT=	Qt4 port of the Scintilla C++ editor class

USE_QT_VER=	4
QT_COMPONENTS=	qmake moc gui
USE_LDCONFIG=	yes
HAS_CONFIGURE=	yes
NO_FILTER_SHLIBS=	yes

OPTIONS=	DOCS 		"Install documentation" on \
		EXAMPLES	"Install example" on \
		HEADERS		"Install Qsci headers" on \
		TRANSLATIONS	"Install translations (de, fr, pt_br, ru)" off

.include <bsd.port.pre.mk>

.if defined(NOPORTDOCS) || defined(WITHOUT_DOCS)
PLIST_SUB+=	DOCS="@comment "
.else
PLIST_SUB+=	DOCS=""
.endif
.if defined(NOPORTDOCS) || defined(WITHOUT_EXAMPLES)
PLIST_SUB+=	EXAMPLES="@comment "
.else
PLIST_SUB+=	EXAMPLES=""
.endif
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
	( cd ${WRKSRC}/Qt4 && ${REINPLACE_CMD} -e \
		's|$$$$\[QT_INSTALL_LIBS\]|${WRKSRC}/lib|' qscintilla.pro )
.if defined(WITHOUT_HEADERS)
	( cd ${WRKSRC}/Qt4 && ${REINPLACE_CMD} -e \
		's|header trans qsci|trans qsci|' qscintilla.pro )
.endif
.if !defined(WITH_TRANSLATIONS)
	( cd ${WRKSRC}/Qt4 && ${REINPLACE_CMD} -e \
		's|trans qsci|qsci|' qscintilla.pro )
.endif

do-configure:
	( cd ${WRKSRC}/Qt4 && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} -unix PREFIX=${PREFIX} qscintilla.pro )

do-build:
	( cd ${WRKSRC}/Qt4 && ${MAKE} )

do-install:
	( cd ${WRKSRC}/Qt4 && ${MAKE} install )
	( cd ${WRKSRC}/lib && \
		${MV} libqscintilla2.so.1.0.0 libqscintilla2.so.1 && \
		${INSTALL_DATA} libqscintilla2.so.1 ${PREFIX}/lib && \
		cd ${PREFIX}/lib && \
		${LN} -sf libqscintilla2.so.1 libqscintilla2.so )
.if !defined(NOPORTDOCS) && !defined(WITHOUT_DOCS)
	( cd ${WRKSRC} && \
		${MKDIR} -m 0755 ${DOCSDIR}/html ${DOCSDIR}/Scintilla && \
		${INSTALL_DATA} ChangeLog NEWS README ${DOCSDIR} && \
		${INSTALL_DATA} doc/html-Qt4/* ${DOCSDIR}/html && \
		${INSTALL_DATA} doc/Scintilla/* ${DOCSDIR}/Scintilla )
.endif
.if !defined(NOPORTDOCS) && !defined(WITHOUT_EXAMPLES)
	( cd ${WRKSRC}/example-Qt4 && \
		${MKDIR} -m 0755 ${EXAMPLESDIR}/images && \
		${INSTALL_DATA} *.* ${EXAMPLESDIR} && \
		${INSTALL_DATA} images/* ${EXAMPLESDIR}/images )
.endif

.include <bsd.port.post.mk>
