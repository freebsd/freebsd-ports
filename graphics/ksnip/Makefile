PORTNAME=	ksnip
DISTVERSIONPREFIX=	v
DISTVERSION=	1.10.1
PORTREVISION=	2
CATEGORIES=	graphics kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Screenshot and annotation tool
WWW=		https://github.com/ksnip/ksnip

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libkColorPicker-Qt5.so:graphics/kcolorpicker@qt5 \
		libkImageAnnotator-Qt5.so:graphics/kimageannotator@qt5

USES=		cmake compiler:c++11-lang desktop-file-utils kde:5 qt:5 xorg
USE_GITHUB=	yes
USE_KDE=	ecm:build
USE_QT=		concurrent core dbus gui network printsupport svg \
		widgets x11extras xml \
		buildtools:build linguisttools:build qmake:build testlib:build
USE_XORG=	x11 xcb

PORTSCOUT=	limit:^[0-9]

.include <bsd.port.mk>
