# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	blobby
PORTVERSION=	1.0
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Blobby%20Volley%202%20%28Linux%29/${PORTVERSION}
DISTNAME=	blobby2-linux-${PORTVERSION}

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Official continuation of the famous Blobby Volley 1.x game

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libphysfs.so:devel/physfs
BUILD_DEPENDS=	zip:archivers/zip \
		${LOCALBASE}/include/boost/crc.hpp:devel/boost-libs

BROKEN_powerpc64=	fails to build: cc1plus: unrecognized command line option "-std=c++11"
NOT_FOR_ARCHS=		aarch64
NOT_FOR_ARCHS_REASON=	fails to compile: I can't tell what endian-ness to use for your architecture

USES=		cmake dos2unix localbase:ldflags pkgconfig
DOS2UNIX_REGEX=	.*\.(c|h|cpp)
CMAKE_ARGS=	-DDATADIR:PATH="${DATADIR}"
WRKSRC=		${WRKDIR}/blobby-${PORTVERSION}
USE_SDL=	sdl2
USE_GL=		gl

PORTDOCS=	AUTHORS ChangeLog README TODO

DESKTOP_ENTRIES="Blobby Volley" \
		"" \
		"${DATADIR}/Icon.bmp" \
		"${PORTNAME}" \
		"Game;ArcadeGame;" \
		""

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_DATA} ${WRKSRC}/data/Icon.bmp ${STAGEDIR}${DATADIR}/

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
