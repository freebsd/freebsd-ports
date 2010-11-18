# New ports collection makefile for: blobby
# Date created:	01 Apr 2008
# Whom:		Ganael Laplanche <ganael.laplanche@martymac.org>
#
# $FreeBSD$
#

PORTNAME=	blobby
PORTVERSION=	0.9b
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Blobby%20Volley%202%20%28Linux%29/Beta%200.9b
DISTNAME=	blobby2-linux-${PORTVERSION}

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Official continuation of the famous Blobby Volley 1.x game

LIB_DEPENDS=	physfs.1:${PORTSDIR}/devel/physfs \
		drm:${PORTSDIR}/graphics/libdrm
BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip \
		${LOCALBASE}/include/boost/crc.hpp:${PORTSDIR}/devel/boost-libs

LICENSE=	GPLv2

USE_XORG=	ice x11 xext xxf86vm xdamage xfixes xau xdmcp xrandr xrender
USE_SDL=	sdl
USE_GL=		glu
USE_CMAKE=	yes
CMAKE_ARGS+=	-DDATADIR:PATH="${DATADIR}"
WRKSRC=		${WRKDIR}/blobby-beta-0.9b

PORTDOCS=	AUTHORS ChangeLog INSTALL NEWS README TODO

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
