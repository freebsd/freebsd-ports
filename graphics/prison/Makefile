# New ports collection makefile for:	prison
# Date created:			Tue  9 Aug 2011, 00:42:14
# Whom:				fluffy@
#
# $FreeBSD$

PORTNAME=	prison
PORTVERSION=	1.0
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTNAME}/${PORTVERSION}/src

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	A barcode library for KDE


LIB_DEPENDS=	dmtx.0:${PORTSDIR}/graphics/libdmtx \
		qrencode.3:${PORTSDIR}/graphics/libqrencode

USE_QT_VER=	4
QT_COMPONENTS=	corelib gui qmake_build moc_build rcc_build uic_build
USE_CMAKE=	yes
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
