# $FreeBSD$

PORTNAME=	opendbviewer
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	databases

MAINTAINER=	lbartoletti@tuxfamily.org
COMMENT=	Simple database explorer

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	convert:graphics/ImageMagick6

USES=		cmake:outsource compiler:c++11-lang qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	Jet1oeil
USE_QT=		core gui network sql sql-sqlite3 testlib widgets \
		buildtools_build linguisttools_build qmake_build

OPTIONS_DEFINE=		DOCS PGSQL MYSQL
OPTIONS_DEFAULT=	PGSQL

PGSQL_USE=	QT=sql-pgsql
MYSQL_USE=	QT=sql-mysql

.include <bsd.port.mk>
