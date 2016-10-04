# Created by: loïc bartoletti <lbartoletti@tuxfamily.org>
# $FreeBSD$

PORTNAME=	sqlitebrowser
PORTVERSION=	3.9.1
DISTVERSIONPREFIX=	v
CATEGORIES=	databases

MAINTAINER=	lbartoletti@tuxfamily.org
COMMENT=	Visual tool to manage SQLite databases

LICENSE=	MPL GPLv3
LICENSE_COMB=	dual

BUILD_DEPENDS=	${LOCALBASE}/lib/libantlr.a:devel/antlr

CONFLICTS_INSTALL?=	${PORTNAME}-qt5-*

USE_GITHUB=	yes

USES=		cmake desktop-file-utils sqlite

.if empty(PKGNAMESUFFIX)
CMAKE_ARGS+=	-DUSE_QT5:BOOL=FALSE
USE_QT4=	corelib network gui qmake_build linguisttools_build \
		moc_build uic_build rcc_build
.else
CMAKE_ARGS+=	-DUSE_QT5:BOOL=TRUE
USE_QT5=	core gui network printsupport testlib widgets \
		buildtools_build linguisttools_build qmake_build
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' \
		${WRKSRC}/src/PreferencesDialog.cpp
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' \
		${WRKSRC}/src/Application.cpp

.include <bsd.port.mk>
