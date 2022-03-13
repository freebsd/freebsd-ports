PORTNAME=	LibreMines
PORTVERSION=	1.9.1
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Free/Libre and Open Source Software Qt based Minesweeper

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake qt:5
USE_QT=		buildtools_build core gui multimedia qmake_build svg widgets

USE_GITHUB=	yes
GH_ACCOUNT=	Bollos00

PLIST_FILES=	bin/libremines \
		share/applications/libremines.desktop \
		share/icons/hicolor/scalable/apps/libremines.svg

.include <bsd.port.mk>
