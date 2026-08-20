PORTNAME=	linuxapi
PORTVERSION=	g20260820
CATEGORIES=	devel

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Linux userspace headers compatibility shim

TEST_DEPENDS=	cmake:devel/cmake-core

USE_GITHUB=	yes
GH_ACCOUNT=	freebsd
GH_TAGNAME=	f17d394249bc85165a871522af464b54cc2eec27

NO_BUILD=	yes
NO_ARCH=	yes

TEST_TARGET=	test

.if exists(/usr/include/dev/ntsync/ntsync.h)
PLIST_SUB+=	NTSYNC=
.else
PLIST_SUB+=	NTSYNC="@comment "
.endif

# Remove after updating CMake to >= 4.2.0
post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/cmake/linuxapi
	${RLN} ${STAGEDIR}${PREFIX}/share/cmake/linuxapi-config.cmake \
		${STAGEDIR}${PREFIX}/lib/cmake/linuxapi/linuxapi-config.cmake

.include <bsd.port.mk>
