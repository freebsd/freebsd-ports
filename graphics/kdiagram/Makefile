# $FreeBSD$

PORTNAME=	kdiagram
DISTVERSION=	2.6.2
CATEGORIES=	graphics kde
MASTER_SITES=   KDE/stable/${PORTNAME}/${DISTVERSION}/
DIST_SUBDIR=    KDE/${PORTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Library to create business diagrams

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.GPL.txt

USES=		cmake compiler:c++11-lang kde:5 qt:5 tar:xz
USE_KDE=	ecm
USE_QT=		core gui linguisttools printsupport sql svg widgets \
		buildtools_build qmake_build

PLIST_SUB=	SHLIB_VER="${PORTVERSION}" \
		SHLIB_SHVER="${PORTVERSION:R:R}"

.include <bsd.port.mk>
