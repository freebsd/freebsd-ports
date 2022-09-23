PORTNAME=	ksnip
DISTVERSIONPREFIX=	v
DISTVERSION=	1.10.0
PORTREVISION=	1
CATEGORIES=	graphics kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Screenshot and annotation tool
WWW=		https://github.com/ksnip/ksnip

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libkColorPicker.so:graphics/kcolorpicker \
		libkImageAnnotator.so:graphics/kimageannotator

USES=		cmake compiler:c++11-lang desktop-file-utils kde:5 qt:5 xorg
USE_GITHUB=	yes
USE_KDE=	ecm:build
USE_QT=		concurrent core dbus gui network printsupport svg testlib \
		widgets x11extras xml \
		buildtools:build linguisttools:build qmake:build
USE_XORG=	x11 xcb

PORTSCOUT=	limit:^[0-9]

.include <bsd.port.mk>
