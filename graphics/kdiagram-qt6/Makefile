PORTNAME=	kdiagram
DISTVERSION=	3.0.1
CATEGORIES=	graphics kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${DISTVERSION}/
PKGNAMESUFFIX=	-qt6
DIST_SUBDIR=	KDE/${PORTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Library to create business diagrams
WWW=		https://projects.kde.org/kdiagram

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.GPL.txt

USES=		cmake compiler:c++11-lang kde:6 qt:6 tar:xz
USE_KDE=	ecm:build
USE_QT=		base svg tools:build

PLIST_SUB=	SHLIB_SHVER="${PORTVERSION:R:R}" \
		SHLIB_VER="${PORTVERSION}"

.include <bsd.port.mk>
