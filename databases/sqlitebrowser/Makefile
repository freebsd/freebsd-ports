# Created by: loïc bartoletti <coder@tuxfamily.org>
# $FreeBSD$

PORTNAME=	sqlitebrowser
PORTVERSION=	3.8.0
DISTVERSIONPREFIX=	v
PORTREVISION?=	1
CATEGORIES=	databases

MAINTAINER=	coder@tuxfamily.org
COMMENT=	DB Browser for SQLite is a visual tool to manage SQLite databases

CONFLICTS_INSTALL?=	${PORTNAME}-qt5-*

LICENSE=	MPL GPLv3
LICENSE_COMB=	dual

USE_GITHUB=	yes

USES=		cmake desktop-file-utils sqlite

.if empty(PKGNAMESUFFIX)
USE_QT4=	corelib network gui qmake_build linguisttools_build \
		moc_build uic_build rcc_build
CMAKE_ARGS+=	-DUSE_QT5:BOOL=FALSE
.else
USE_QT5=	core gui network printsupport testlib widgets \
		buildtools_build linguisttools_build qmake_build
CMAKE_ARGS+=	-DUSE_QT5:BOOL=TRUE
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' \
		${WRKSRC}/src/PreferencesDialog.cpp
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' \
		${WRKSRC}/src/Application.cpp

.include <bsd.port.mk>
