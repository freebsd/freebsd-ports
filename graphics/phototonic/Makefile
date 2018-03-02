# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	phototonic
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0
CATEGORIES=	graphics

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Image viewer and organizer

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexiv2.so:graphics/exiv2

USES=		desktop-file-utils gettext qmake
USE_GITHUB=	yes
GH_ACCOUNT=	oferkv
USE_GL=		gl
USE_QT5=	core gui imageformats svg widgets buildtools_build

post-patch:
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/phototonic.pro

.include <bsd.port.mk>
