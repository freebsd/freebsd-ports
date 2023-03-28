PORTNAME=	rgbds
DISTVERSION=	0.6.1
PORTREVISION=	2
CATEGORIES=	devel games
MASTER_SITES=	https://github.com/gbdev/rgbds/releases/download/v${DISTVERSION}/

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Free assembler/linker for the Game Boy and Game Boy Color
WWW=		https://rgbds.gbdev.io/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpng.so:graphics/png

USES=		bison compiler:c11 dos2unix pkgconfig
MAKE_ARGS=	Q= # verbose builds
WRKSRC=		${WRKDIR}/rgbds

do-configure:
# yank _POSIX_C_SOURCE because it breaks the build, see also:
# https://github.com/gbdev/rgbds/issues/1091
# https://github.com/gbdev/rgbds/issues/1111
	${REINPLACE_CMD} 's,-D_POSIX_C_SOURCE=200809L,,' ${WRKSRC}/Makefile

.include <bsd.port.mk>
