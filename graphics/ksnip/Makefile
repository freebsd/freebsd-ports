# $FreeBSD$

PORTNAME=	ksnip
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.0
CATEGORIES=	graphics kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Screenshot and annotation tool

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libkColorPicker.so:graphics/kcolorpicker \
		libkImageAnnotator.so:graphics/kimageannotator

USES=		cmake compiler:c++11-lang kde:5 qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	ksnip
USE_KDE=	ecm_build
USE_QT=		concurrent core dbus gui network printsupport svg testlib \
		widgets x11extras xml \
		buildtools_build linguisttools_build qmake_build
USE_XORG=	xcb

.include <bsd.port.mk>
