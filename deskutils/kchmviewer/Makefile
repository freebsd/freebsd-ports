PORTNAME=	kchmviewer
DISTVERSIONPREFIX=	RELEASE_
DISTVERSION=	8_0
PORTREVISION=	3
CATEGORIES=	deskutils kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE viewer for CHM files
WWW=		https://www.kchmviewer.net/

LIB_DEPENDS=	libchm.so:misc/chmlib \
		libzip.so:archivers/libzip

USES=		compiler:c++11-lang desktop-file-utils dos2unix gl \
		qmake:outsource qt:5 xorg
USE_GL=		gl
USE_QT=		core dbus gui network printsupport webkit widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	gyunaev

DOS2UNIX_GLOB=	*.cpp *.h *.pro *.ui

.include <bsd.port.mk>
