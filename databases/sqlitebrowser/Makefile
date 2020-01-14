# Created by: loïc bartoletti <lbartoletti@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sqlitebrowser
PORTVERSION=	3.11.2
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	databases

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Visual tool to manage SQLite databases

LICENSE=	MPL20 GPLv3
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/lib/libantlr.a:devel/antlr
LIB_DEPENDS=	libqscintilla2_qt5.so:devel/qscintilla2-qt5

USES=		compiler:c++11-lang cmake desktop-file-utils gnome qt:5 sqlite
CMAKE_ARGS+=	-DQT_INCLUDE_DIR=${QT_INCDIR} -DQT_LIBRARY_DIR=${QT_LIBDIR}
USE_QT=		core concurrent gui network printsupport testlib widgets \
		buildtools_build linguisttools_build qmake_build xml
USE_GITHUB=	yes

INSTALLS_ICONS=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' \
		${WRKSRC}/src/PreferencesDialog.cpp
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' \
		${WRKSRC}/src/Application.cpp

.include <bsd.port.mk>
