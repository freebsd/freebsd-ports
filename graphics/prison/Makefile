# Created by: fluffy@
# $FreeBSD$

PORTNAME=	prison
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	graphics kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}/src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Barcode library for KDE

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libdmtx.so:graphics/libdmtx \
		libqrencode.so:graphics/libqrencode

USE_QT4=	corelib gui qmake_build moc_build rcc_build uic_build
USES=		cmake
USE_LDCONFIG=	yes

.include <bsd.port.mk>
