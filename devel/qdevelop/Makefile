# New ports collection makefile for:	qdevelop
# Date created:				4 Jul 2007
# Whom:					Yinghong.Liu <liu_yinghong@yahoo.com.cn>
#
# $FreeBSD$
#

PORTNAME=	qdevelop
PORTVERSION=	0.23.1
PORTREVISION=	1
CATEGORIES=	devel kde
MASTER_SITES=	http://qdevelop.org/download/ \
		ftp://local-distfiles.freebsd.org.cn/pub/china-ports/hamigua/
DISTNAME=	QDevelop-${PORTVERSION:C/.([0-9])$/-\1/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A development environment entirely dedicated to Qt4

BUILD_DEPENDS=	cmake:${PORTSDIR}/devel/cmake
RUN_DEPENDS=	exctags:${PORTSDIR}/devel/ctags \
		qt4-sqlite-plugin>=0:${PORTSDIR}/databases/qt4-sqlite3-plugin

BROKEN=		checksum fails

CMAKE_ARGS=	-DCMAKE_BUILD_TYPE:STRING=Release \
		-DCMAKE_C_COMPILER:STRING='${CC}' \
		-DCMAKE_CXX_COMPILER:STRING=${CXX} \
		-DCMAKE_CXX_FLAGS:STRING="${CXXFLAGS} -pthread" \
		-DCMAKE_INSTALL_PREFIX=${PREFIX}

USE_ZIP=	yes
USE_QT_VER=	4
QT_COMPONENTS=	qmake moc uic rcc sql network xml gui corelib assistant linguist designer

DESKTOP_ENTRIES=	"QDevelop" \
			"A development environment entirely dedicated to Qt4" \
			"QDevelop" \
			"QDevelop" \
			"Qt;KDE;Development;" \
			"false"

.if !defined(WITHOUT_NLS)
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|\"qmake\"|\"qmake-qt4\"|g" \
		-e "s|\"linguist\"|\"linguist-qt4\"|g" \
		-e "s|\"lupdate\"|\"lupdate-qt4\"|g" \
		-e "s|\"lrelease\"|\"lrelease-qt4\"|g" \
		-e "s|\"designer\"|\"designer-qt4\"|g" \
		-e "s|\"assistant\"|\"assistant-qt4\"|g" \
		-e "s|\"/usr/bin/make\"|\"${LOCALBASE}/bin/gmake\"|g" \
		-e "s|\"/usr/bin/ctags\"|\"${LOCALBASE}/bin/exctags\"|g" \
		${WRKSRC}/src/toolscontrolimpl.cpp

do-configure:
	@(cd ${WRKSRC}; \
	${SETENV} ${CONFIGURE_ENV} ${LOCALBASE}/bin/cmake ${CMAKE_ARGS} ${WRKSRC})

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/QDevelop ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/resources/images/logo.png ${PREFIX}/share/pixmaps/QDevelop.png
.if !defined(WITHOUT_NLS)
	@${MKDIR} ${DATADIR}
	(cd ${WRKSRC}/resources/translations/ && ${COPYTREE_SHARE} '*.qm' ${DATADIR}/translations)
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ChangeLog.txt README.txt README.cmake copying
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
