# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	blobby
PORTVERSION=	1.0r3
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Blobby%20Volley%202%20%28Linux%29/1.0RC3/
DISTNAME=	blobby2-linux-1.0rc3

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Official continuation of the famous Blobby Volley 1.x game

LICENSE=	GPLv2

LIB_DEPENDS=	libphysfs.so:${PORTSDIR}/devel/physfs \
		libdrm.so:${PORTSDIR}/graphics/libdrm
BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip \
		${LOCALBASE}/include/boost/crc.hpp:${PORTSDIR}/devel/boost-libs

USE_XORG=	ice x11 xext xxf86vm xdamage xfixes xau xdmcp xrandr xrender
USE_SDL=	sdl
USE_GL=		glu
USES=		cmake
CMAKE_ARGS+=	-DDATADIR:PATH="${DATADIR}"
WRKSRC=		${WRKDIR}/blobby-1.0rc3

USE_DOS2UNIX=	yes
DOS2UNIX_REGEX=	.*\.(c|h|cpp)

PORTDOCS=	AUTHORS ChangeLog INSTALL NEWS README TODO

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR}  ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc}  ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
