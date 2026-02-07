PORTNAME=	kdevelop-pg-qt
DISTVERSION=	2.4.0
CATEGORIES=	devel kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${DISTVERSION}/src
DIST_SUBDIR=	KDE/kdevelop

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Parser-generator from KDevplatform
WWW=		https://techbase.kde.org/Development/KDevelop-PG-Qt_Introduction

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/LICENSES/LGPL-2.0-or-later.txt

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:textproc/flex

USES=		bison cmake compiler:c++17-lang kde:6 qt:6 tar:xz
USE_KDE=	ecm:build
USE_QT=		base	

.include <bsd.port.mk>
