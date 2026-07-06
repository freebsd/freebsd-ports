PORTNAME=	uchmviewer
PORTVERSION=	8.6
DISTVERSIONPREFIX=	v
CATEGORIES=	deskutils

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Qt based viewer for CHM and EPUB files
WWW=		https://github.com/eBookProjects/uChmViewer

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libchm.so:misc/chmlib \
		libzip.so:archivers/libzip

USES=		cmake desktop-file-utils gettext qt:6
USE_QT=		5compat base webengine

USE_GITHUB=	yes
GH_ACCOUNT=	eBookProjects
GH_PROJECT=	uChmViewer

CMAKE_ON=	USE_DBUS \
		USE_WEBENGINE

post-patch:
	${REINPLACE_CMD} '/set(APP_QT_MIN_VERSION/s,5,6,' \
		${WRKSRC}/CMakeLists.txt
	${REINPLACE_CMD} 's,/usr/bin,${LOCALBASE}/bin,' \
		${WRKSRC}/src/config.cpp

.include <bsd.port.mk>
