# $FreeBSD$

PORTNAME=	rgbds
DISTVERSION=	0.5.0-rc2
CATEGORIES=	devel games
MASTER_SITES=	https://github.com/gbdev/rgbds/releases/download/v${DISTVERSION}/

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Free assembler/linker for the Game Boy and Game Boy Color

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpng.so:graphics/png

USES=		bison compiler:c11 dos2unix pkgconfig
WRKSRC=		${WRKDIR}/rgbds

.include <bsd.port.mk>
