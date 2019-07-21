# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	libnspsl
PORTVERSION=	0.1.5
CATEGORIES=	dns
MASTER_SITES=	https://download.netsurf-browser.org/libs/releases/
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	neel@neelc.org
COMMENT=	NetSurf public suffix list handling

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	netsurf-buildsystem>=1.5:devel/netsurf-buildsystem

USES=		gmake
USE_LDCONFIG=	yes
MAKE_ENV+=	COMPONENT_TYPE="lib-shared"
PLIST_SUB+=	VERSION=${PORTVERSION}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libnspsl.so*

.include <bsd.port.mk>
