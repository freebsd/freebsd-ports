# $FreeBSD$

PORTNAME=	qbs
PORTVERSION=	1.5.1
DISTVERSIONPREFIX=	src-
CATEGORIES=	devel
MASTER_SITES=	QT/official_releases/${PORTNAME}/${PORTVERSION}
DIST_SUBDIR=	KDE/Qt/qbs

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt Build Suite

LICENSE=	GPLv3 LGPL21
LICENSE_COMB=	dual

USES=		compiler:c++11-lib qmake:outsource
USE_LDCONFIG=	yes
USE_QT5=	buildtools_build concurrent gui script testlib widgets xml

QMAKE_SOURCE_PATH=	${WRKSRC}/qbs.pro

OPTIONS_DEFINE=		DOCS
DOCS_USE=		QT5=help_build,qdoc_build,sql-sqlite3_build
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

ALL_TARGET=		all
INSTALL_TARGET=		install

DOCS_ALL_TARGET=	docs
DOCS_INSTALL_TARGET=	install_docs

.include <bsd.port.mk>
