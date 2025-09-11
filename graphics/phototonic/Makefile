PORTNAME=	phototonic
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.95
CATEGORIES=	graphics

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Image viewer and organizer
WWW=		https://github.com/luebking/phototonic

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexiv2.so:graphics/exiv2

USES=		desktop-file-utils gl qmake qt:6
USE_GITHUB=	yes
GH_ACCOUNT=	luebking
USE_GL=		opengl
USE_QT=		base

post-patch:
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/phototonic.pro

.include <bsd.port.mk>
