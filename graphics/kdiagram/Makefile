# $FreeBSD$

PORTNAME=	kdiagram
PORTVERSION=	2.6.0
CATEGORIES=	graphics kde
MASTER_SITES=   KDE/stable/${PORTNAME}/${PORTVERSION}/src
DIST_SUBDIR=    KDE/${PORTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Library to create business diagrams

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.GPL.txt

USES=		cmake:outsource kde:5 tar:xz
USE_KDE=	ecm
USE_QT5=	core gui linguisttools printsupport sql svg widgets \
		buildtools_build qmake_build

PLIST_SUB=	SHLIB_VER="${PORTVERSION}" \
		SHLIB_SHVER="${PORTVERSION:R:R}"

.include <bsd.port.mk>
