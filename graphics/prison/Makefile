# Created by: fluffy@
# $FreeBSD$

PORTNAME=	prison
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTNAME}/${PORTVERSION}/src

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	A barcode library for KDE


LIB_DEPENDS=	dmtx.0:${PORTSDIR}/graphics/libdmtx \
		qrencode.3:${PORTSDIR}/graphics/libqrencode

USE_QT4=	corelib gui qmake_build moc_build rcc_build uic_build
USES=		cmake
USE_LDCONFIG=	yes

.include <bsd.port.mk>
