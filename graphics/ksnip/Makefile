PORTNAME=	ksnip
DISTVERSIONPREFIX=	v
DISTVERSION=	1.11.0.g20260518
PORTREVISION=	1
CATEGORIES=	graphics kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Screenshot and annotation tool
WWW=		https://github.com/ksnip/ksnip

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libkColorPicker-Qt6.so:graphics/kcolorpicker \
		libkImageAnnotator-Qt6.so:graphics/kimageannotator

USES=		cmake compiler:c++17-lang desktop-file-utils kde:6 qt:6 xorg
USE_GITHUB=	yes
USE_KDE=	ecm:build
USE_QT=		base svg tools:build
USE_XORG=	x11 xcb

GH_TAGNAME=	7db6c85325c9e74d878aee23dd0ed366d6592254

CMAKE_ON=	BUILD_WITH_QT6

PORTSCOUT=	limit:^[0-9]

post-patch:
	${REINPLACE_CMD} '/^Exec=/s,/usr/bin/,,' \
		${WRKSRC}/desktop/org.ksnip.ksnip.desktop

.include <bsd.port.mk>
