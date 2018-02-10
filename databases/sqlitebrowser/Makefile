# Created by: loïc bartoletti <lbartoletti@tuxfamily.org>
# $FreeBSD$

PORTNAME=	sqlitebrowser
PORTVERSION=	3.10.1
DISTVERSIONPREFIX=	v
CATEGORIES=	databases

MAINTAINER=	lbartoletti@tuxfamily.org
COMMENT=	Visual tool to manage SQLite databases

LICENSE=	MPL20 GPLv3
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/lib/libantlr.a:devel/antlr

USES=		cmake desktop-file-utils sqlite
CMAKE_ARGS+=	-DUSE_QT5:BOOL=TRUE
USE_QT5=	core gui network printsupport testlib widgets \
		buildtools_build linguisttools_build qmake_build
USE_GITHUB=	yes

INSTALLS_ICONS=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' \
		${WRKSRC}/src/PreferencesDialog.cpp
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' \
		${WRKSRC}/src/Application.cpp

.include <bsd.port.mk>
