# Created by: fluffy@
# $FreeBSD$

PORTNAME=	prison
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	graphics kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Barcode library for KDE

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libdmtx.so:graphics/libdmtx \
		libqrencode.so:graphics/libqrencode

USES=		cmake:outsource tar:xz
USE_QT4=	corelib gui qmake_build moc_build rcc_build uic_build

USE_LDCONFIG=	yes

.include <bsd.port.mk>
