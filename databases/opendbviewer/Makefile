PORTNAME=	opendbviewer
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.0
PORTREVISION=	3
CATEGORIES=	databases

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple database explorer
WWW=		https://github.com/Jet1oeil/opendbviewer

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake gl magick:build qt:6 xorg
USE_GITHUB=	yes
GH_ACCOUNT=	Jet1oeil
USE_GL=		egl
USE_QT=		base sqldriver-sqlite:run tools:build
USE_XORG=	x11 xcb

CMAKE_ARGS+=	-DQT_USE_VERSION=6

OPTIONS_DEFINE=		DOCS MYSQL PGSQL
OPTIONS_DEFAULT=	PGSQL

MYSQL_USE=	QT=sqldriver-mysql:run
PGSQL_USE=	QT=sqldriver-psql:run

.include <bsd.port.mk>
