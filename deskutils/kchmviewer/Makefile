PORTNAME=	kchmviewer
DISTVERSIONPREFIX=	RELEASE_
DISTVERSION=	8_0
CATEGORIES=	deskutils kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE viewer for CHM files

LIB_DEPENDS=	libchm.so:misc/chmlib \
		libzip.so:archivers/libzip

USES=		compiler:c++11-lang dos2unix qmake:outsource qt:5 xorg
USE_QT=		core dbus gui network printsupport webkit widgets xml \
		buildtools_build qmake_build
USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	gyunaev

DOS2UNIX_GLOB=	*.cpp *.h *.pro *.ui

.include <bsd.port.mk>
