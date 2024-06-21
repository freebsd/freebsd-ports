PORTNAME=	opendbviewer
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.0
CATEGORIES=	databases

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Simple database explorer
WWW=		https://github.com/Jet1oeil/opendbviewer

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake gl magick:build qt:5 xorg
USE_GITHUB=	yes
GH_ACCOUNT=	Jet1oeil
USE_GL=		egl
USE_QT=		core dbus gui network sql sql-sqlite3 testlib widgets \
		buildtools:build linguisttools:build qmake:build
USE_XORG=	x11 xcb

OPTIONS_DEFINE=		DOCS MYSQL PGSQL
OPTIONS_DEFAULT=	PGSQL

MYSQL_USE=	QT=sql-mysql
PGSQL_USE=	QT=sql-pgsql

.include <bsd.port.mk>
