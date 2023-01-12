PORTNAME=	kdevelop-pg-qt
DISTVERSION=	2.2.2
CATEGORIES=	devel kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${DISTVERSION}/src
DIST_SUBDIR=	KDE/kdevelop

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Parser-generator from KDevplatform
WWW=		https://techbase.kde.org/Development/KDevelop-PG-Qt_Introduction

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:textproc/flex

USES=		bison cmake compiler:c++11-lib kde:5 qt:5 tar:xz
USE_KDE=	ecm
USE_QT=		core testlib \
		buildtools:build qmake:build

CONFLICTS=	kdevelop-pg-qt-1.0*

.include <bsd.port.mk>
