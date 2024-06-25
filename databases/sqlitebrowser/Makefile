PORTNAME=	sqlitebrowser
PORTVERSION=	3.12.2
DISTVERSIONPREFIX=	v
CATEGORIES=	databases

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Visual tool to manage SQLite databases
WWW=		https://sqlitebrowser.org/

LICENSE=	MPL20 GPLv3
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/lib/libantlr.a:devel/antlr
LIB_DEPENDS=	libqscintilla2_qt5.so:devel/qscintilla2-qt5

USES=		cmake desktop-file-utils gnome qt:5 sqlite
USE_QT=		core concurrent gui network printsupport testlib widgets \
		buildtools:build linguisttools:build qmake:build xml
USE_GITHUB=	yes

PORTSCOUT=	ignore:1

post-patch:
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' \
		${WRKSRC}/src/PreferencesDialog.cpp ${WRKSRC}/src/Application.cpp
	@${REINPLACE_CMD} -e 's|metainfo|appdata|' \
		${WRKSRC}/src/src.pro ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
