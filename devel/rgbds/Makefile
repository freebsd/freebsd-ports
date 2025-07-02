PORTNAME=	rgbds
DISTVERSION=	0.9.3
PORTREVISION=	1
CATEGORIES=	devel games
MASTER_SITES=	https://github.com/gbdev/rgbds/releases/download/v${DISTVERSION}/
DISTNAME=	${PORTNAME}-source
DIST_SUBDIR=	${PORTNAME}/${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Free assembler/linker for the Game Boy and Game Boy Color
WWW=		https://rgbds.gbdev.io/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpng16.so:graphics/png
TEST_DEPENDS=	bash>0:shells/bash \
		git>0:devel/git \
		xxd>0:sysutils/xxd

USES=		bison cmake:testing pkgconfig shebangfix
SHEBANG_FILES=	contrib/view_palettes.sh src/bison.sh test/*.sh test/*/*.sh

CMAKE_OFF=	USE_NONFREE_TESTS

WRKSRC=		${WRKDIR}/rgbds

.include <bsd.port.mk>
