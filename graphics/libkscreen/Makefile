# Created by: alonso@
# $FreeBSD$

PORTNAME=	libkscreen
PORTVERSION=	1.0.5
PORTREVISION=	5
CATEGORIES=	graphics kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}/src

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE screen management library

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2018-12-31

LIB_DEPENDS=	libqjson.so:devel/qjson@qt4 \
		libxcb.so:x11/libxcb \
		libxcb-image.so:x11/xcb-util-image \
		libxcb-render-util.so:x11/xcb-util-renderutil

USES=		cmake kde:4 pkgconfig qt:4 tar:xz
USE_KDE=	kdelibs automoc4
USE_QT=		corelib dbus gui script \
		moc_build qmake_build rcc_build uic_build
USE_LDCONFIG=	yes

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

pre-configure:
	${REINPLACE_CMD} -e 's,$${LIB_INSTALL_DIR}/pkgconfig,libdata/pkgconfig,' \
		${WRKSRC}/src/CMakeLists.txt

.include <bsd.port.mk>
