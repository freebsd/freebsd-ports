# $FreeBSD$

PORTNAME=	qbs
PORTVERSION=	1.4.5
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

.include <bsd.port.mk>
