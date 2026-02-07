PORTNAME=	kchmviewer
DISTVERSIONPREFIX=	RELEASE_
DISTVERSION=	8_0-9
DISTVERSIONSUFFIX=	-g869ecdf
CATEGORIES=	deskutils kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE viewer for CHM files
WWW=		https://www.kchmviewer.net/

LIB_DEPENDS=	libchm.so:misc/chmlib \
		libzip.so:archivers/libzip

USES=		compiler:c++11-lang desktop-file-utils dos2unix gl \
		qmake:outsource qt:5 xorg
USE_GL=		gl
USE_QT=		core dbus declarative gui location network printsupport \
		webchannel webengine widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	gyunaev
GH_TAGNAME=	869ecdf6861dbc75db1a37de5844d3e40c2b267b

DOS2UNIX_GLOB=	*.cpp *.h *.pro *.ui

.include <bsd.port.mk>
