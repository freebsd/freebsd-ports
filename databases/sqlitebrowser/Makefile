# Created by: loïc bartoletti <coder@tuxfamily.org>
# $FreeBSD$

PORTNAME=	sqlitebrowser
PORTVERSION=	3.8.0
DISTVERSIONPREFIX=	v
CATEGORIES=	databases

MAINTAINER=	coder@tuxfamily.org
COMMENT=	DB Browser for SQLite is a visual tool to manage SQLite databases

LICENSE=	MPL GPLv3
LICENSE_COMB=	dual

USE_GITHUB=	yes

USES=		cmake desktop-file-utils sqlite
USE_QT4=	corelib network gui qmake_build linguisttools_build \
		moc_build uic_build rcc_build

INSTALLS_ICONS=	yes

post-patch:
	@${ECHO} ${DATADIR}
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' \
		${WRKSRC}/src/PreferencesDialog.cpp
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' \
		${WRKSRC}/src/Application.cpp

.include <bsd.port.mk>
