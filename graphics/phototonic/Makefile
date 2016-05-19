# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	phototonic
PORTVERSION=	1.7.20
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Image viewer and organizer

LICENSE=	GPLv3

LIB_DEPENDS=	libexiv2.so:graphics/exiv2

USE_GITHUB=	yes
GH_ACCOUNT=	oferkv

USES=	desktop-file-utils gettext qmake
USE_QT5=	buildtools_build imageformats svg widgets

post-patch:
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/phototonic.pro

.include <bsd.port.mk>
