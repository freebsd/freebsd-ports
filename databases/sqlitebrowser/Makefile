PORTNAME=	sqlitebrowser
DISTVERSIONPREFIX=	v
DISTVERSION=	3.13.1
PORTREVISION=	1
CATEGORIES=	databases

MAINTAINER=	mce@FreeBSD.org
COMMENT=	Visual tool to manage SQLite databases
WWW=		https://sqlitebrowser.org/

LICENSE=	GPLv3+ MPL20
LICENSE_COMB=	dual
LICENSE_FILE_GPLv3+ =	${WRKSRC}/LICENSE-GPL-3.0
LICENSE_FILE_MPL20=	${WRKSRC}/LICENSE-MPL-2.0

LIB_DEPENDS=	libQCustomPlot-qt5.so:graphics/qcustomplot@qt5 \
		libqscintilla2_qt5.so:devel/qscintilla2@qt5

USES=		cmake:testing compiler:c++14-lang desktop-file-utils gnome qt:5
USE_GITHUB=	yes
USE_QT=		core concurrent gui network printsupport testlib widgets \
		buildtools:build linguisttools:build qmake:build xml

CMAKE_ARGS=	-DFORCE_INTERNAL_QCUSTOMPLOT=OFF \
		-DQCustomPlot_LIBRARY=${LOCALBASE}/lib/libQCustomPlot-qt5.so \
		-DQSCINTILLA_INCLUDE_DIR=${QT_INCDIR}/Qsci \
		-DQSCINTILLA_LIBRARY=${QT_LIBDIR}/libqscintilla2_qt5.so
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
