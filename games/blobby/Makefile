# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	blobby
PORTVERSION=	1.0r3
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Blobby%20Volley%202%20%28Linux%29/1.0RC3/
DISTNAME=	blobby2-linux-1.0rc3

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Official continuation of the famous Blobby Volley 1.x game

LICENSE=	GPLv2

LIB_DEPENDS=	libphysfs.so:devel/physfs \
		libdrm.so:graphics/libdrm
BUILD_DEPENDS=	zip:archivers/zip \
		${LOCALBASE}/include/boost/crc.hpp:devel/boost-libs

USE_XORG=	ice x11 xext xxf86vm xdamage xfixes xau xdmcp xrandr xrender
USE_SDL=	sdl
USE_GL=		glu

USES=		dos2unix cmake
DOS2UNIX_REGEX=	.*\.(c|h|cpp)
CMAKE_ARGS+=	-DDATADIR:PATH="${DATADIR}"
WRKSRC=		${WRKDIR}/blobby-1.0rc3

PORTDOCS=	AUTHORS ChangeLog INSTALL NEWS README TODO

post-install:
	@${MKDIR}  ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
