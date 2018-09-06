# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	libnsutils
PORTVERSION=	0.0.5
DISTVERSIONSUFFIX=	-src
CATEGORIES=	devel
MASTER_SITES=	http://download.netsurf-browser.org/libs/releases/

MAINTAINER=	neel@neelc.org
COMMENT=	NetSurf generalised utility library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	netsurf-buildsystem>=1.5:devel/netsurf-buildsystem

USES=		gmake
USE_LDCONFIG=	yes

MAKE_ENV=	COMPONENT_TYPE="lib-shared"

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_SUB=	VERSION=${PORTVERSION}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libnsutils.so

.include <bsd.port.mk>
