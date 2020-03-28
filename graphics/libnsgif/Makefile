# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	libnsgif
PORTVERSION=	0.2.1
CATEGORIES=	graphics
MASTER_SITES=	http://download.netsurf-browser.org/libs/releases/
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	NetSurf GIF Decoder

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	netsurf-buildsystem>=1.5:devel/netsurf-buildsystem

USES=		gmake
USE_LDCONFIG=	yes
MAKE_ENV=	COMPONENT_TYPE="lib-shared"
PLIST_SUB=	VERSION=${PORTVERSION}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libnsgif.so

.include <bsd.port.mk>
