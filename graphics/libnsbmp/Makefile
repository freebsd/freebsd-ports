# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	libnsbmp
PORTVERSION=	0.1.5
DISTVERSIONSUFFIX=	-src
CATEGORIES=	graphics
MASTER_SITES=	http://download.netsurf-browser.org/libs/releases/

MAINTAINER=	neel@neelc.org
COMMENT=	NetSurf BMP decoder

LICENSE=	MIT

BUILD_DEPENDS=	netsurf-buildsystem>=1.5:devel/netsurf-buildsystem

USES=		gmake
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAKE_ENV=	COMPONENT_TYPE="lib-shared"

PLIST_SUB=	VERSION=${PORTVERSION}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libnsbmp.so

.include <bsd.port.mk>
