PORTNAME=	sqlitebrowser
DISTVERSIONPREFIX=	v
DISTVERSION=	3.13.99
CATEGORIES=	databases

MAINTAINER=	mce@FreeBSD.org
COMMENT=	Visual tool to manage SQLite databases
WWW=		https://sqlitebrowser.org/

LICENSE=	GPLv3+ MPL20
LICENSE_COMB=	dual
LICENSE_FILE_GPLv3+ =	${WRKSRC}/LICENSE-GPL-3.0
LICENSE_FILE_MPL20=	${WRKSRC}/LICENSE-MPL-2.0

LIB_DEPENDS=	libQCustomPlotQt6.so:graphics/qcustomplot@qt6 \
		libqhexedit.so:editors/qhexedit2 \
		libqscintilla2_qt6.so:devel/qscintilla2@qt6

USES=		cmake:testing compiler:c++17-lang desktop-file-utils gl gnome \
		qt:6
USE_GITHUB=	yes
GH_TAGNAME=	9ccf5501ad00bbdb1b592894936cbc7ca76229f5
USE_GL=		opengl
USE_QT=		5compat base tools:build

CMAKE_ARGS=	-DFORCE_INTERNAL_QCUSTOMPLOT=OFF \
		-DFORCE_INTERNAL_QHEXEDIT=OFF \
		-DQCustomPlot_LIBRARY=${LOCALBASE}/lib/libQCustomPlotQt6.so \
		-DQHexEdit_INCLUDE_DIR=${QT_INCDIR}/qhexedit2 \
		-DQHexEdit_LIBRARY=${QT_LIBDIR}/libqhexedit.so \
		-DQSCINTILLA_INCLUDE_DIR=${QT_INCDIR}/Qsci \
		-DQSCINTILLA_LIBRARY=${QT_LIBDIR}/libqscintilla2_qt6.so \
		-DQT_MAJOR=Qt6
CMAKE_TESTING_ARGS=	-DENABLE_TESTING=ON

OPTIONS_DEFINE=		SQLCIPHER
SQLCIPHER_DESC=		Support encrypted SQLite databases
SQLCIPHER_LIB_DEPENDS=	libsqlcipher.so:databases/sqlcipher
SQLCIPHER_USES_OFF=	sqlite
SQLCIPHER_CMAKE_ON=	-Dsqlcipher=ON
SQLCIPHER_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-src_SqlUiLexer.cpp

post-patch:
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' \
		${WRKSRC}/src/PreferencesDialog.cpp ${WRKSRC}/src/Application.cpp

.include <bsd.port.mk>
