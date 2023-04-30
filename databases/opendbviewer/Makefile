PORTNAME=	opendbviewer
PORTVERSION=	1.1.1
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	databases

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple database explorer
WWW=		https://github.com/Jet1oeil/opendbviewer

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang magick:6,build qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	Jet1oeil
USE_QT=		core gui network sql sql-sqlite3 testlib widgets \
		buildtools:build linguisttools:build qmake:build

OPTIONS_DEFINE=		DOCS PGSQL MYSQL
OPTIONS_DEFAULT=	PGSQL

PGSQL_USE=	QT=sql-pgsql
MYSQL_USE=	QT=sql-mysql

CMAKE_ARGS+=	-DCMAKE_CXX_STANDARD=11

.include <bsd.port.mk>
