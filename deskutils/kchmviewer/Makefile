# Created by: Markus Brueffer <markus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kchmviewer
PORTVERSION=	7.7
PORTREVISION=	4
CATEGORIES=	deskutils kde
MASTER_SITES=	SF

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE viewer for CHM files

LIB_DEPENDS=	libchm.so:misc/chmlib \
		libzip.so:archivers/libzip

USES=		compiler:c++11-lang dos2unix qmake:outsource qt:5 xorg
USE_QT=		core dbus gui network printsupport webkit widgets xml \
		buildtools_build qmake_build
USE_XORG=	x11

DOS2UNIX_GLOB=	*.cpp *.h *.pro *.ui

.include <bsd.port.mk>
