# Created by: Markus Brueffer <markus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kchmviewer
PORTVERSION=	7.7
CATEGORIES=	deskutils kde
MASTER_SITES=	SF

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE viewer for CHM files

LIB_DEPENDS=	libchm.so:misc/chmlib \
		libzip.so:archivers/libzip

USES=		dos2unix qmake:outsource 
USE_QT5=	core dbus gui network printsupport webkit widgets xml \
		buildtools_build qmake_build
USE_XORG=	x11

.include <bsd.port.mk>
